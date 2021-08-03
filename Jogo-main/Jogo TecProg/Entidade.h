#pragma once
#include "stdafx.h"
#include "Ente.h"
//#include "GerenciadorGrafico.h"

class Entidade : public Ente
{
protected:
	
	sf::Vector2f DimensoesCorpo;
	sf::RectangleShape Corpo;
	sf::Vector2f Posicao;
	sf::Texture Textura;
	
	//GerenciadorGrafico gerenciadorGrafico;
	
public:
	Entidade();
	virtual ~Entidade();
	
	sf::RectangleShape& getCorpo();
	void setDimensoes(sf::Vector2f dimensoes); // Coloquei asteriscos pois seria ponteiro
	sf::Vector2f getDimensoes();
	void setPosicao(sf::Vector2f posicao);
	sf::Vector2f getPosicao();

	void setOrigem();
	void setTextura(const string textura);

	void desenhar();
};

