#pragma once
#include "stdafx.h"

class Fase;
class Personagem;
class Jogo;

class Atirador
{
protected:
	Fase* faseAtual;
	string ProjetilEsquerda, ProjetilDireita;
	
public:
	Atirador();
	~Atirador();

	void setFaseAtual(Fase* faseatual);

	void setTexturaProjetil(string textura1, string textura2);
	void atiraProjetilHorizontal(Personagem* personagem, float altura);
	void atiraProjetilDirecionado(Personagem* personagem, float dimensao);

	
};

