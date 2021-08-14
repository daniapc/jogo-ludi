#pragma once
//#include "Entidade.h"

class Fase;
class Personagem;
class Jogo;
//
class Atirador
{
protected:
	Fase* faseAtual;
	
public:
	Atirador();
	~Atirador();

	void setFaseAtual(Fase* faseatual);

	void atiraProjetilHorizontal(Personagem* personagem, float altura);
	void atiraProjetilDirecionado(Personagem* personagem, float dimensao);
};

