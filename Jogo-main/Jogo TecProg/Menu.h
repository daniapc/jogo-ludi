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
		int Indice, Tamanho, Id;

		vector <Texto*> Textos;
		Jogo* jogo;
		Cenario PlanoFundo;

	public:
		Menu(Jogo* jg);
		~Menu();

		void moverCima();
		void moverBaixo();
		void desenhar();

		void criaTexto(Texto* t, string mens, string cor, string font, float dim, float posx, float posy);
	};
}




