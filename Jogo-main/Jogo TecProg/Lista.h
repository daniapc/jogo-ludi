#pragma once
#include "stdafx.h"

template <class TIPO>
class Lista
{
public:
    template <class TIPO>
    class Elemento
    {
    private:
        TIPO* pTipo;
        Elemento <TIPO> *pProx, * pAnte;
    public:
        Elemento() { pProx = NULL; pTipo = NULL; pAnte = NULL; }
        ~Elemento() { pTipo = NULL; pProx = NULL; }

        void setTipo(TIPO* ptipo) { pTipo = ptipo; }
        TIPO* getTipo() { return pTipo; }

        void setAnte(Elemento* p) { pAnte = p; }
        Elemento <TIPO>* getAnte() { return pAnte; }

        void setProx(Elemento* p) { pProx = p; }
        Elemento <TIPO>* getProx() { return pProx; }
    };

private:

    Elemento <TIPO>* pPrimeiro;
    Elemento <TIPO>* pUltimo;
    Elemento <TIPO>* pAtual;

public:
    Lista();
    ~Lista();

    void incluaTipo(TIPO* ptipo);
    TIPO* getAtual();
    void proximo();
    void anterior();
    void inicio();
    int tamanho();
    void limparTudo();
    void remove(TIPO* ptipo);
    void pop(TIPO* ptipo);
};

template<class TIPO>
inline Lista<TIPO>::Lista()
{
    pPrimeiro = NULL;
    pUltimo = NULL;
}

template<class TIPO>
inline Lista<TIPO>::~Lista()
{
    Elemento <TIPO>* pAux = NULL;

    pAux = pPrimeiro;

    while (pAux != NULL)
    {
        pPrimeiro = pPrimeiro->getProx();
        delete pAux;
        pAux = NULL;
        pAux = pPrimeiro;
    }
    pAux = NULL;
    pPrimeiro = NULL;
    pUltimo = NULL;
    pAtual = NULL;
}

template<class TIPO>
inline void Lista<TIPO>::incluaTipo(TIPO* ptipo)
{
    Elemento <TIPO>* pAux = NULL;

    pAux = new Elemento<TIPO>();
    pAux->setTipo(ptipo);

    if (pPrimeiro == NULL)
    {
        pPrimeiro = pAux;
        pUltimo = pAux;
    }
    else
    {
        pUltimo->setProx(pAux);
        pAux->setAnte(pUltimo);
        pUltimo = pAux;
    }
}

template<class TIPO>
inline TIPO* Lista<TIPO>::getAtual()
{
    if (pAtual == NULL)
        return NULL;
    else
        return pAtual->getTipo();
}

template<class TIPO>
inline void Lista<TIPO>::proximo()
{
    if (pAtual != NULL)
        pAtual = pAtual->getProx();
    else
        cout << "Elemento indevido acessado" << endl;
}

template<class TIPO>
inline void Lista<TIPO>::anterior()
{
    if (pAtual != NULL)
        pAtual = pAtual->getAnte();
    else
        cout << "Elemento indevido acessado" << endl;
}

template<class TIPO>
inline void Lista<TIPO>::inicio()
{
    pAtual = pPrimeiro;
}

template<class TIPO>
inline int Lista<TIPO>::tamanho()
{
    Elemento <TIPO>* pAux = NULL;
    int tamanho = 0;

    pAux = pPrimeiro;

    while (pAux != NULL)
    {
        tamanho++;
        pAux = pAux->getProx();
    }
    
    return tamanho;
}

template<class TIPO>
inline void Lista<TIPO>::limparTudo()
{
    Elemento <TIPO>* pAux = NULL;

    pAux = pPrimeiro;

    while (pAux != NULL && pAux->getTipo() != NULL)
    {
        pPrimeiro = pPrimeiro->getProx();
        delete pAux;
        pAux = NULL;
        pAux = pPrimeiro;
    }
    pAux = NULL;
    pPrimeiro = NULL;
    pUltimo = NULL;
    pAtual = NULL;
}

template<class TIPO>
inline void Lista<TIPO>::remove(TIPO* ptipo)
{
    if (ptipo == NULL)
    {
        cout << "Tipo nulo." << endl;
        exit(1);
    }

    Elemento <TIPO>* pAux = NULL;
    TIPO* pE = NULL;

    pAux = pPrimeiro;

    while (pAux != NULL && pAux->getTipo() != ptipo)
        pAux = pAux->getProx();

    if (pAux == NULL)
    {
        cout << "pAux nulo." << endl;
        exit(1);
    }

    pE = pAux->getTipo();

    if (pAux->getAnte() != NULL)
        pAux->getAnte()->setProx(pAux->getProx());
    else
    {
        pPrimeiro = pAux->getProx();
        pPrimeiro->setAnte(NULL);
    }
    if (pAux->getProx() != NULL)
        pAux->getProx()->setAnte(pAux->getAnte());
    else
    {
        pUltimo = pAux->getAnte();
        pUltimo->setProx(NULL);
    }
    delete pE;
    delete pAux;
}

template<class TIPO>
inline void Lista<TIPO>::pop(TIPO* ptipo)
{
    Elemento <TIPO>* pAux = NULL;
    TIPO* pE = NULL;

    pAux = pPrimeiro;

    while (pAux != NULL && pAux->getTipo() != ptipo)
        pAux = pAux->getProx();

    if (pAux->getAnte() != NULL)
        pAux->getAnte()->setProx(pAux->getProx());
    else
    {
        pPrimeiro = pAux->getProx();
        pPrimeiro->setAnte(NULL);
    }
    if (pAux->getProx() != NULL)
        pAux->getProx()->setAnte(pAux->getAnte());
    else
    {
        pUltimo = pAux->getAnte();
        pUltimo->setProx(NULL);
    }

    delete pAux;
}

