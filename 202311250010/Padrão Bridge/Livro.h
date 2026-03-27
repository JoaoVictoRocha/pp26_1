#ifndef LIVRO_H
#define LIVRO_H

#include "Publicacao.h"
#include <string>

class Livro : public Publicacao {
public:
    Livro(Implementador* implementador);

    void getISBN();
    void getTitulo() override;
    void getAutor();
    void getAutor(int id) override;
};

#endif 