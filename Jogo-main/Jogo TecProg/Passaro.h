#pragma once
#include "Inimigo.h"
#include "stdafx.h"

class Fase;

class Passaro : public Inimigo
{
private:
	Fase* faseAtual;
	float limiteXEsq, limiteXDir;

public:
	Passaro();
	~Passaro();
	
	void colidir(Personagem* personagem);
	void inicializa();
	void setFaseAtual(Fase* faseatual);
	void atualiza(float deltaTempo);
	void atiraProjetil();
};

