#pragma once
#include "Inimigo.h"

class Fantasma : public Inimigo
{
private:
	float limiteXEsq, limiteXDir, limiteYCima, limiteYBaixo;
	bool cima;

public:
	Fantasma();
	~Fantasma();

	void setLimitesX(float limesq, float limdir);

	void setLimiteYCima(float limiteycima);
	void setLimiteYBaixo(float limiteybaixo);

	void colidir(Personagem* personagem);
	void atualiza(float deltaTempo);
	void salvar();
};

