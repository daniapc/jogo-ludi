#pragma once
#include "Menu.h"

class Jogo;

namespace Menus
{
	class MenuPause : public Menu
	{
	private:
		int EstadoAtual;

	public:
		MenuPause(Jogo* jg);
		~MenuPause();

		void setEstadoAtual(int estadoatual);
		int getEstadoAtual() const;
		void LoopMenu(char tecla);

		void Inicializa();
	};
}

