#include "Publicacao.h"
#include "Implementador.h"

Publicacao::Publicacao(Implementador* implementador) : imp(implementador) {}

void Publicacao::obterDados() {
    if (imp) {
        imp->getDados(this); // Passando a própria instância
    }
}