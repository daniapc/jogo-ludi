#pragma once
#include "Inimigo.h"

class Fantasma : public Inimigo
{
private:
	float limiteXEsq, limiteXDir, limiteYCima, limiteYBaixo;
	bool direita, cima;

public:
	Fantasma();
	~Fantasma();

	void inicializa();

	void atualiza(float deltaTempo);
};

