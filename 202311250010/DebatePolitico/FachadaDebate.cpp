#include "FachadaDebate.h"
#include "IFabricaPolitico.h"
#include "FabricaInquiridor.h"
#include "FabricaInquirido.h"
#include "IMediadorBuilder.h"
#include "MediadorBuilderConcreto.h"
#include <iostream>

FachadaDebate* FachadaDebate::instance = nullptr;

FachadaDebate* FachadaDebate::getInstance() {
    if(instance == nullptr) { instance = new FachadaDebate(); }
    return instance;
}

void FachadaDebate::configuracaoTempo(int perg, int resp, int rep, int trep) {
    config = ConfiguraTempo(perg, resp, rep, trep);
}

void FachadaDebate::adicionarCandidato(std::string nome, std::string partido) {
    gerencia.adicionarCandidato(nome, partido);
}

void FachadaDebate::vincularEleitor(std::string nome, Eleitor* eleitor) {
    gerencia.vincularEleitor(nome, eleitor);
}

void FachadaDebate::prepararDebate() {
    gerencia.prepararUrnaDeSorteio();
    numeroRodada = 1;
    LogSistem::getInstance()->registrar("--- PREPARANDO DEBATE ---");
}

bool FachadaDebate::debateFinalizado() {
    return gerencia.urnaVazia();
}

void FachadaDebate::realizarProximaRodada() {
    if (debateFinalizado()) { return; }

    DadosCandidato dInquiridor = gerencia.sortearInquiridorPendente();
    
    std::cout << "\n[SISTEMA]: O inquiridor sorteado foi o(a) candidato(a) " << dInquiridor.nome << "!\n";
    std::cout << "Quem ele(a) vai escolher para responder? (Digite o nome do inquirido): ";
    std::string nomeEscolhido;
    std::cin >> nomeEscolhido;
    
    DadosCandidato dInquirido = gerencia.obterCandidatoPorNome(nomeEscolhido);
    while (dInquirido.nome == "" || dInquirido.nome == dInquiridor.nome) {
        std::cout << "[ERRO] Nome invalido, nao cadastrado ou o candidato tentou escolher a si mesmo.\n";
        std::cout << "Digite um nome valido para responder: ";
        std::cin >> nomeEscolhido;
        dInquirido = gerencia.obterCandidatoPorNome(nomeEscolhido);
    }

    // Factory
    std::unique_ptr<IFabricaPolitico> fabInq = std::make_unique<FabricaInquiridor>();
    ColaboradorPolitico* inquiridorRodada = fabInq->criarPolitico(dInquiridor.nome, dInquiridor.partido);
    for (auto* e : dInquiridor.eleitoresAssociados) { inquiridorRodada->cadastrarEleitor(e); }

    std::unique_ptr<IFabricaPolitico> fabResp = std::make_unique<FabricaInquirido>();
    ColaboradorPolitico* inquiridoRodada = fabResp->criarPolitico(dInquirido.nome, dInquirido.partido);
    for (auto* e : dInquirido.eleitoresAssociados) { inquiridoRodada->cadastrarEleitor(e); }

    std::cout << "\n============================================\n";
    std::cout << ">>> RODADA " << numeroRodada << " | CONFRONTO DEFINIDO <<<\n";
    std::cout << "PERGUNTA: " << inquiridorRodada->getNome() << " (" << inquiridorRodada->getPartido() << ")\n";
    std::cout << "RESPONDE: " << inquiridoRodada->getNome() << " (" << inquiridoRodada->getPartido() << ")\n";
    std::cout << "============================================\n";

    // Builder
    std::unique_ptr<IMediadorBuilder> builder = std::make_unique<MediadorBuilderConcreto>();
    builder->resetar();
    builder->buildConfiguracao(config);
    builder->buildInquiridor(inquiridorRodada);
    builder->buildInquirido(inquiridoRodada);

    mediador = builder->getMediadorPronto();
    mediador->debate(config);

    delete inquiridorRodada;
    delete inquiridoRodada;
    delete mediador;

    numeroRodada++; 
}