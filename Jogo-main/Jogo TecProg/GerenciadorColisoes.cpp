#include "GerenciadorColisoes.h"

GerenciadorColisoes::GerenciadorColisoes():
	plistaEntidades(NULL),
	plistaPersonagens(NULL)
{
}

GerenciadorColisoes::~GerenciadorColisoes()
{
}

void GerenciadorColisoes::setListaEntidades(ListaEntidades* listaentidades)
{
	plistaEntidades = listaentidades;
}

void GerenciadorColisoes::setListaPersonagens(ListaPersonagens* listapersonagens)
{
	plistaPersonagens = listapersonagens;
}

void GerenciadorColisoes::checaColisoes()
{
	for (unsigned int i = 0; i < plistaPersonagens->tamanho(); i++)
	{
		for (unsigned int j = 0; j < plistaEntidades->tamanho(); j++)
		{
			checaColisao((*plistaPersonagens)(i), (*plistaEntidades)[j]);
		}
	}
}

void GerenciadorColisoes::checaColisao(Personagem* personagem, Entidade* entidade)
{
	float deltaX = entidade->getPosicaoX()  - personagem->getPosicaoX() ;
	float deltaY = entidade->getPosicaoY()  - personagem->getPosicaoY() ;
	float intersecaoX = abs(deltaX) - (personagem->getDimensoesX()  / 2 + entidade->getDimensoesX()  / 2);
	float intersecaoY = abs(deltaY) - (personagem->getDimensoesY()  / 2 + entidade->getDimensoesY()  / 2);

	if (intersecaoX < 0.f && intersecaoY < 0.f)
	{
		entidade->colidir(personagem);
	}
}
