#include "Personagem.h"

Personagem::Personagem():
	Entidade(),
	Neutralizavel(true),
	Amigavel(false),
	colidePlataforma(true),
	CooldownAtaque(0.f),
	CooldownAtaqueMax(1.f),
	olharDireita(true),
	Vida(3),
	Velocidade(200.f)
{
}

Personagem::~Personagem()
{
}

void Personagem::setVida(int vida)
{
	Vida = vida;
}

int Personagem::getVida()
{
	return Vida;
}

void Personagem::setAmigavel(bool amigavel)
{
	this->Amigavel = amigavel;
}

bool Personagem::getAmigavel()
{
	return Amigavel;
}

bool Personagem::podeMorrer()
{
	return true;
}

void Personagem::colidir(Personagem* personagem)
{
}

void Personagem::setCooldownAtaque(float cooldownataque)
{
	CooldownAtaque = cooldownataque;
}

void Personagem::setOlhaDireita(bool olhardireita)
{
	olharDireita = olhardireita;
}

bool Personagem::getOlharDireita()
{
	return olharDireita;
}

void Personagem::setColidePlataforma(bool colideplataforma)
{
	colidePlataforma = colideplataforma;
}

bool Personagem::getColidePlataforma()
{
	return colidePlataforma;
}

bool Personagem::podeAtacar()
{
	if (CooldownAtaque >= CooldownAtaqueMax)
		return true;
	return false;
}

void Personagem::setMovimentoX(float movimentox)
{
	MovimentoX  = movimentox;
}

void Personagem::setMovimentoY(float movimentoy)
{
	MovimentoY  = movimentoy;
}

void Personagem::setVelocidade(float velocidade)
{
	Velocidade = velocidade;
}

float Personagem::getVelocidade()
{
	return Velocidade;
}

void Personagem::setPodePular(bool podepular)
{
}


