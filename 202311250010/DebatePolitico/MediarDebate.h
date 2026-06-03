#ifndef MEDIARDEBATE_H
#define MEDIARDEBATE_H

#include "MediadorBase.h"
#include "ColaboradorPolitico.h"
#include "Inquiridor.h"
#include "Inquirido.h"
#include "ConfiguraTempo.h"

class MediarDebate : public MediadorBase {
private:
    Inquiridor* inquiridor;
    Inquirido* inquirido;

public:
    MediarDebate();
    void setInquiridor(ColaboradorPolitico* inq);
    void setInquirido(ColaboradorPolitico* inq);
    void debate(ConfiguraTempo& config) override; 
};

#endif