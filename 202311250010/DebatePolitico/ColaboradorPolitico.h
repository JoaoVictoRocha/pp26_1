#ifndef COLABORADORPOLITICO_H
#define COLABORADORPOLITICO_H

#include <string>
#include <vector>
#include "IObservador.h"
#include "Microfone.h"

class ColaboradorPolitico {
protected:
    std::string nome;
    std::string partido;
    bool inquiridor;
    Microfone microfone;
    std::vector<IObservador*> observadores;

    void notificarEleitores(const std::string& mensagem);
    void iniciarFala(const std::string& tipo);

public:
    ColaboradorPolitico(const std::string& nome, const std::string& partido);
    virtual ~ColaboradorPolitico() = default;

    std::string getNome() const;
    std::string getPartido() const;

    void cadastrarEleitor(IObservador* obs);
    void removerEleitor(IObservador* obs);
};

#endif