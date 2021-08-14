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
	char Direita, Esquerda, Pulo, Atira;
	bool podePular;
	float alturaPulo;
	static int Pontuacao;

public:
	Jogador();
	~Jogador();

	void setPodePular(bool podepular);
	void setAlturaPulo(float alturapulo);
	void setTeclas(char direita, char esquerda, char pulo, char atira);

	void incrementaPontuacao();
	static int getPontuacao();

	void atualiza(float deltaTempo);
	void salvar();
};

