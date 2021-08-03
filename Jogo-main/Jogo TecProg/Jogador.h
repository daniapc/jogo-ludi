#pragma once
#include "stdafx.h"
#include "Projetil.h"
#include "Personagem.h"

class Jogador : public Personagem
{
private:
	sf::Keyboard::Key Direita, Esquerda, Pulo, Atira;
	bool direita;

public:
	Jogador();
	~Jogador();
	
	void inicializa();

	void atualiza(float deltaTempo);
	void setTeclas(sf::Keyboard::Key direita, sf::Keyboard::Key esquerda , sf::Keyboard::Key pulo, sf::Keyboard::Key atira);
	void atiraProjetil();
};

