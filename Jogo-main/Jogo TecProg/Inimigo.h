#pragma once
#include "Personagem.h"
#include "Jogador.h"

class Inimigo : public Personagem
{
protected:

public:
	Inimigo();
	virtual ~Inimigo();

	virtual void inicializa() = 0;
	virtual void atualiza();
	virtual void colidir();
};

