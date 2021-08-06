#pragma once
#include "Menu.h"

class Jogo;

class MenuFases : public Menu
{
private:

public:
	MenuFases(unsigned int comprimento, unsigned int altura, int tamanho, Jogo* jg);
	~MenuFases();

	void LoopMenu(sf::Event* evento);
};

