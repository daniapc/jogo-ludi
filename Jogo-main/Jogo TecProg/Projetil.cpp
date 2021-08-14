#include "Projetil.h"
#include "Fase.h"

Projetil::Projetil():Entidade()
{
}

Projetil::~Projetil()
{
}

/*
void Projetil::setMovimento(sf::Vector2f movimento)
{
	Movimento = movimento;
}
*/


void Projetil::setAmigavel(bool amigavel)
{
	this->Amigavel = amigavel;
}

bool Projetil::getAmigavel()
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
					faseAtual->getFazendeira()->incrementaPontuacao();
					cout << faseAtual->getFazendeira()->getPontuacao() << endl;
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
float Projetil::getVelocidadeX()
{
	return VelocidadeX;
}

float Projetil::getVelocidadeY()
{
	return VelocidadeY;
}
/*
sf::Vector2f Projetil::getVelocidade()
{
	return Velocidade;
}
*/


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
			<< this->getAmigavel() << endl;

		gravadorProjetil.close();
	}
}
