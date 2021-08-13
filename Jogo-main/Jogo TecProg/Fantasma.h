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

	void setLimiteXEsq(float limesq);
	void setLimiteXDir(float limdir);
	void setLimiteYCima(float limiteycima);
	void setLimiteYBaixo(float limiteybaixo);

	void colidir(Personagem* personagem);
	void inicializa();
	void atualiza(float deltaTempo);
	void salvar();
};

