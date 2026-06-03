#ifndef FACHADADEBATE_H
#define FACHADADEBATE_H

#include <string>
#include <memory>
#include "ConfiguraTempo.h"
#include "GerenciaPolitico.h"
#include "Eleitor.h"
#include "LogSistem.h"
#include "MediadorBase.h"

class FachadaDebate {
private:
    static FachadaDebate* instance;
    ConfiguraTempo config;
    GerenciaPolitico gerencia;
    MediadorBase* mediador;
    int numeroRodada;

    FachadaDebate() = default;

public:
    static FachadaDebate* getInstance();
    void configuracaoTempo(int perg, int resp, int rep, int trep);
    void adicionarCandidato(std::string nome, std::string partido);
    void vincularEleitor(std::string nome, Eleitor* eleitor);
    void prepararDebate();
    bool debateFinalizado();
    void realizarProximaRodada();
};

#endif