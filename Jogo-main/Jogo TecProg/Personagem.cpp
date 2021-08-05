#include "Personagem.h"

Personagem::Personagem() : Entidade()
{
}

Personagem::~Personagem()
{
}

void Personagem::setVida(int vida)
{
	if (vida == 0)
		Desalocavel = true;

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

void Personagem::atualiza(float deltaTempo)
{
}

void Personagem::colidir()
{
}

bool Personagem::podeMorrer()
{

	if (CooldownInvencibilidade >= CooldownInvencibilidadeMax)
		CooldownInvencibilidade = 1;
	if (CooldownInvencibilidade % CooldownInvencibilidadeMax + 1 <= CooldownInvencibilidadeMax/2)
		return false;
	else
		return true;
}

void Personagem::setOlhaDireita(bool olhardireita)
{
	olharDireita = olhardireita;
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
	{
		CooldownAtaque = 0;
		return true;
	}
	return false;
}

void Personagem::setMovimentoX(float movimentox)
{
	Movimento.x = movimentox;
}

void Personagem::setMovimentoY(float movimentoy)
{
	Movimento.y = movimentoy;
}

void Personagem::setVelocidade(float velocidade)
{
	Velocidade = velocidade;
}

void Personagem::setPodePular(bool podepular)
{
	podePular = podepular;
}

void Personagem::setAlturaPulo(float alturapulo)
{
	alturaPulo = alturapulo;
}

float Personagem::getVelocidade()
{
	return Velocidade;
}

