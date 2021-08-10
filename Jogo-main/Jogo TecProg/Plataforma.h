#pragma once
#include "Obstaculo.h"

class Plataforma : public Obstaculo
{
private:

public:
	Plataforma();
	~Plataforma();

	void colidir(Personagem* personagem);
	void salvar();
};

