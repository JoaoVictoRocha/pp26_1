#ifndef ELEITOR_H
#define ELEITOR_H

#include "IObservador.h"
#include <iostream>

class Eleitor : public IObservador {
private:
    std::string nome;

public:
    Eleitor(const std::string& nome);
    void atualizar(const std::string& mensagem) override;
};

#endif