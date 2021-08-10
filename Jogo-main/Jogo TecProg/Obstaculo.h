#pragma once
#include "Personagem.h"
#include "Entidade.h"

class Obstaculo : public Entidade
{
private:

public:
	Obstaculo();
	~Obstaculo();

	virtual void colidir(Personagem* personagem);
	virtual void atualiza(float deltaTempo);
	virtual void salvar();
};

