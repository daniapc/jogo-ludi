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
	
	void setLimiteXEsq(float limesq);
	void setLimiteXDir(float limdir);
	void colidir(Personagem* personagem);
	void inicializa();
	void setFaseAtual(Fase* faseatual);
	void atualiza(float deltaTempo);
	void atiraProjetil();
	void salvar();
};

