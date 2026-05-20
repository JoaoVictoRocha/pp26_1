#ifndef INQUIRIDO_H
#define INQUIRIDO_H
#include "ColaboradorPolitico.h"

class Inquirido : public ColaboradorPolitico {
public:
    Inquirido(const std::string& nome, const std::string& partido);
    void responder(int tempo);
    void treplica(int tempo);
};
#endif