#pragma once
#include "stdafx.h"
#include "Ente.h"
//#include "GerenciadorGrafico.h"

class Personagem;

class Entidade : public Ente
{
protected:
	sf::Vector2f DimensoesCorpo;
	sf::Vector2f Movimento;
	sf::RectangleShape Corpo;
	sf::Vector2f Posicao;
	sf::Texture Textura;
	bool Desalocavel;

	//GerenciadorGrafico gerenciadorGrafico;
	
public:
	Entidade();
	virtual ~Entidade();
	
	sf::RectangleShape& getCorpo();
	void setDimensoes(sf::Vector2f dimensoes); // Coloquei asteriscos pois seria ponteiro
	sf::Vector2f getDimensoes();
	void setPosicao(sf::Vector2f posicao);
	sf::Vector2f getPosicao();
	sf::Vector2f getMovimento();

	// Para saber se o elemento 
	void setDesalocavel(bool desalocavel);
	bool getDesalocavel();

	void setOrigem();
	void setTextura(const string textura);

	virtual void colidir(Personagem* personagem);
	void movimenta(sf::Vector2f movimento);
	virtual void atualiza(float deltaTempo);
	void desenhar();
	virtual void salvar();
};

