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
            pAux->setAnte(pUltimo);
            pUltimo = pAux;
        }
}

void ListaEntidades::atualiza(float deltaTempo)
{
    Elemento* pAux = NULL;

    pAux = pPrimeiro;

    while (pAux != NULL)
    {
        Entidade* pE = NULL;

        
        pE = pAux->getEntidade();
        pE->atualiza(deltaTempo);
        pAux = pAux->getProx();
        
        /*
        pE = pAux->getEntidade();
        if (pE->getDesalocavel())
        {
            Elemento* pAux2 = pAux;
            pAux = pAux->getProx();
            if (pAux2->getAnte() != NULL)
                pAux2->getAnte()->setProx(pAux2->getProx());
            if (pAux2->getProx() != NULL)
                pAux2->getProx()->setAnte(pAux2->getAnte());
            delete pE;
            delete pAux2;
        }
        else
        {
            pE->atualiza(deltaTempo);
            pAux = pAux->getProx();
        }
        */
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

void ListaEntidades::salvar()
{
    Elemento* pAux = NULL;

    pAux = pPrimeiro;

    while (pAux != NULL)
    {
        Entidade* pE = NULL;

        pE = pAux->getEntidade();

        pE->salvar();

        pAux = pAux->getProx();
    }
}
