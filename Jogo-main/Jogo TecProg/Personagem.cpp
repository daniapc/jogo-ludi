#include "Personagem.h"

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

sf::FloatRect Personagem::getHitbox()
{
	return Corpo.getGlobalBounds();
}

bool Personagem::colidindoParedeEsquerda()
{
	if (this->getPosicao().x <= 0.f + this->getDimensoes().x/2)
		return true;
	return false;
}

bool Personagem::colidindoParedeDireita()
{
	if (this->getPosicao().x >= 4000 - this->getDimensoes().x/2)
		return true;
	return false;
}
