#pragma once
#include "stdafx.h"
#include "Entidade.h"
class Personagem : public Entidade   
{
protected:
	sf::Vector2f Velocidade;

public:
	Personagem();
	~Personagem();

	virtual void movimenta() = 0;
	void setVelocidade(sf::Vector2f velocidade);
	sf::Vector2f getVelocidade();
};

