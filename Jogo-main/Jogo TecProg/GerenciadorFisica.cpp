#include "GerenciadorFisica.h"

GerenciadorFisica::GerenciadorFisica()
{
}

GerenciadorFisica::~GerenciadorFisica()
{
}

/*
void GerenciadorFisica::setListaEntidades(ListaEntidades* listaentidades)
{
	listaEntidades = listaentidades;
}
*/

void GerenciadorFisica::setFazendeira(Jogador* fazendeira)
{
	pFazendeira = fazendeira;
}

/*
void GerenciadorFisica::incluaPlataforma(Plataforma* plataforma)
{
	ListaPlataformas.push_back(plataforma);
}
*/

void GerenciadorFisica::incluaPersonagem(Personagem* personagem)
{
	ListaPersonagens.push_back(personagem);
}

/*
void GerenciadorFisica::incluaProjetil(Projetil* projetil)
{
	ListaProjeteis.push_back(projetil);
}
*/

void GerenciadorFisica::incluaEntidade(Entidade* entidade)
{
	ListaEntidades.push_back(entidade);
}

void GerenciadorFisica::checaColisoes()
{
	for (unsigned int i = 0; i < ListaPersonagens.size(); i++)
	{
		for (unsigned int j = 0; j < ListaEntidades.size(); j++)
			if (ListaPersonagens[i] != NULL && ListaEntidades[j] != NULL)
				checaColisao(ListaPersonagens[i], ListaEntidades[j]);
	}

	checaColisaoParede(pFazendeira);
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
	
	if (entidade->getPosicao().x <= entidade->getDimensoes().x / 2
		|| entidade->getPosicao().x >= COMPRIMENTO_CENARIO - entidade->getDimensoes().x / 2
		|| entidade->getPosicao().y <= 0
		|| entidade->getPosicao().y >= ALTURA_RESOLUCAO)
		entidade->setDesalocavel(true);

}

void GerenciadorFisica::checaColisaoParede(Personagem* personagem)
{
	if (personagem->getPosicao().x <= personagem->getDimensoes().x / 2)
		personagem->movimenta(sf::Vector2f(personagem->getDimensoes().x / 2 - personagem->getPosicao().x, 0.f));
	if (personagem->getPosicao().x >= COMPRIMENTO_CENARIO - personagem->getDimensoes().x / 2)
		personagem->movimenta(sf::Vector2f(COMPRIMENTO_CENARIO - (personagem->getPosicao().x + personagem->getDimensoes().x / 2), 0.f));
}
	