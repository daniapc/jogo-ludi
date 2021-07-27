#include "Personagem.h"

Personagem::Personagem():
	Entidade()
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
