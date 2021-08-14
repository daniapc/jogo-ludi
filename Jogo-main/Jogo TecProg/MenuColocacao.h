#pragma once
#include "Menu.h"
#include "stdafx.h"
#include <sstream>

class Jogo;

class MenuColocacao : public Menu
{
private:
	bool Digitando;
	sf::String Nome;
	int Limite;
	int EstadoAnterior;

public:
	MenuColocacao(unsigned int comprimento, unsigned int altura, int tamanho, Jogo* jg);
	~MenuColocacao();

	//void setEditavel(bool editavel);

	void Recupera();
	void Inicializa();

	void setEditavel(bool Editavel);
	void setEstadoAnterior(int estadoanterior);

	void LoopMenu(char tecla);
};

