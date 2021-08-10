#pragma once
#include "Entidade.h"

class ListaEntidades
{
public:
    class Elemento
    {
    private:
        Entidade* pEntidade;
        Elemento* pProx, *pAnte;
    public:
        Elemento() { pProx = NULL; pEntidade = NULL; pAnte = NULL; }
        ~Elemento()  { pEntidade = NULL; pProx = NULL; }

        void setEntidade(Entidade* pentidade) { pEntidade = pentidade; }
        Entidade* getEntidade() { return pEntidade; }

        void setAnte(Elemento* p) { pAnte = p; }
        Elemento* getAnte() { return pAnte; }

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
    void atualiza(float deltaTempo);
    void desenhar() const;
    void salvar();
};


