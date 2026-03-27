#include <iostream>
#include "Livro.h"
#include "Revista.h"
#include "PublicacaoImplBD.h"
#include "PublicacaoImplXML.h"

int main() {
    std::cout << "--- Testando Livro com BD ---" << std::endl;
    Implementador* bd = new PublicacaoImplBD();
    Livro* meuLivro = new Livro(bd);
    
    meuLivro->obterDados(); 

    std::cout << "\n--- Testando Revista com XML ---" << std::endl;
    Implementador* xml = new PublicacaoImplXML();
    Revista* minhaRevista = new Revista(xml);
    
    minhaRevista->obterDados();

    // Limpeza de memória
    delete meuLivro;
    delete bd;
    delete minhaRevista;
    delete xml;

    return 0;
}