#include "Inquiridor.h"
#include <iostream>

Inquiridor::Inquiridor(const std::string& nome, const std::string& partido) : ColaboradorPolitico(nome, partido) {}

void Inquiridor::perguntar(int tempo) {
    iniciarFala("Pergunta");
    std::cout << nome << " perguntando por " << tempo << " segundos" << std::endl;
    microfone.desliga();
}

void Inquiridor::replica(int tempo) {
    iniciarFala("Replica");
    std::cout << nome << " replicando por " << tempo << " segundos" << std::endl;
    microfone.desliga();
}