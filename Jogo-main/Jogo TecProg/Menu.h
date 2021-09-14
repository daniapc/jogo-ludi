#pragma once
#include "Ente.h"
#include "stdafx.h" 
#include "Cenario.h"
#include "Texto.h"

class Jogo;

namespace Menus
{
	class Menu : public Ente
	{
	protected:
		int Indice, Tamanho, *Ids, TamIds;

		vector <Texto*> Textos;
		Jogo* jogo;

	public:
		Menu(Jogo* jg);
		~Menu();

		void moverCima();
		void moverBaixo();
		void desenhar();

		void InicializaPlanoFundo();
		void criaTexto(Texto* t, string mens, string cor, string font, float dim, float posx, float posy);
	};
}




