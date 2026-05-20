#ifndef COLABORADORPOLITICO_H
#define COLABORADORPOLITICO_H

#include <vector>
#include <string>
#include "IObservador.h"
#include "Microfone.h"

class MediadorBase;

class ColaboradorPolitico {
protected:
    std::string nome;
    std::string partido;
    bool inquiridor;
    Microfone microfone;
    std::vector<IObservador*> observadores;
    MediadorBase* mediador;

public:
    ColaboradorPolitico(const std::string& nome, const std::string& partido);
    virtual ~ColaboradorPolitico() = default;

    std::string getNome() const;
    std::string getPartido() const;

    void cadastrarEleitor(IObservador* obs);
    void removerEleitor(IObservador* obs);
    void notificarEleitores(const std::string& mensagem);
    void iniciarFala(const std::string& tipo);
};

#endif