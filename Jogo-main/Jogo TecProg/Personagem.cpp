#include "Personagem.h"
#include "Jogo.h"

Personagem::Personagem() : Entidade()
{
}

Personagem::~Personagem()
{
}

void Personagem::setVelocidade(sf::Vector2f velocidade)
{
	Velocidade = velocidade;
}

sf::Vector2f Personagem::getVelocidade()
{
	return Velocidade;
}

bool Personagem::colidindoParedeEsquerda()
{
	if (this->getPosicao().x <= 0.f)
		return true;
	return false;
}

bool Personagem::colidindoParedeDireita()
{
	if (this->getPosicao().x >= 4000 - this->getDimensoes().x)
		return true;
	return false;
}
