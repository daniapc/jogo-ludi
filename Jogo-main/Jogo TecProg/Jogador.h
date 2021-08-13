#pragma once
#include "stdafx.h"
#include "Projetil.h"
#include "Personagem.h"
#include "Atirador.h"

class Fase;
class Jogo;

class Jogador : public Personagem, public Atirador
{
private:
	sf::Keyboard::Key Direita, Esquerda, Pulo, Atira;
	bool podePular;
	float alturaPulo;
	static int Pontuacao;

public:
	Jogador();
	~Jogador();


	void setPodePular(bool podepular);
	void setAlturaPulo(float alturapulo);
	void incrementaPontuacao();
	static int getPontuacao();
	void inicializa();
	void colidir();
	void atualiza(float deltaTempo);
	void setTeclas(sf::Keyboard::Key direita, sf::Keyboard::Key esquerda , sf::Keyboard::Key pulo, sf::Keyboard::Key atira);
	//void atiraProjetil();
	void salvar();
};

