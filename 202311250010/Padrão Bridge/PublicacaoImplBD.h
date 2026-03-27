#ifndef PUBLICACAO_IMPL_BD_H
#define PUBLICACAO_IMPL_BD_H

#include "Implementador.h"

class PublicacaoImplBD : public Implementador {
public:
    void getDados(Publicacao *tipo) override;
};

#endif 