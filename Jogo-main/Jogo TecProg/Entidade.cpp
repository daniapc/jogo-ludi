#include "Entidade.h"
#include "Personagem.h"
#include "GerenciadorGrafico.h"

int Entidade::IdAtual = 0;

Entidade::Entidade():
	Ente(),
	Desalocavel(false),
	MovimentoX(0),
	MovimentoY(0),
	PosicaoX(0),
	PosicaoY(0),
	DimensaoX(0),
	DimensaoY(0),
	IdCorpo(0)
{
}

Entidade::~Entidade()
{
}
 

void Entidade::setDimensoes(float x, float y)
{
	pGerenciadorGrafico->setDimensoes(IdCorpo, x, y);
	DimensaoX = x;
	DimensaoY = y;
}


float Entidade::getDimensoesX()
{
	return pGerenciadorGrafico->getDimensoesX(IdCorpo);
}

float Entidade::getDimensoesY()
{
	return pGerenciadorGrafico->getDimensoesY(IdCorpo);
}



void Entidade::setPosicao(float x, float y)
{

	pGerenciadorGrafico->setPosicao(IdCorpo, x, y);
	PosicaoX = x;
	PosicaoY = y;
}



float Entidade::getPosicaoX()
{
	return pGerenciadorGrafico->getPosicaoX(IdCorpo);
}

float Entidade::getPosicaoY()
{
	return pGerenciadorGrafico->getPosicaoY(IdCorpo);
}


float Entidade::getMovimentoX()
{
	return MovimentoX;
}

float Entidade::getMovimentoY()
{
	return MovimentoY;
}


void Entidade::setDesalocavel(bool desalocavel)
{
	Desalocavel = desalocavel;
}

bool Entidade::getDesalocavel()
{
	return Desalocavel;
}

void Entidade::setTextura(const string textura)
{
	/*
		if (!Textura.loadFromFile(textura))
        cerr << "Erro. Nao foi possivel carregar a textura de uma Entidade." << endl;
	*/
	//pGerenciadorGrafico->

	//Corpo.setTexture(&Textura);
	Textura = textura;

}

void Entidade::incrementaIdAtual()
{
	IdAtual++;
}

void Entidade::setId(int id)
{
	IdCorpo = id;
}

int Entidade::getIdAtual()
{
	return IdAtual;
}

int Entidade::getId()
{
	return IdCorpo;
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
