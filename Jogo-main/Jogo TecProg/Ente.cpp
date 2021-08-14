#include "Ente.h"
#include "GerenciadorGrafico.h"

Ente::Ente()
	//Janela(NULL)
{
}

Ente::~Ente()
{
	//Janela = NULL;
}

void Ente::setGerenciadorGrafico(GerenciadorGrafico* pgerenciadorgrafico)
{
	pGerenciadorGrafico = pgerenciadorgrafico;
}

