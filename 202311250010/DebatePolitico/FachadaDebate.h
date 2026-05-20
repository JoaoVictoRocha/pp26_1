#ifndef FACHADADEBATE_H
#define FACHADADEBATE_H

#include "ConfiguraTempo.h"
#include "MediarDebate.h"
#include "GerenciaPolitico.h"
#include "LogSistem.h"
#include "Inquiridor.h"
#include "Inquirido.h"

class FachadaDebate {
private:
    static FachadaDebate* instance;
    ConfiguraTempo config;
    MediarDebate mediador;
    GerenciaPolitico gerencia; 
    int numeroRodada;

    FachadaDebate() = default; // Construtor privado (Singleton)

public:
    static FachadaDebate* getInstance();
    
    void configuracaoTempo(int perg, int resp, int rep, int trep);
    
    // Métodos repassados para a Gerência
    void adicionarCandidato(std::string nome, std::string partido);
    void vincularEleitor(std::string nome, Eleitor* eleitor);
    
    void prepararDebate();
    bool debateFinalizado();
    void realizarProximaRodada();
};

#endif