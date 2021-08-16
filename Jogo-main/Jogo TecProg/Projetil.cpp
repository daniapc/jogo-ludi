#include "Projetil.h"
#include "Fase.h"

Projetil::Projetil():Entidade()
{
}

Projetil::~Projetil()
{
}

void Projetil::setAmigavel(bool amigavel)
{
	this->Amigavel = amigavel;
}

bool Projetil::getAmigavel() const
{
	return Amigavel;
}

void Projetil::colidir(Personagem* personagem)
{
	if (personagem->getAmigavel() != Amigavel && personagem->podeMorrer())
	{
		personagem->setVida(personagem->getVida() - 1);
		if (personagem->getVida() <= 0)
		{
			personagem->setDesalocavel(true);
			if (!personagem->getAmigavel())
			{
				if (faseAtual != NULL) {
					faseAtual->getJogador1()->incrementaPontuacao();
					cout << faseAtual->getJogador1()->getPontuacao() << endl;
				}
			}
		}
		this->setDesalocavel(true);
	}
}

void Projetil::atualiza(float deltaTempo)
{
	MovimentoX = 0;
	MovimentoY = 0;

	MovimentoX += VelocidadeX;
	MovimentoY += VelocidadeY;

	this->movimenta(MovimentoX * deltaTempo, MovimentoY * deltaTempo);

	if (this->getPosicaoX() <= -this->getDimensoesX() / 2 ||
		this->getPosicaoX()>= COMPRIMENTO_CENARIO + this->getDimensoesX() / 2 ||
		this->getPosicaoY() <= -this->getDimensoesY() / 2 ||
		this->getPosicaoY() >= ALTURA_RESOLUCAO + this->getDimensoesY() / 2) 
	{
		this->setDesalocavel(true);
	}
}


void Projetil::setVelocidade(float velx, float vely)
{
	VelocidadeX = velx;
	VelocidadeY = vely;
}
void Projetil::setTextura(string textura)
{
	Textura = textura;
}

float Projetil::getVelocidadeX() const
{
	return VelocidadeX;
}

float Projetil::getVelocidadeY() const
{
	return VelocidadeY;
}


void Projetil::setFaseAtual(Fase* faseatual)
{
	faseAtual = faseatual;
}

void Projetil::salvar()
{
	if (!this->getDesalocavel())
	{
		ofstream gravadorProjetil("saves/Projeteis.dat", ios::app);

		if (!gravadorProjetil)
			cout << "Erro." << endl;

		gravadorProjetil << this->getPosicaoX() << ' '
			<< this->getPosicaoY() << ' '
			<< this->getVelocidadeX() << ' '
			<< this->getVelocidadeY() << ' '
			<< this->getAmigavel() << ' '
			<< Textura << ' '
			<< this->getDimensoesX() << endl;

		gravadorProjetil.close();
	}
}
