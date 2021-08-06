#pragma once
#include "Menu.h"

class Jogo;

class MenuPause : public Menu
{
private:

public:
	MenuPause(unsigned int comprimento, unsigned int altura, int tamanho, Jogo* jg);
	~MenuPause();

	void LoopMenu(sf::Event* evento);
};

