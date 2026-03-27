#ifndef REVISTA_H
#define REVISTA_H

#include "Publicacao.h"
#include <string>

class Revista : public Publicacao {
public:
    Revista(Implementador* implementador);

    void getArtigo();
    void getTitulo() override;
    void getAutor(int id) override;
};

#endif  