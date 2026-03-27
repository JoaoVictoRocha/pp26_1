#include "PublicacaoImplBD.h"
#include "Publicacao.h" // Necessário para acessar getTitulo e getAutor
#include "Livro.h"   // Precisa incluir as filhas para o cast funcionar
#include "Revista.h"
#include <iostream>

void PublicacaoImplBD::getDados(Publicacao *tipo) {
    std::cout << "[Banco de Dados] Procurando..." << std::endl;
    tipo->getAutor(0);
    tipo->getTitulo();

    if (Livro* meuLivro = dynamic_cast<Livro*>(tipo)) {
        // Se entrou aqui, é porque era um livro! Agora podemos chamar getISBN()
        meuLivro->getISBN();
    } 
    else if (Revista* minhaRevista = dynamic_cast<Revista*>(tipo)) {
        // Se entrou aqui, era uma revista! Podemos chamar getArtigo()
        minhaRevista->getArtigo();
    }
}