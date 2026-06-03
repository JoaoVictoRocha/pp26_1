#include "FabricaInquirido.h"
#include "Inquirido.h"

ColaboradorPolitico* FabricaInquirido::criarPolitico(const std::string& nome, const std::string& partido) {
    return new Inquirido(nome, partido);
}