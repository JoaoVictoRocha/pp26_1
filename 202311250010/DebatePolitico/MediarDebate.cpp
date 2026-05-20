#include "MediarDebate.h"

void MediarDebate::setInquiridor(Inquiridor* inq) { inquiridor = inq; }
void MediarDebate::setInquirido(Inquirido* inq) { inquirido = inq; }

void MediarDebate::debate(ConfiguraTempo& config) {
    inquiridor->perguntar(config.getPergunta());
    inquirido->responder(config.getResposta());
    inquiridor->replica(config.getReplica());
    inquirido->treplica(config.getTreplica());
}