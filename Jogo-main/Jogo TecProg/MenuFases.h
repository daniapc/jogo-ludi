#pragma once
#include "Menu.h"

class Jogo;

namespace Menus
{
	class MenuFases : public Menu
	{
	private:

	public:
		MenuFases(Jogo* jg);
		~MenuFases();

		void LoopMenu(char tecla);
	};
}



