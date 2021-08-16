#include "Texto.h"

Texto::Texto()
{
}

Texto::~Texto()
{
}

void Texto::setPosicoes(float x, float y)
{
	PosicaoX = x;
	PosicaoY = y;
}

float Texto::getPosicaoX() const
{
	return PosicaoX;
}

float Texto::getPosicaoY() const
{
	return PosicaoY;
}

void Texto::setDimensao(float dim)
{
	Dimensao = dim;
}

float Texto::getDimensao() const
{
	return Dimensao;
}

void Texto::setMensagem(string mens)
{
	Mensagem = mens;
}

string Texto::getMensagem() const
{
	return Mensagem ;
}

void Texto::setCor(string cor)
{
	Cor = cor;
}

string Texto::getCor() const
{
	return Cor;
}

void Texto::setFonte(string fon)
{
	Fonte = fon;
}

string Texto::getFonte() const
{
	return Fonte;
}
