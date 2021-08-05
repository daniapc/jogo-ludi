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

	void colidir(Personagem* personagem);
	void inicializa();
	void atualiza(float deltaTempo);
};

