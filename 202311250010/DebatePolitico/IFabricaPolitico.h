#ifndef IFABRICAPOLITICO_H
#define IFABRICAPOLITICO_H

#include "ColaboradorPolitico.h"
#include <string>

class IFabricaPolitico {
public:
    virtual ~IFabricaPolitico() = default;
    virtual ColaboradorPolitico* criarPolitico(const std::string& nome, const std::string& partido) = 0;
};

#endif