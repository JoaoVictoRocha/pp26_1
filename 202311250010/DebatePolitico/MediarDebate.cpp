#include "MediarDebate.h"

MediarDebate::MediarDebate() : inquiridor(nullptr), inquirido(nullptr) {}

void MediarDebate::setInquiridor(ColaboradorPolitico* inq) {
    inquiridor = dynamic_cast<Inquiridor*>(inq);
}

void MediarDebate::setInquirido(ColaboradorPolitico* inqui) {
    inquirido = dynamic_cast<Inquirido*>(inqui);
}

void MediarDebate::debate(ConfiguraTempo& config) {
    if (!inquiridor || !inquirido) return;

    inquiridor->perguntar(config.getPergunta());
    inquirido->responder(config.getResposta());
    inquiridor->replica(config.getReplica());
    inquirido->treplica(config.getTreplica());
}