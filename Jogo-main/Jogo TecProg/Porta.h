#pragma once
#include "Obstaculo.h"

class Jogo;

class Porta : public Obstaculo
{
private:
	Jogo* jogo;

public:
	Porta();
	~Porta();

	void salvar();
	void setJogo(Jogo* jg);
	void colidir(Personagem* personagem);
};

