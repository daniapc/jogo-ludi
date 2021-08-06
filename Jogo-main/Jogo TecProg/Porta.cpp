#include "Porta.h"
#include "Jogo.h"

Porta::Porta()
{
	this->setPosicao(sf::Vector2f(COMPRIMENTO_CENARIO - 150.f , ALTURA_RESOLUCAO - (ALTURA_PLATAFORMA + 50.f)));
	this->setDimensoes(sf::Vector2f(50.f, 100.f));
	this->setOrigem();
	this->setTextura("");
}

Porta::~Porta()
{
}


void Porta::setJogo(Jogo* jg)
{
	jogo = jg;
}

void Porta::colidir(Personagem* personagem)
{
	if (personagem->getAmigavel())
		jogo->setEstado(5);
}
