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
	
	void setLimiteXEsq(float limesq);
	void setLimiteXDir(float limdir);
	void colidir(Personagem* personagem);
	void inicializa();
	//void setFaseAtual(Fase* faseatual);
	void atualiza(float deltaTempo);
	//void atiraProjetil();
	void salvar();
};

