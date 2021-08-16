#pragma once
#include "stdafx.h"
#include "GerenciadorGrafico.h" 
#include "MenuPrincipal.h"
#include "MenuFases.h"
#include "MenuJogadores.h"
#include "MenuPause.h"
#include "MenuColocacao.h"
#include "Creditos.h"
#include "Quintal.h"
#include "Quarto.h"
#include "Jogador.h"
 
class Jogo
{
private:
	GerenciadorGrafico gerenciadorGrafico;
	Quintal Fase_Quintal;
	Quarto Fase_Quarto;
	Jogador* Jogador1;
	Jogador* Jogador2;
 	int Estado;
	bool Multiplayer;
	Menus::MenuPrincipal menuPrincipal;
	Menus::MenuJogadores menuJogadores;
	Menus::MenuFases menuFases;
	Menus::MenuPause menuPause;
	Menus::MenuColocacao menuColocacao;
	Menus::Creditos creditos;

	bool Jogador1Fazendeira;

public:
	Jogo();
	~Jogo();

	void setEstado(const int estado);
	int getEstado();
	Quarto& getQuarto();
	Quintal& getQuintal();
	void setMultiplayer(bool multiplayer);
	bool getMultiplayer() const;
	GerenciadorGrafico& getGerenciadorGrafico();

	Menus::MenuColocacao& getMenuColocacao();
	
	Jogador* getJogador2();
	Jogador* getJogador1();

	void Atualiza(float deltaTempo);
	void Inicializa();
	void InicializaFases();
	void InicializaQuintal();
	void InicializaQuarto();
	void InicializaJogadores();
	void Executar();
	void LoopJogo();
	void Salvar();
	void Recuperar();
	void LimparArquivos();

	void setJogador1Fazendeira(bool fazendeira);
	bool getJogador1Fazendeira() const;

	void setEstadoAtual(int estado);

	void mensagemCreditos(string mensagem);

	void MenusJogo(int estado, char tecla);

	void RecuperarJogadores();
};

