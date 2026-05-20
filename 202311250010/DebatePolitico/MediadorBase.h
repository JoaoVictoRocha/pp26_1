#ifndef MEDIADORBASE_H
#define MEDIADORBASE_H

#include "ConfiguraTempo.h"

class MediadorBase {
public:
    // CORREÇÃO: Assinatura reflete o que o Mediator faz na UML
    virtual void debate(ConfiguraTempo& config) = 0; 
    virtual ~MediadorBase() = default;
};

#endif