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

	void criaPlataformas();
	void criaPlataforma(float posx, float posy, string subtextura = "Plataforma_Quintal_2");


	void recuperar();
	void recuperarPassaros();
};

