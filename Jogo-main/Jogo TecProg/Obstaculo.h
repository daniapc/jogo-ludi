#pragma once
#include "Entidade.h"

class Obstaculo : public Entidade
{
private:
	sf::FloatRect Hitbox;

public:
	Obstaculo();
	~Obstaculo();

	sf::FloatRect getHitbox();
};

