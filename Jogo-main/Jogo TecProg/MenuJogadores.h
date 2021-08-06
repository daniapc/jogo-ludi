#pragma once
#include "Menu.h"

class Jogo;

class MenuJogadores : public Menu
{
private:

public:
	MenuJogadores(unsigned int comprimento, unsigned int altura, int tamanho, Jogo* jg);
	~MenuJogadores();

	void LoopMenu(sf::Event* evento);
};

