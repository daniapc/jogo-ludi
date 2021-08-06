#pragma once
#include "Fase.h"
#include "Passaro.h"
#include "Espinho.h"
#include "Fantasma.h"
#include "Estatico.h"
#include "GerenciadorFisica.h"
#include "Chefao.h"
#include "Porta.h"

class Quintal : public Fase
{
private:
	Porta porta;

public:
	Quintal();
	~Quintal();

	void inicializa();
	void desenhar();
	void atualiza(float deltaTempo);

	void criaPassaro(sf::Vector2f posicao);
	//void criaFantasma(sf::Vector2f posicao);
	void criaTeia(sf::Vector2f posicao);
	void criaPlataformas();
};

