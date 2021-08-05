#pragma once
#include "Fase.h"
#include "Passaro.h"
#include "Espinho.h"
#include "Fantasma.h"
#include "Estatico.h"
#include "GerenciadorFisica.h"

class Quintal : public Fase
{
private:
	/*
	vector <Passaro*> ListaPassaros;
	vector <Espinho*> ListaEspinhos;
	vector <Fantasma*> ListaFantasmas;
	vector <Teia*> ListaTeias;
	*/

public:
	Quintal();
	~Quintal();

	void inicializa();
	void desenhar();
	void atualiza(float deltaTempo);

	void criaPassaro(sf::Vector2f posicao);
	void criaFantasma(sf::Vector2f posicao);
	void criaTeia(sf::Vector2f posicao);
	void criaPlataformas();
};

