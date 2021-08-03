#include "Personagem.h"

Personagem::Personagem() : Entidade()
{
}

Personagem::~Personagem()
{
}

void Personagem::setMovimentoX(float movimentox)
{
	Movimento.x = movimentox;
}

void Personagem::setMovimentoY(float movimentoy)
{
	Movimento.y = movimentoy;
}

void Personagem::setVelocidade(float velocidade)
{
	Velocidade = velocidade;
}

void Personagem::setPodePular(bool podepular)
{
	podePular = podepular;
}

void Personagem::setAlturaPulo(float alturapulo)
{
	alturaPulo = alturapulo;
}

float Personagem::getVelocidade()
{
	return Velocidade;
}

sf::FloatRect Personagem::getHitbox()
{
	return Corpo.getGlobalBounds();
}

void Personagem::movimenta(sf::Vector2f movimento)
{
	Corpo.move(movimento);
}
