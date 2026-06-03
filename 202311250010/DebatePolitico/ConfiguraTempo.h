#ifndef CONFIGURATEMPO_H
#define CONFIGURATEMPO_H

class ConfiguraTempo {
private:
    int tempoPergunta;
    int tempoResposta;
    int tempoReplica;
    int tempoTreplica;

public:
    ConfiguraTempo() = default;
    ConfiguraTempo(int pergunta, int resposta, int replica, int treplica);
    
    int getPergunta() const;
    int getResposta() const;
    int getReplica() const;
    int getTreplica() const;
};

#endif