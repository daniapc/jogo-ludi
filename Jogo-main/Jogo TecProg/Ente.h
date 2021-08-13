#pragma once
#include "stdafx.h"

class Ente
{
protected:
	sf::RenderWindow* Janela;

public:
	Ente();
	virtual ~Ente();

	void setJanela(sf::RenderWindow* janela);
	sf::RenderWindow* getJanela();
};

