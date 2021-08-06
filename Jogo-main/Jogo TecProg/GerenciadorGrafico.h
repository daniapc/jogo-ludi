#pragma once
#include "stdafx.h"

class GerenciadorGrafico
{
private:

	sf::RenderWindow Janela;
	sf::View View;
		
public:
	GerenciadorGrafico();
	~GerenciadorGrafico();

	sf::RenderWindow& getJanela();
	sf::View& getView();

	//void setView();
	void resetaView();

};


