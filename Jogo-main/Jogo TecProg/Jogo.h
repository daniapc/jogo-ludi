#pragma once
#include "stdafx.h"
#include "GerenciadorGrafico.h"
#include "Quintal.h"  
#include "MenuPrincipal.h"
#include "MenuFases.h"
#include "MenuJogadores.h"
#include "MenuPause.h"
#include "Quarto.h"
#include "Jogador.h"
 
class Jogo
{
private:

	GerenciadorGrafico gerenciadorGrafico;
	Quintal Fase_Quintal;
	Quarto Fase_Quarto;
	static int Pontuacao;
	Jogador* Fazendeira;
	Jogador* Bruxo;
	int Estado;
	bool Multiplayer;
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
	int getEstado();
	Quarto& getQuarto();
	Quintal& getQuintal();
	void setMultiplayer(bool multiplayer);
	bool getMultiplayer();

	void Atualiza(float deltaTempo);
	void Inicializa();
	void InicializaFases();
	void InicializaQuintal();
	void InicializaQuarto();
	void Executar();
	void LoopJogo();
	void Salvar();
	void Recuperar();
};

