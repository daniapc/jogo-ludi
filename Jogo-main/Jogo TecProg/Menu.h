#pragma once
#include "Ente.h"
#include "stdafx.h" 

class Jogo;

class Menu : public Ente
{
protected:
	int Indice, Tamanho;
	sf::Text* menu;
	sf::RectangleShape PlanoFundo;
	sf::Font Fonte;
	Jogo* jogo;

public:
	Menu(unsigned int comprimento, unsigned int altura, int tamanho, Jogo* jg);
	~Menu();

	void moverCima();
	void moverBaixo();
	void desenhar();
};


