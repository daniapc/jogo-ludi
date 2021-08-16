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

void Atirador::setTexturaProjetil(string textura1, string textura2)
{
	ProjetilDireita = textura1;
	ProjetilEsquerda = textura2;
}

void Atirador::atiraProjetilHorizontal(Personagem* personagem, float altura)
{
	Projetil* novo = NULL;

	novo = new Projetil();

	float posicaoX;

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

	faseAtual->getJogo()->getGerenciadorGrafico().criaCorpo(novo, LADO_PROJETIL, LADO_PROJETIL,
		posicaoX, altura, "textures/Projeteis.png");
	if (personagem->getOlharDireita()) {
		novo->setTextura(ProjetilDireita);
		novo->setSubTextura(ProjetilDireita);
	}

	else {
		novo->setSubTextura(ProjetilEsquerda);
		novo->setTextura(ProjetilEsquerda);
	}

	faseAtual->incluaProjetil(novo);
}

void Atirador::atiraProjetilDirecionado(Personagem* personagem, float dimensao)
{

	float modulo, deltax, deltay;

	float deltax1 = faseAtual->getJogador1()->getPosicaoX()  - personagem->getPosicaoX() ;
	float deltay1 = faseAtual->getJogador1()->getPosicaoY()  - personagem->getPosicaoY() ;
	float modulo1 = sqrt(deltax1 * deltax1 + deltay1 * deltay1);
	modulo = modulo1;
	deltax = deltax1;
	deltay = deltay1;

	if (faseAtual->getJogador2() != NULL) {
		float deltax2 = faseAtual->getJogador2()->getPosicaoX() - personagem->getPosicaoX();
		float deltay2 = faseAtual->getJogador2()->getPosicaoY() - personagem->getPosicaoY();
		float modulo2 = sqrt(deltax2 * deltax2 + deltay2 * deltay2);
		if (modulo2 > modulo1) {
			modulo = modulo1;
			deltax = deltax1;
			deltay = deltay1;
		}
		else {
			modulo = modulo2;
			deltax = deltax2;
			deltay = deltay2;
		}
	}

	try
	{
		if (modulo == 0)
			throw 1;
		else
		{
			Projetil* novo = NULL;

			novo = new Projetil();

			novo->setVelocidade(400.f * deltax / modulo, 400.f * deltay / modulo);

			novo->setAmigavel(personagem->getAmigavel());
			novo->setDesalocavel(false);
			novo->setFaseAtual(faseAtual);

			novo->setGerenciadorGrafico(&faseAtual->getJogo()->getGerenciadorGrafico());
			faseAtual->getJogo()->getGerenciadorGrafico().criaCorpo(novo, dimensao, dimensao,
				personagem->getPosicaoX(), personagem->getPosicaoY(), "textures/Projeteis.png");

			if (personagem->getOlharDireita()) {
				novo->setTextura(ProjetilDireita);
				novo->setSubTextura(ProjetilDireita);
			}
				
			else {
				novo->setSubTextura(ProjetilEsquerda);
				novo->setTextura(ProjetilEsquerda);
			}

			novo->setDimensoes(dimensao, dimensao);
			novo->setPosicao(personagem->getPosicaoX(), personagem->getPosicaoY());

			faseAtual->incluaProjetil(novo);
		}
	}
	catch (int erro)
	{
		if (erro == 1)
			cout << "Erro - Divisao por 0 - Projetil direcionado." << endl;
	}
}
