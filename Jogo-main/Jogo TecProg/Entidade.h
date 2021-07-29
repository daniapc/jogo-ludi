#pragma once
#include "stdafx.h"

class Entidade
{
protected:
	sf::Vector2f DimensoesCorpo;
	sf::RectangleShape Corpo;
	sf::Vector2f Posicao;
	sf::Texture Textura;

	sf::RenderWindow* Janela;
	
public:
	Entidade();
	virtual ~Entidade();
	
	sf::RectangleShape& getCorpo();
	void setDimensoes(sf::Vector2f dimensoes);
	sf::Vector2f getDimensoes();
	void setPosicao(sf::Vector2f posicao);
	sf::Vector2f getPosicao();

	void setOrigem();
	void setTextura(const string textura);
	void setJanela(sf::RenderWindow* janela);

	void desenhar();
};

