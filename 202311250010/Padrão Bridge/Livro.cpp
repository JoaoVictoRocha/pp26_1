#include "Livro.h"
#include <iostream>

Livro::Livro(Implementador* implementador) : Publicacao(implementador) {}

void Livro::getISBN() {
    std::cout << "ISBN-999-99-9999-9" << std::endl;
}

void Livro::getTitulo() {
    std::cout << "Titulo: Livro de Padroes de Projeto" << std::endl;
}

void Livro::getAutor() {
    std::cout << "Autor: Katyusco" << std::endl;
}

void Livro::getAutor(int id) {
    std::cout << "Autor: Katyusco" << std::endl;
}