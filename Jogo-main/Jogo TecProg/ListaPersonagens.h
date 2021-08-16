#pragma once
#include "Lista.h"
#include "Personagem.h"

class ListaPersonagens
{
private:
    Lista <Personagem> listaPersonagens;

public:
    ListaPersonagens();
    ~ListaPersonagens();

    Personagem* getAtual();
    void inclua(Personagem* ppersonagem);
    int tamanho();
    void limpar();
    void limparTudo();
    void proximo();
    void inicio();

    Personagem* operator()(int indice);
};

