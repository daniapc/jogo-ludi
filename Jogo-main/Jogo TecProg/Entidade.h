#pragma once
#include "stdafx.h"

class Entidade
{
protected:
	sf::Vector2f DimensoesCorpo;
	sf::RectangleShape Corpo;
	sf::Vector2f Posicao;

	sf::RenderTarget* Janela;
	
public:
	Entidade();
	virtual ~Entidade();

	virtual void Inicializa(sf::Vector2f dimensoes, sf::Vector2f posicao) = 0;
	
	sf::Vector2f getDimensoes();
	sf::RectangleShape& getCorpo();
	sf::Vector2f getPosicao();

	void setJanela(sf::RenderTarget* janela);
	
};

