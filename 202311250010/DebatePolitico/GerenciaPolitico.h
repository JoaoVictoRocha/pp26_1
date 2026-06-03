#ifndef GERENCIAPOLITICO_H
#define GERENCIAPOLITICO_H

#include <vector>
#include <string>
#include "Eleitor.h"

struct DadosCandidato {
    std::string nome;
    std::string partido;
    std::vector<Eleitor*> eleitoresAssociados;
};

class GerenciaPolitico {
private:
    std::vector<DadosCandidato> poolCandidatos;
    std::vector<DadosCandidato> inquiridoresPendentes;

public:
    void adicionarCandidato(std::string nome, std::string partido);
    void vincularEleitor(std::string nome, Eleitor* eleitor);
    void prepararUrnaDeSorteio();
    bool urnaVazia();
    DadosCandidato sortearInquiridorPendente();
    DadosCandidato obterCandidatoPorNome(const std::string& nome);
};

#endif