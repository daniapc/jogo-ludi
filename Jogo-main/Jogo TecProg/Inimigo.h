#pragma once
#include "Personagem.h"
#include "Jogador.h"

class Inimigo : public Personagem
{
protected:

public:
	Inimigo();
	virtual ~Inimigo();

	virtual void atualiza(float deltaTempo) = 0;
	virtual void colidir(Personagem* personagem) = 0;
	virtual void salvar() = 0;
};

