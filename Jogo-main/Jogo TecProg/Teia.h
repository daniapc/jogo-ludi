#pragma once
#include "Obstaculo.h"
class Teia : public Obstaculo
{
private:
	float Lentidao;

public:
	Teia();
	~Teia();

	void colidir(Personagem* personagem);
	void salvar();
};

