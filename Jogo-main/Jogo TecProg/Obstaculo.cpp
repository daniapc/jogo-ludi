#include "Obstaculo.h"

Obstaculo::Obstaculo()
{
}

Obstaculo::~Obstaculo()
{
}

sf::FloatRect Obstaculo::getHitbox()
{
	return Corpo.getGlobalBounds();
}
