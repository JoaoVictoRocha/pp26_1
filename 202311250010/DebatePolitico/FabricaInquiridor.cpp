#include "FabricaInquiridor.h"
#include "Inquiridor.h"

ColaboradorPolitico* FabricaInquiridor::criarPolitico(const std::string& nome, const std::string& partido) {
    return new Inquiridor(nome, partido);
}