#include "Jogador.h"

Jogador::Jogador():Personagem()
{
}

Jogador::~Jogador()
{
}

void Jogador::atualiza()
{
	if (sf::Keyboard::isKeyPressed(Direita))
	{
		Velocidade.x = 0.1f;
		Velocidade.y = 0.f;
		if (!colidindoParedeDireita())
			this->movimenta();
	}
	if (sf::Keyboard::isKeyPressed(Esquerda))
	{
		Velocidade.x = -0.1f;
		Velocidade.y = 0.f;
		if (!colidindoParedeEsquerda())
			this->movimenta();
	}
	if (sf::Keyboard::isKeyPressed(Cima))
	{
		Velocidade.x = 0.f;
		Velocidade.y = -0.1f;
		this->movimenta();
	}
		
	if (sf::Keyboard::isKeyPressed(Baixo))
	{
		Velocidade.x = 0.f;
		Velocidade.y = 0.1f;
		this->movimenta();
	}
}

void Jogador::movimenta()
{
	Corpo.move(sf::Vector2f(Velocidade.x, Velocidade.y));
}

void Jogador::setTeclas(sf::Keyboard::Key direita, sf::Keyboard::Key esquerda, sf::Keyboard::Key baixo, sf::Keyboard::Key cima)
{
	Direita = direita;
	Esquerda = esquerda;
	Baixo = baixo;
	Cima = cima;
}



