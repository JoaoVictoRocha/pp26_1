#ifndef PUBLICACAO_IMPL_XML_H
#define PUBLICACAO_IMPL_XML_H

#include "Implementador.h"

class PublicacaoImplXML : public Implementador {
public:
    void getDados(Publicacao *tipo) override;
};

#endif 