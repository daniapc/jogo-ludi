#pragma once
#include "stdafx.h"
#include "GerenciadorGrafico.h"
#include "Quintal.h"

class Jogo
{
private:

	GerenciadorGrafico gerenciadorGrafico;
	Quintal Fase_Quintal;

public:
	Jogo();
	~Jogo();

	void Atualiza(float deltaTempo);
	void Inicializa();
	void InicializaFases();
	void Executar();
	void LoopJogo();

};

