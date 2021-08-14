#pragma once
#include "Inimigo.h"
#include "stdafx.h"
#include "Atirador.h"

class Fase;

class Passaro : public Inimigo, public Atirador
{
private:
	float limiteXEsq, limiteXDir;

public:
	Passaro();
	~Passaro();

	void setLimites(float limesq, float limdir);

	void colidir(Personagem* personagem);
	void atualiza(float deltaTempo);
	void salvar();
};

