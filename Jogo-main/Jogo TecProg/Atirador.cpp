#include "Atirador.h"
#include "Fase.h"
#include "Personagem.h"
#include "Jogo.h"

Atirador::Atirador():
	faseAtual(NULL)
{
}

Atirador::~Atirador()
{
}

void Atirador::setFaseAtual(Fase* faseatual) {
	faseAtual = faseatual;
}

void Atirador::atiraProjetilHorizontal(Personagem* personagem, float altura)
{
	Projetil* novo = NULL;

	novo = new Projetil();

	float posicaoX;

	//novo->setJanela(faseAtual->getJanela());
	novo->setAmigavel(personagem->getAmigavel());
	novo->setDesalocavel(false);
	novo->setFaseAtual(faseAtual);
	novo->setGerenciadorGrafico(&faseAtual->getJogo()->getGerenciadorGrafico());

	if (personagem->getOlharDireita())
	{
		posicaoX = personagem->getPosicaoX() + personagem->getDimensoesX() / 2;
		novo->setVelocidade(600.f, 0.f);
	}
	else
	{
		posicaoX = personagem->getPosicaoX() + personagem->getDimensoesX() / 2;
		novo->setVelocidade(-600.f, 0.f);
	}

	faseAtual->getJogo()->getGerenciadorGrafico().criaCorpo(novo, 10.f, 10.f, 
		posicaoX, altura, "");

	novo->setPosicao(posicaoX, altura);

	novo->setDimensoes(10.f, 10.f);


	faseAtual->incluaProjetil(novo); //Incluído na fase
}

void Atirador::atiraProjetilDirecionado(Personagem* personagem, float dimensao)
{
	float deltax = faseAtual->getFazendeira()->getPosicaoX()  - personagem->getPosicaoX() ;
	float deltay = faseAtual->getFazendeira()->getPosicaoY()  - personagem->getPosicaoY() ;
	float modulo = sqrt(deltax * deltax + deltay * deltay);

	try
	{
		if (modulo == 0)
			throw 1;
		else
		{
			Projetil* novo = NULL;

			novo = new Projetil();


			novo->setVelocidade(400.f * deltax / modulo, 400.f * deltay / modulo);


			//novo->setJanela(faseAtual->getJanela());
			novo->setAmigavel(personagem->getAmigavel());
			novo->setDesalocavel(false);
			novo->setFaseAtual(faseAtual);

			novo->setGerenciadorGrafico(&faseAtual->getJogo()->getGerenciadorGrafico());
			faseAtual->getJogo()->getGerenciadorGrafico().criaCorpo(novo, dimensao, dimensao,
				personagem->getPosicaoX(), personagem->getPosicaoY(), "");

			novo->setDimensoes(dimensao, dimensao);
			novo->setPosicao(personagem->getPosicaoX(), personagem->getPosicaoY());

			faseAtual->incluaProjetil(novo); //Incluído na fase	
		}
	}
	catch (int erro)
	{
		if (erro == 1)
			cout << "Erro - Divisao por 0 - Projetil direcionado." << endl;
	}
}
