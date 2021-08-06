#pragma once
#include "Inimigo.h"
#include "Fase.h"

class Chefao : public Inimigo
{
private:
	Fase* faseAtual;

public:
	Chefao();
	~Chefao();

	void colidir(Personagem* personagem);
	void inicializa();
	void setFaseAtual(Fase* faseatual);
	void atualiza(float deltaTempo);
	void atiraProjetil(float altura);
	void atiraProjetil2();
	void atiraProjeteis();
};

