#include "Teia.h"

Teia::Teia()
{
}

Teia::~Teia()
{
}

void Teia::colidir(Personagem* personagem)
{
	if (personagem->getAmigavel())
	{
		personagem->setVelocidade(100.f);
		personagem->setPodePular(false);
	}
}

void Teia::setLentidao(float lentidao)
{
	Lentidao = lentidao;
}

float Teia::getLentidao()
{
	return Lentidao;
}
