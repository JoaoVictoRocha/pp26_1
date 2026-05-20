#ifndef INQUIRIDOR_H
#define INQUIRIDOR_H
#include "ColaboradorPolitico.h"

class Inquiridor : public ColaboradorPolitico {
public:
    Inquiridor(const std::string& nome, const std::string& partido);
    void perguntar(int tempo);
    void replica(int tempo);
};
#endif