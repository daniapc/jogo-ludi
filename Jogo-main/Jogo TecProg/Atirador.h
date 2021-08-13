#pragma once
//#include "Entidade.h"

class Fase;
class Personagem;

class Atirador// :
	//public Entidade 
{
protected:
	Fase* faseAtual;
	
public:
	Atirador();
	~Atirador();

	void setFaseAtual(Fase* faseatual);

	void atiraProjetilHorizontal(Personagem* personagem);
	void atiraProjetilHorizontal(Personagem* personagem, float altura);
	void atiraProjetilDirecionado(Personagem* personagem, float dimensao);
};

