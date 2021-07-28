#pragma once
#include "stdafx.h"
#include "Entidade.h"

class Jogo;

class Personagem : public Entidade   
{
protected:
	sf::Vector2f Velocidade;

public:
	Personagem();
	~Personagem();

	void setVelocidade(sf::Vector2f velocidade);
	sf::Vector2f getVelocidade();

	bool colidindoParedeEsquerda();
	bool colidindoParedeDireita();
	virtual void movimenta() = 0;
};

