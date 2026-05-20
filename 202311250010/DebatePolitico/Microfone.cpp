#include "Microfone.h"

Microfone::Microfone() { microAtivo = false; }

void Microfone::liga() {
    microAtivo = true;
    std::cout << "  [MIC LIGADO]" << std::endl;
}

void Microfone::desliga() {
    microAtivo = false;
    std::cout << "  [MIC DESLIGADO]\n" << std::endl;
}

bool Microfone::ativo() const { return microAtivo; }