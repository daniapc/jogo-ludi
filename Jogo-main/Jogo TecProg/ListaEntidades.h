#pragma once
#include "Entidade.h"
#include "Lista.h"

class ListaEntidades
{
private:
    Lista <Entidade> listaEntidades;

public:
    ListaEntidades();
    ~ListaEntidades();
   
    Entidade* getAtual();
    void inclua(Entidade* pentidade); 
    void atualiza(float deltaTempo);
    void limpar();
    void limparTudo();
    void desenhar();
    void salvar();
    int tamanho();
    void proximo();
    void inicio();

    void remove(Entidade* pentidade);

    Entidade* operator[](int indice);
};


