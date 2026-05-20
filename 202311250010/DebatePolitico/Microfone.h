#ifndef MICROFONE_H
#define MICROFONE_H

#include <iostream>

class Microfone {
private:
    bool microAtivo;

public:
    Microfone();
    void liga();
    void desliga();
    bool ativo() const;
};

#endif