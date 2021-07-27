#pragma once
#include "stdafx.h"
#include "GerenciadorGrafico.h"
#include "Jogador.h"
#include "Entidade.h"
//#include "Personagem.h"

class Jogo
{
private:
	sf::RenderWindow Janela;
	sf::View View;

	Jogador Bruxo;
	Jogador Fazendeira;
	
	Entidade Background;

public:
	Jogo();
	~Jogo();

	void Inicializa();
	void InicializaJogadores();
	void Executar();
	void LoopJogo();

};

