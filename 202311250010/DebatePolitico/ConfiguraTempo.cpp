#include "ConfiguraTempo.h"

ConfiguraTempo::ConfiguraTempo(int pergunta, int resposta, int replica, int treplica) {
    tempoPergunta = pergunta;
    tempoResposta = resposta;
    tempoReplica = replica;
    tempoTreplica = treplica;
}

int ConfiguraTempo::getPergunta() const { return tempoPergunta; }
int ConfiguraTempo::getResposta() const { return tempoResposta; }
int ConfiguraTempo::getReplica() const { return tempoReplica; }
int ConfiguraTempo::getTreplica() const { return tempoTreplica; }