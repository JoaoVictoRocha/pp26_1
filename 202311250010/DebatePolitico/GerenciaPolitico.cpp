#include "GerenciaPolitico.h"
#include <cstdlib>

void GerenciaPolitico::adicionarCandidato(std::string nome, std::string partido) {
    poolCandidatos.push_back({nome, partido, std::vector<Eleitor*>()});
}

void GerenciaPolitico::vincularEleitor(std::string nome, Eleitor* eleitor) {
    for(auto& candidato : poolCandidatos) {
        if(candidato.nome == nome) {
            candidato.eleitoresAssociados.push_back(eleitor);
            return;
        }
    }
}

void GerenciaPolitico::prepararUrnaDeSorteio() {
    inquiridoresPendentes = poolCandidatos;
}

bool GerenciaPolitico::urnaVazia() {
    return inquiridoresPendentes.empty();
}

DadosCandidato GerenciaPolitico::sortearInquiridorPendente() {
    // Sorteia, salva o dado, remove da urna de pendentes e retorna
    int index = std::rand() % inquiridoresPendentes.size();
    DadosCandidato sorteado = inquiridoresPendentes[index];
    inquiridoresPendentes.erase(inquiridoresPendentes.begin() + index);
    return sorteado;
}

DadosCandidato GerenciaPolitico::obterCandidatoPorNome(const std::string& nome) {
    for (auto& candidato : poolCandidatos) {
        if (candidato.nome == nome) {
            return candidato; 
        }
    }
    // Retorna uma ficha vazia caso o nome digitado não exista
    return {"", "", std::vector<Eleitor*>()}; 
}