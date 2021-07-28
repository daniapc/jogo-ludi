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
		if (!colidindoParedeDireita())
			Corpo.move(sf::Vector2f(Velocidade.x, 0.f));
	if (sf::Keyboard::isKeyPressed(Esquerda))
		if (!colidindoParedeEsquerda())
			Corpo.move(sf::Vector2f(-Velocidade.x, 0.f));
	if (sf::Keyboard::isKeyPressed(Cima))
		Corpo.move(sf::Vector2f(0.f, -Velocidade.y));
	if (sf::Keyboard::isKeyPressed(Baixo))
		Corpo.move(sf::Vector2f(0.f, Velocidade.y));
}

void Jogador::setTeclas(sf::Keyboard::Key direita, sf::Keyboard::Key esquerda, sf::Keyboard::Key baixo, sf::Keyboard::Key cima)
{
	Direita = direita;
	Esquerda = esquerda;
	Baixo = baixo;
	Cima = cima;
}



