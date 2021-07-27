#pragma once
#include "stdafx.h"
#include "Personagem.h"

class Jogador : public Personagem
{
private:
	sf::Keyboard::Key Direita, Esquerda, Baixo, Cima;

public:
	Jogador();
	~Jogador();
	
	void movimenta();
	void setTeclas(sf::Keyboard::Key direita, sf::Keyboard::Key esquerda, sf::Keyboard::Key baixo, sf::Keyboard::Key cima);
};

