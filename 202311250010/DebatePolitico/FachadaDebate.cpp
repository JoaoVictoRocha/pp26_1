#include "FachadaDebate.h"
#include <iostream>

FachadaDebate* FachadaDebate::instance = nullptr;

FachadaDebate* FachadaDebate::getInstance() {
    if(instance == nullptr) { instance = new FachadaDebate(); }
    return instance;
}

void FachadaDebate::configuracaoTempo(int perg, int resp, int rep, int trep) {
    config = ConfiguraTempo(perg, resp, rep, trep);
}

// A Fachada apenas terceiriza a guarda dos dados
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

    // 1. Sorteia quem vai PERGUNTAR
    DadosCandidato dInquiridor = gerencia.sortearInquiridorPendente();
    
    // 2. Interação com o terminal para escolher quem vai RESPONDER
    std::cout << "\n[SISTEMA]: O inquiridor sorteado foi o(a) candidato(a) " << dInquiridor.nome << "!\n";
    std::cout << "Quem ele(a) vai escolher para responder? (Digite o nome do inquirido): ";
    
    std::string nomeEscolhido;
    std::cin >> nomeEscolhido;
    
    DadosCandidato dInquirido = gerencia.obterCandidatoPorNome(nomeEscolhido);

    // Validação contra auto-confronto ou erro de digitação
    while (dInquirido.nome == "" || dInquirido.nome == dInquiridor.nome) {
        std::cout << "[ERRO] Nome invalido, nao cadastrado ou o candidato tentou escolher a si mesmo.\n";
        std::cout << "Digite um nome valido para responder: ";
        std::cin >> nomeEscolhido;
        dInquirido = gerencia.obterCandidatoPorNome(nomeEscolhido);
    }

    // 3. Cria as instâncias reais dos políticos com todos os seus eleitores
    Inquiridor inquiridorRodada(dInquiridor.nome, dInquiridor.partido);
    for (auto* e : dInquiridor.eleitoresAssociados) { inquiridorRodada.cadastrarEleitor(e); }

    Inquirido inquiridoRodada(dInquirido.nome, dInquirido.partido);
    for (auto* e : dInquirido.eleitoresAssociados) { inquiridoRodada.cadastrarEleitor(e); }

    // 4. Repassa para o Mediador iniciar a rodada
    std::cout << "\n============================================\n";
    std::cout << ">>> RODADA " << numeroRodada << " | CONFRONTO DEFINIDO <<<\n";
    std::cout << "PERGUNTA: " << inquiridorRodada.getNome() << " (" << inquiridorRodada.getPartido() << ")\n";
    std::cout << "RESPONDE: " << inquiridoRodada.getNome() << " (" << inquiridoRodada.getPartido() << ")\n";
    std::cout << "============================================\n";

    mediador.setInquiridor(&inquiridorRodada);
    mediador.setInquirido(&inquiridoRodada);
    mediador.debate(config);

    numeroRodada++; 
}