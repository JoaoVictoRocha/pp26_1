#ifndef IMPLEMENTADOR_H
#define IMPLEMENTADOR_H

// Informando que essa classe existe
class Publicacao; 

class Implementador {
public:
    virtual ~Implementador() = default;
    virtual void getDados(Publicacao *tipo) = 0; 
};

#endif 