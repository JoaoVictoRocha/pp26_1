#include "Inquirido.h"
#include <iostream>

Inquirido::Inquirido(const std::string& nome, const std::string& partido) : ColaboradorPolitico(nome, partido) {}

void Inquirido::responder(int tempo) {
    iniciarFala("Resposta");
    std::cout << nome << " respondendo por " << tempo << " segundos" << std::endl;
    microfone.desliga();
}

void Inquirido::treplica(int tempo) {
    iniciarFala("Treplica");
    std::cout << nome << " exercendo treplica por " << tempo << " segundos" << std::endl;
    microfone.desliga();
}