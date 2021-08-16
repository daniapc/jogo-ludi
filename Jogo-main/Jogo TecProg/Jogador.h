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

	string Textura, SubTextura[12];

public:
	Jogador();
	~Jogador();

	void setPodePular(bool podepular);
	void setAlturaPulo(float alturapulo);
	void setTeclas(char direita, char esquerda, char pulo, char atira);

	void incrementaPontuacao();
	static int getPontuacao();

	void setTexturas(bool fazendeira);
	string getTextura() const;

	void atualiza(float deltaTempo);
	void salvar();

	Jogador& operator++();
};

