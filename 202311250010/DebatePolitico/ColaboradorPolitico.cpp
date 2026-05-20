#include "ColaboradorPolitico.h"
#include "LogSistem.h"
#include <iostream>
#include <algorithm>

ColaboradorPolitico::ColaboradorPolitico(const std::string& nome, const std::string& partido) {
    this->nome = nome;
    this->partido = partido;
    inquiridor = false;
}

std::string ColaboradorPolitico::getNome() const { return nome; }
std::string ColaboradorPolitico::getPartido() const { return partido; }

void ColaboradorPolitico::cadastrarEleitor(IObservador* obs) {
    observadores.push_back(obs);
}

void ColaboradorPolitico::removerEleitor(IObservador* obs) {
    observadores.erase(
        std::remove(observadores.begin(), observadores.end(), obs), 
        observadores.end()
    );
}

void ColaboradorPolitico::notificarEleitores(const std::string& mensagem) {
    for(auto obs : observadores) {
        obs->atualizar(mensagem);
    }
}

void ColaboradorPolitico::iniciarFala(const std::string& tipo) {
    std::string mensagem = "Candidato " + nome + " esta exercendo: " + tipo;
    
    // Registra no Log
    LogSistem::getInstance()->registrar(mensagem);

    notificarEleitores(mensagem);
    microfone.liga();
}