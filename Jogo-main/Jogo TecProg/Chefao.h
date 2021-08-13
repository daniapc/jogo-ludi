#pragma once
#include "Inimigo.h"
#include "Atirador.h"
//#include "Fase.h"

class Fase;

class Chefao : public Inimigo, public Atirador
{
private:
	//Fase* faseAtual;

public:
	Chefao();
	~Chefao();

	void colidir(Personagem* personagem);
	void inicializa();
	//void setFaseAtual(Fase* faseatual);
	void atualiza(float deltaTempo);
	//void atiraProjetil(float altura);
	//void atiraProjetil2();
	void atiraProjeteis();
	void salvar();
};

