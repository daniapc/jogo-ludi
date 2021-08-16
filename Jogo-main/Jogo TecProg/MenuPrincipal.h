#pragma once
#include "Menu.h"

class Jogo;

namespace Menus
{
	class MenuPrincipal : public Menu
	{
	private:

	public:
		MenuPrincipal(Jogo* jg);
		~MenuPrincipal();

		void LoopMenu(char tecla);
		void InicializaPlanoFundo();
	};
}

