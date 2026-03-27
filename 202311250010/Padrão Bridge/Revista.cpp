#include "Revista.h"
#include <iostream>

Revista::Revista(Implementador* implementador) : Publicacao(implementador) {}

void Revista::getArtigo() {
    std::cout << "Artigo: Artigo sobre C++" << std::endl;
}

void Revista::getTitulo() {
    std::cout << "Titulo: Revista de Tecnologia" << std::endl;
}

void Revista::getAutor(int id) {
    std::cout << "Autor da Revista" << std::endl;
}