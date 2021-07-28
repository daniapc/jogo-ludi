#pragma once
#include "stdafx.h"
#include "GerenciadorGrafico.h"
#include "Jogador.h"
#include "Entidade.h"
#include "Quintal.h"
//#include "Personagem.h"

class Jogo
{
private:
	static const float Altura;
	static const float Comprimento;

	sf::RenderWindow Janela;
	sf::View View;

	Quintal Fase_Quintal;

public:
	Jogo();
	~Jogo();

	const float getAltura();
	const float getComprimento();

	void Atualiza();
	void Inicializa();
	void InicializaFases();
	void Executar();
	void LoopJogo();

};

