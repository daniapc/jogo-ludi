#pragma once
#include "Menu.h"

class Jogo;

class MenuPrincipal : public Menu
{
private:

public:
	MenuPrincipal(unsigned int comprimento, unsigned int altura, int tamanho, Jogo* jg);
	~MenuPrincipal();

	void LoopMenu(sf::Event* evento);
};

