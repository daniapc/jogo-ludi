#include "Atirador.h"
#include "Fase.h"
#include "Personagem.h"

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

void Atirador::atiraProjetilHorizontal(Personagem* personagem)
{
	Projetil* novo = NULL;

	novo = new Projetil();

	if (personagem->getOlharDireita())
	{
		novo->setPosicao(sf::Vector2f(personagem->getPosicao().x + personagem->getDimensoes().x / 2, personagem->getPosicao().y));
		novo->setVelocidade(sf::Vector2f(600.f, 0.f));
	}
	else
	{
		novo->setPosicao(sf::Vector2f(personagem->getPosicao().x - personagem->getDimensoes().x / 2, personagem->getPosicao().y));
		novo->setVelocidade(sf::Vector2f(-600.f, 0.f));
	}
	novo->setDimensoes(sf::Vector2f(10.f, 10.f));
	//novo->setOrigem();
	novo->setJanela(faseAtual->getJanela());
	novo->setAmigavel(personagem->getAmigavel());
	novo->setDesalocavel(false);
	novo->setFaseAtual(faseAtual);

	faseAtual->incluaProjetil(novo); //Incluído na fase
}

void Atirador::atiraProjetilHorizontal(Personagem* personagem, float altura)
{
	Projetil* novo = NULL;

	novo = new Projetil();

	if (personagem->getOlharDireita())
	{
		novo->setPosicao(sf::Vector2f(personagem->getPosicao().x + personagem->getDimensoes().x / 2, altura));
		novo->setVelocidade(sf::Vector2f(600.f, 0.f));
	}
	else
	{
		novo->setPosicao(sf::Vector2f(personagem->getPosicao().x - personagem->getDimensoes().x / 2, altura));
		novo->setVelocidade(sf::Vector2f(-600.f, 0.f));
	}
	novo->setDimensoes(sf::Vector2f(10.f, 10.f));
	//novo->setOrigem();
	novo->setJanela(faseAtual->getJanela());
	novo->setAmigavel(personagem->getAmigavel());
	novo->setDesalocavel(false);
	novo->setFaseAtual(faseAtual);

	faseAtual->incluaProjetil(novo); //Incluído na fase
}

void Atirador::atiraProjetilDirecionado(Personagem* personagem, float dimensao)
{
	float deltax = faseAtual->getFazendeira()->getPosicao().x - personagem->getPosicao().x;
	float deltay = faseAtual->getFazendeira()->getPosicao().y - personagem->getPosicao().y;
	float modulo = sqrt(deltax * deltax + deltay * deltay);

	try
	{
		if (modulo == 0)
			throw 1;
		else
		{
			Projetil* novo = NULL;

			novo = new Projetil();

			novo->setPosicao(personagem->getPosicao());
			novo->setVelocidade(sf::Vector2f(400.f * deltax / modulo, 400.f * deltay / modulo));

			novo->setDimensoes(sf::Vector2f(dimensao, dimensao));
			//novo->setOrigem();
			novo->setJanela(faseAtual->getJanela());
			novo->setAmigavel(personagem->getAmigavel());
			novo->setDesalocavel(false);
			novo->setFaseAtual(faseAtual);

			faseAtual->incluaProjetil(novo); //Incluído na fase	
		}
	}
	catch (int erro)
	{
		if (erro == 1)
			cout << "Erro - Divisao por 0 - Projetil direcionado." << endl;
	}
}
