#pragma once
#include "Fase.h"
#include "Passaro.h"
#include "Espinho.h"

class Quintal : public Fase
{
private:
	vector <Passaro*> ListaPassaros;
	vector <Espinho*> ListaEspinhos;

public:
	Quintal();
	~Quintal();

	void checaColisoes();
	void inicializa();
	void desenhar();

	void criaPassaro();
	void criaEspinho(sf::Vector2f posicao);
};

