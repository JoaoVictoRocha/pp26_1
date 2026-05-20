#ifndef MEDIARDEBATE_H
#define MEDIARDEBATE_H

#include "MediadorBase.h"
#include "Inquiridor.h"
#include "Inquirido.h"
#include "ConfiguraTempo.h"

// CORREÇÃO: Herança aplicada
class MediarDebate : public MediadorBase {
private:
    Inquiridor* inquiridor;
    Inquirido* inquirido;

public:
    void setInquiridor(Inquiridor* inq);
    void setInquirido(Inquirido* inq);
    void debate(ConfiguraTempo& config) override; // CORREÇÃO: Override garantido
};

#endif