#pragma once
#include "stdafx.h"
#include "Projetil.h"
#include "Personagem.h"

class Fase;

class Jogador : public Personagem
{
private:
	sf::Keyboard::Key Direita, Esquerda, Pulo, Atira;
	Fase* faseAtual;
	//static int Pontuacao;

public:
	Jogador();
	~Jogador();
	
	//static void setPontuacao(int pontuacao);
	//static int getPontuacao();
	void inicializa();
	void colidir();
	void atualiza(float deltaTempo);
	void setTeclas(sf::Keyboard::Key direita, sf::Keyboard::Key esquerda , sf::Keyboard::Key pulo, sf::Keyboard::Key atira);
	void setFaseAtual(Fase* faseatual);
	void atiraProjetil();
};

