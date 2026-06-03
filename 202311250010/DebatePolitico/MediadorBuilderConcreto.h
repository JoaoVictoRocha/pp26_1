#ifndef MEDIADORBUILDERCONCRETO_H
#define MEDIADORBUILDERCONCRETO_H

#include "IMediadorBuilder.h"

class MediadorBuilderConcreto : public IMediadorBuilder {
private:
    MediarDebate* mediador;

public:
    MediadorBuilderConcreto();
    ~MediadorBuilderConcreto();
    
    void resetar() override;
    void buildConfiguracao(const ConfiguraTempo& config) override;
    void buildInquiridor(ColaboradorPolitico* inq) override;
    void buildInquirido(ColaboradorPolitico* resp) override;
    MediarDebate* getMediadorPronto() override;
};

#endif