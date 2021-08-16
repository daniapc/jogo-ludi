#include "Entidade.h"
#include "Personagem.h"
#include "GerenciadorGrafico.h"

int Entidade::IdCorpoAtual = 0;

Entidade::Entidade():
	Ente(),
	Desalocavel(false),
	MovimentoX(0),
	MovimentoY(0),
	IdCorpo(0)
{
}

Entidade::~Entidade()
{
}
 
void Entidade::setDimensoes(float x, float y)
{
	pGerenciadorGrafico->setDimensoes(IdCorpo, x, y);
}


float Entidade::getDimensoesX() const 
{
	return pGerenciadorGrafico->getDimensoesX(IdCorpo);
}

float Entidade::getDimensoesY() const
{
	return pGerenciadorGrafico->getDimensoesY(IdCorpo);
}

void Entidade::setPosicao(float x, float y)
{
	pGerenciadorGrafico->setPosicao(IdCorpo, x, y);
}

float Entidade::getPosicaoX() const
{
	return pGerenciadorGrafico->getPosicaoX(IdCorpo);
}

float Entidade::getPosicaoY() const
{
	return pGerenciadorGrafico->getPosicaoY(IdCorpo);
}


void Entidade::setMovimento(float x, float y)
{
	MovimentoX = x;
	MovimentoY = y;
}

float Entidade::getMovimentoX() const
{
	return MovimentoX;
}

float Entidade::getMovimentoY() const
{
	return MovimentoY;
}

void Entidade::setDesalocavel(bool desalocavel)
{
	Desalocavel = desalocavel;
}

bool Entidade::getDesalocavel() const
{
	return Desalocavel;
}

void Entidade::incrementaIdCorpoAtual()
{
	IdCorpoAtual++;
}

void Entidade::setId(int id)
{
	IdCorpo = id;
}

int Entidade::getIdCorpoAtual() const
{
	return IdCorpoAtual;
}
 
int Entidade::getId() const
{
	return IdCorpo;
}

void Entidade::setSubTextura(string subtext)
{
	pGerenciadorGrafico->setSubTextura(IdCorpo, subtext);
}

void Entidade::colidir(Personagem* personagem)
{
}

void Entidade::movimenta(float movimentox, float movimentoy)
{
	pGerenciadorGrafico->movimenta(IdCorpo, movimentox, movimentoy);

}

void Entidade::atualiza(float deltaTempo)
{
}

void Entidade::desenhar()
{
	pGerenciadorGrafico->desenhar(IdCorpo, Desalocavel);
}

void Entidade::salvar()
{
}
