#ifndef IOBSERVADOR_H
#define IOBSERVADOR_H

#include <string>

class IObservador {
public:
    virtual void atualizar(const std::string& mensagem) = 0;
    virtual ~IObservador() = default;
};

#endif