#pragma once
#include "stdafx.h"
#include "Entidade.h"

class Personagem : public Entidade   
{
protected:
	sf::Vector2f Velocidade;
	sf::FloatRect Hitbox;

public:
	Personagem();
	~Personagem();

	void setVelocidade(sf::Vector2f velocidade);
	sf::Vector2f getVelocidade();
	sf::FloatRect getHitbox();

	bool colidindoParedeEsquerda();
	bool colidindoParedeDireita();
	virtual void movimenta() = 0;
};

