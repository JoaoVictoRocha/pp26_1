#ifndef PUBLICACAO_H
#define PUBLICACAO_H

#include <string>

// Informando que essa classe existe
class Implementador; 

class Publicacao {
protected:
    Implementador* imp;

public:
    Publicacao(Implementador* implementador);
    virtual ~Publicacao() = default;

    void obterDados();

    virtual void getTitulo() = 0;
    virtual void getAutor(int id) = 0;
};

#endif 