#ifndef FABRICAINQUIRIDOR_H
#define FABRICAINQUIRIDOR_H

#include "IFabricaPolitico.h"

class FabricaInquiridor : public IFabricaPolitico {
public:
    ColaboradorPolitico* criarPolitico(const std::string& nome, const std::string& partido) override;
};

#endif