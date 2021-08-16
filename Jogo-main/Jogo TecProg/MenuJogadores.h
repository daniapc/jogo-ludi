#pragma once
#include "Menu.h"

class Jogo;

namespace Menus
{
	class MenuJogadores : public Menu
	{
	private:

		int LimiteBaixo, LimiteCima;

	public:
		MenuJogadores(Jogo* jg);
		~MenuJogadores();

		void LoopMenu(char tecla);
		void Inicializa();
	};
}



