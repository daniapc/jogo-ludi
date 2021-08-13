#pragma once
//#include "Entidade.h"
#include "stdafx.h"

class Fase;
class Personagem;

class Atirador// :
	//public Entidade 
{
protected:
	Fase* faseAtual;
	string Textura;
	
public:
	Atirador();
	~Atirador();

	void setFaseAtual(Fase* faseatual);
	void setTexturaProjetil(string textura);

	//void atiraProjetilHorizontal(Personagem* personagem);
	void atiraProjetilHorizontal(Personagem* personagem, float altura);
	void atiraProjetilDirecionado(Personagem* personagem, float dimensao);
};

