#pragma once
#include "Personagem.h"

class Inimigo : public Personagem
{
protected:


public:
	Inimigo();
	virtual ~Inimigo();

	virtual void movimenta() = 0;
};

