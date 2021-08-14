#include "ListaPersonagens.h"

ListaPersonagens::ListaPersonagens()
{
}

ListaPersonagens::~ListaPersonagens()
{
	listaPersonagens.limparTudo();
}

Personagem* ListaPersonagens::getAtual()
{
	return listaPersonagens.getAtual();
}

void ListaPersonagens::inclua(Personagem* ppersonagem)
{
	listaPersonagens.incluaTipo(ppersonagem);
}

int ListaPersonagens::tamanho()
{
	return listaPersonagens.tamanho();
}

void ListaPersonagens::limpar()
{
	listaPersonagens.inicio();

	while (listaPersonagens.getAtual() != NULL)
	{
		Personagem* pE = NULL;

		pE = listaPersonagens.getAtual();

		listaPersonagens.proximo();
		if (pE->getDesalocavel())
		{
			listaPersonagens.pop(pE);
		}
	}
}

void ListaPersonagens::limparTudo()
{
	listaPersonagens.limparTudo();
}

void ListaPersonagens::proximo()
{
	listaPersonagens.proximo();
}

void ListaPersonagens::inicio()
{
	listaPersonagens.inicio();
}

Personagem* ListaPersonagens::operator[](int indice)
{
	listaPersonagens.inicio();

	for (int i = 0; i < indice; i++) {
		listaPersonagens.proximo();
	}

	return getAtual();
}

