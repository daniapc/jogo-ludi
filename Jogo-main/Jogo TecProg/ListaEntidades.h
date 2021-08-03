#pragma once
#include "Entidade.h"

class ListaEntidades
{
public:
    class Elemento
    {
    private:
        Entidade* pEntidade;
        Elemento* pProx;
    public:
        Elemento() { pProx = NULL; pEntidade = NULL; }
        ~Elemento()  { pEntidade = NULL; pProx = NULL; }

        void setEntidade(Entidade* pentidade) { pEntidade = pentidade; }
        Entidade* getEntidade() { return pEntidade; }

        void setProx(Elemento* p) { pProx = p; }
        Elemento* getProx() { return pProx; }
    };

private:

    Elemento* pPrimeiro;
    Elemento* pUltimo;

public:
    ListaEntidades();
    ~ListaEntidades();
   
    void inclua(Entidade* pentidade); 
    void desenhar() const;
};


