#pragma once
#include "Obstaculo.h"
class Espinho : public Obstaculo
{
private:

public:
	Espinho();
	~Espinho();

	void colidir(Personagem* personagem);
	void salvar();
};

