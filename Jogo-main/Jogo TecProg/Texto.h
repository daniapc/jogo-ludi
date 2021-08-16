#pragma once
#include "stdafx.h"

class Texto
{
private:
	string Mensagem, Cor, Fonte;
	float PosicaoX, PosicaoY, Dimensao;


public:
	Texto();
	~Texto();

	void setPosicoes(float x, float y);
	float getPosicaoX() const;
	float getPosicaoY() const;

	void setDimensao(float dim);
	float getDimensao() const;

	void setMensagem(string mens);
	string getMensagem() const;

	void setCor(string cor);
	string getCor() const;

	void setFonte(string fon);
	string getFonte() const;
};

