#ifndef FABRICAINQUIRIDO_H
#define FABRICAINQUIRIDO_H

#include "IFabricaPolitico.h"

class FabricaInquirido : public IFabricaPolitico {
public:
    ColaboradorPolitico* criarPolitico(const std::string& nome, const std::string& partido) override;
};

#endif