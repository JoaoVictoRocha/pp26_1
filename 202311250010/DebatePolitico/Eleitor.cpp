#include "Eleitor.h"

Eleitor::Eleitor(const std::string& nome) {
    this->nome = nome;
}

void Eleitor::atualizar(const std::string& mensagem) {
    std::cout << "[NOTIFICACAO CELULAR - " << nome << "]: " << mensagem << std::endl;
}