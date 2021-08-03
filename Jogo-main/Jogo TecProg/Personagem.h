#pragma once
#include "stdafx.h"
#include "Entidade.h"

class Personagem : public Entidade   
{
protected:
	float Velocidade;
	sf::FloatRect Hitbox;
	sf::Vector2f Movimento;
	bool podePular;
	float alturaPulo;

public:
	Personagem();
	~Personagem();

	virtual void inicializa() = 0;

	void setMovimentoX(float movimentox);
	void setMovimentoY(float movimentoy);
	void setVelocidade(float velocidade);
	void setPodePular(bool podepular);
	void setAlturaPulo(float alturapulo);
	float getVelocidade();
	sf::FloatRect getHitbox();

	void movimenta(sf::Vector2f movimento);
};

