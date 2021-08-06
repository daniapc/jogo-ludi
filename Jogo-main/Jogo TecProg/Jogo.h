#pragma once
#include "stdafx.h"
#include "GerenciadorGrafico.h"
#include "Quintal.h"  
#include "MenuPrincipal.h"
#include "MenuFases.h"
#include "MenuJogadores.h"
#include "MenuPause.h"
#include "Quarto.h"
 
class Jogo
{
private:

	GerenciadorGrafico gerenciadorGrafico;
	Quintal Fase_Quintal;
	Quarto Fase_Quarto;
	static int Pontuacao;
	int Estado;
	MenuPrincipal menuPrincipal;
	MenuJogadores menuJogadores;
	MenuFases menuFases;
	MenuPause menuPause;
	//MenuJogadores;
	//MenuColocacao;

public:
	Jogo();
	~Jogo();

	void setEstado(int estado);

	void Atualiza(float deltaTempo);
	void Inicializa();
	void InicializaFases();
	void Executar();
	void LoopJogo();

};

