#include "GerenciadorFisica.h"

GerenciadorFisica::GerenciadorFisica():
	listaEntidades(NULL),
	listaPersonagens(NULL)
{
}

GerenciadorFisica::~GerenciadorFisica()
{
}

void GerenciadorFisica::setListaEntidades(ListaEntidades* listaentidades)
{
	listaEntidades = listaentidades;
}

void GerenciadorFisica::setListaPersonagens(ListaPersonagens* listapersonagens)
{
	listaPersonagens = listapersonagens;
}

/*
void GerenciadorFisica::setFazendeira(Jogador* fazendeira)
{
	pFazendeira = fazendeira;
}
*/

void GerenciadorFisica::incluaEntidade(Entidade* entidade)
{
	listaEntidades->inclua(entidade);
}


void GerenciadorFisica::checaColisoes()
{

	for (unsigned int i = 0; i < listaPersonagens->tamanho(); i++)
	{
		for (unsigned int j = 0; j < listaEntidades->tamanho(); j++)
		{
			checaColisao((*listaPersonagens)[i], (*listaEntidades)[j]);
		}
	}
	//cout << listaEntidades->tamanho() << endl;
}

void GerenciadorFisica::checaColisao(Personagem* personagem, Entidade* entidade)
{
	float deltaX = entidade->getPosicao().x - personagem->getPosicao().x;
	float deltaY = entidade->getPosicao().y - personagem->getPosicao().y;
	float intersecaoX = abs(deltaX) - (personagem->getDimensoes().x / 2 + entidade->getDimensoes().x / 2);
	float intersecaoY = abs(deltaY) - (personagem->getDimensoes().y / 2 + entidade->getDimensoes().y / 2);

	if (intersecaoX < 0.f && intersecaoY < 0.f)
	{
		entidade->colidir(personagem);
	}
}

void GerenciadorFisica::checaColisaoParede(Personagem* personagem)
{
	if (personagem->getPosicao().x <= personagem->getDimensoes().x / 2)
		personagem->movimenta(sf::Vector2f(personagem->getDimensoes().x / 2 - personagem->getPosicao().x, 0.f));
	if (personagem->getPosicao().x >= COMPRIMENTO_CENARIO - personagem->getDimensoes().x / 2)
		personagem->movimenta(sf::Vector2f(COMPRIMENTO_CENARIO - (personagem->getPosicao().x + personagem->getDimensoes().x / 2), 0.f));
}
	