#ifndef IMEDIADORBUILDER_H
#define IMEDIADORBUILDER_H

#include "MediarDebate.h"
#include "ColaboradorPolitico.h"
#include "ConfiguraTempo.h"

class IMediadorBuilder {
public:
    virtual ~IMediadorBuilder() = default;
    virtual void resetar() = 0;
    virtual void buildConfiguracao(const ConfiguraTempo& config) = 0;
    virtual void buildInquiridor(ColaboradorPolitico* inq) = 0;
    virtual void buildInquirido(ColaboradorPolitico* resp) = 0;
    virtual MediarDebate* getMediadorPronto() = 0;
};

#endif