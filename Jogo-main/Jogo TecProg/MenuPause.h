#pragma once
#include "Menu.h"

class Jogo;

class MenuPause : public Menu
{
private:
	int EstadoAtual;

public:
	MenuPause(unsigned int comprimento, unsigned int altura, int tamanho, Jogo* jg);
	~MenuPause();

	void setEstadoAtual(int estadoatual);
	int getEstadoAtual();
	void LoopMenu(sf::Event* evento);
};

