#pragma once
#include "Obstaculo.h"
class Espinho : public Obstaculo
{
private:
	float CooldownDano, CooldownDanoMax;

public:
	Espinho();
	~Espinho();

	void atualiza(float deltaTempo);
	bool podeDarDano();
	void colidir(Personagem* personagem);
	void salvar();
};

