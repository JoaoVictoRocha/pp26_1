#include "FachadaDebate.h"
#include "Eleitor.h"
#include <ctime>
#include <iostream>

int main() {
    // Garante que o sorteio seja aleatório a cada execução
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    FachadaDebate* sistema = FachadaDebate::getInstance();
    sistema->configuracaoTempo(30, 60, 30, 30);

    // Cadastrando candidatos na Fachada
    sistema->adicionarCandidato("LULA", "Partido A");
    sistema->adicionarCandidato("BOLSONARO", "Partido B");
    sistema->adicionarCandidato("CAIADO", "Partido C");
    sistema->adicionarCandidato("ZEMA", "Partido D");

    // Cadastrando e vinculando eleitores
    Eleitor e1("Lucas");
    Eleitor e2("Julia");
    Eleitor e3("Marcos");
    Eleitor e4("Fernanda");

    sistema->vincularEleitor("LULA", &e1);
    sistema->vincularEleitor("BOLSONARO", &e2);
    sistema->vincularEleitor("CAIADO", &e3);
    sistema->vincularEleitor("ZEMA", &e4);

    std::cout << "\n========== DEBATE ==========\n";
    
    // Inicia o fluxo de controle
    sistema->prepararDebate();

    while(!sistema->debateFinalizado()) {
        std::cout << "\n[Apresentador]: Iniciando proxima rodada...\n";
        sistema->realizarProximaRodada();
    }

    std::cout << "\n========== FIM DO DEBATE ==========\n";
    std::cout << "Todos os candidatos ja passaram pelo papel de inquiridor.\n";

    return 0;
}