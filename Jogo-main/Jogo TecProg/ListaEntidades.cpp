#include "ListaEntidades.h"

ListaEntidades::ListaEntidades()
{
    pPrimeiro = NULL;
    pUltimo = NULL;
}

ListaEntidades::~ListaEntidades()
{
    Elemento* pAux = NULL;

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
}

void ListaEntidades::inclua(Entidade* pentidade)
   {
        Elemento* pAux = NULL;

        pAux = new Elemento();
        pAux->setEntidade(pentidade);

        if (pPrimeiro == NULL)
        {
            pPrimeiro = pAux;
            pUltimo = pAux;
        }
        else
        {
            pUltimo->setProx(pAux);
            pUltimo = pAux;
    }
}

void ListaEntidades::desenhar() const
{
    Elemento *pAux = NULL;

    pAux = pPrimeiro;

    while (pAux != NULL)
    {
        Entidade* pE = NULL;

        pE = pAux->getEntidade();
        pE->desenhar();
        pAux = pAux->getProx();
    }
}
