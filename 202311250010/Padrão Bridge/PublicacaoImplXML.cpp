#include "PublicacaoImplXML.h"
#include "Publicacao.h"
#include "Livro.h"   // Precisa incluir as filhas para o cast funcionar
#include "Revista.h"
#include <iostream>

void PublicacaoImplXML::getDados(Publicacao *tipo) {
    std::cout << "[Arquivo XML] Gerando XML..." << std::endl;
    tipo->getAutor(0);
    tipo->getTitulo();

    // Tentando converter para um livro para pegar o ISBN
    if (Livro* meuLivro = dynamic_cast<Livro*>(tipo)) {
        // Se entrou aqui é porque era um livro
        meuLivro->getISBN();
    } 
    // Tentando converter para uma revista para pegar o Artigo
    else if (Revista* minhaRevista = dynamic_cast<Revista*>(tipo)) {
        // Se entrou aqui é porque era uma revista
        minhaRevista->getArtigo();
    }
}