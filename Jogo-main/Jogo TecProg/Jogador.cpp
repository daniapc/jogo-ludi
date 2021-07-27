#include "Jogador.h"

Jogador::Jogador():
	Personagem()
{

}

Jogador::~Jogador()
{
}

void Jogador::movimenta()
{
	if (sf::Keyboard::isKeyPressed(Direita))
		Corpo.move(0.1, 0.f);
	if (sf::Keyboard::isKeyPressed(Esquerda))
		Corpo.move(-0.1, 0.f);
	if (sf::Keyboard::isKeyPressed(Cima))
		Corpo.move(0.f, -0.1);
	if (sf::Keyboard::isKeyPressed(Baixo))
		Corpo.move(0.f, 0.1);
}

void Jogador::setTeclas(sf::Keyboard::Key direita, sf::Keyboard::Key esquerda, sf::Keyboard::Key baixo, sf::Keyboard::Key cima)
{
	Direita = direita;
	Esquerda = esquerda;
	Baixo = baixo;
	Cima = cima;
}



