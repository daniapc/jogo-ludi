#include "Projetil.h"

Projetil::Projetil()
{
}

Projetil::~Projetil()
{
}

void Projetil::atualiza(float deltaTempo)
{
	Movimento.x += Velocidade.x;
	Movimento.y += Velocidade.y;

	this->movimenta(Movimento * deltaTempo);
}

void Projetil::movimenta(sf::Vector2f movimento)
{
	Corpo.move(movimento);
}

void Projetil::setVelocidade(sf::Vector2f velocidade)
{
	Velocidade = velocidade;
}
