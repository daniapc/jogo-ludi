#pragma once
#include "Fase.h"
#include "Passaro.h"
#include "Espinho.h"
#include "Fantasma.h"
#include "Estatico.h"
#include "Porta.h"

class Jogo;

class Quintal : public Fase
{
private:
	Porta porta;

public:
	Quintal();
	~Quintal();

	void inicializa();
	void atualiza(float deltaTempo);
	void limparTudo();

	//void criaPassaro(sf::Vector2f posicao);
	void criaPlataformas();
	void criaPlataforma(float posx, float posy);


	void recuperar();
	void recuperarPassaros();
};

