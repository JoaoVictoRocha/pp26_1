#ifndef CONFIGURATEMPO_H
#define CONFIGURATEMPO_H

class ConfiguraTempo {
private:
    int tempoPergunta;
    int tempoResposta;
    int tempoReplica;
    int tempoTreplica;

public:
    ConfiguraTempo(int pergunta = 30, int resposta = 60, int replica = 30, int treplica = 30);

    int getPergunta() const;
    int getResposta() const;
    int getReplica() const;
    int getTreplica() const;
};

#endif