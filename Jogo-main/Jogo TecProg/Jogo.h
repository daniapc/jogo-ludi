#pragma once
#include "stdafx.h"
#include "GerenciadorGrafico.h"
#include "Jogador.h"

class Jogo
{
private:
	sf::RenderWindow Janela;

	Jogador Bruxo;

public:
	Jogo();
	~Jogo();
	void Executar();
	void LoopJogo();

};

