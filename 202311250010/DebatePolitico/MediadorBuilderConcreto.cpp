#include "MediadorBuilderConcreto.h"

MediadorBuilderConcreto::MediadorBuilderConcreto() : mediador(nullptr) {
    resetar();
}

MediadorBuilderConcreto::~MediadorBuilderConcreto() {
    delete mediador;
}

void MediadorBuilderConcreto::resetar() {
    mediador = new MediarDebate();
}

void MediadorBuilderConcreto::buildConfiguracao(const ConfiguraTempo& config) {
    // Config passiva neste modelo
}

void MediadorBuilderConcreto::buildInquiridor(ColaboradorPolitico* inq) {
    if (mediador) mediador->setInquiridor(inq);
}

void MediadorBuilderConcreto::buildInquirido(ColaboradorPolitico* resp) {
    if (mediador) mediador->setInquirido(resp);
}

MediarDebate* MediadorBuilderConcreto::getMediadorPronto() {
    MediarDebate* pronto = mediador;
    mediador = nullptr; 
    return pronto;
}