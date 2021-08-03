#pragma once
#include "Entidade.h"
class Projetil : public Entidade
{
private:
	sf::Vector2f Velocidade;
	sf::Vector2f Movimento;

public:
	Projetil();
	~Projetil();

	void atualiza(float deltaTempo);
	void movimenta(sf::Vector2f movimento);
	void setVelocidade(sf::Vector2f velocidade);
};

