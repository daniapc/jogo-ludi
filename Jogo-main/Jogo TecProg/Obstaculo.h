#pragma once
#include "Entidade.h"

class Obstaculo : public Entidade
{
private:

public:
	Obstaculo();
	~Obstaculo();

	sf::FloatRect getHitbox();
};

