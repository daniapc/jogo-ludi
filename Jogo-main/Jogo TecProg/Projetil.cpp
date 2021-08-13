#include "Projetil.h"
#include "Fase.h"

Projetil::Projetil():Entidade()
{
}

Projetil::~Projetil()
{
}

void Projetil::setMovimento(sf::Vector2f movimento)
{
	Movimento = movimento;
}

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
		cout << "Personagem colidiu com projetil" << endl;
		personagem->setVida(personagem->getVida() - 1);
		if (personagem->getVida() <= 0)
		{
			personagem->setDesalocavel(true);
			if (!personagem->getAmigavel())
			{
				faseAtual->getFazendeira()->incrementaPontuacao();
				cout << faseAtual->getFazendeira()->getPontuacao() << endl;
			}
		}

		this->setDesalocavel(true);
	}

}

void Projetil::atualiza(float deltaTempo)
{
	Movimento = sf::Vector2f(0.f, 0.f);


	Movimento.x += Velocidade.x;
	Movimento.y += Velocidade.y;

	this->movimenta(Movimento * deltaTempo);

	if (this->getPosicao().x <= -this->getDimensoes().x / 2 ||
		this->getPosicao().x >= COMPRIMENTO_CENARIO + this->getDimensoes().x / 2 ||
		this->getPosicao().y <= -this->getDimensoes().y / 2 ||
		this->getPosicao().y >= ALTURA_RESOLUCAO + this->getDimensoes().y / 2) 
	{
		this->setDesalocavel(true);
	}
}

void Projetil::movimenta(sf::Vector2f movimento)
{
	Corpo.move(movimento);
}

void Projetil::setVelocidade(sf::Vector2f velocidade)
{
	Velocidade = velocidade;
}

sf::Vector2f Projetil::getVelocidade()
{
	return Velocidade;
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

		gravadorProjetil << this->getPosicao().x << ' '
			<< this->getPosicao().y << ' '
			<< this->getMovimento().x << ' '
			<< this->getMovimento().y << ' '
			<< this->getVelocidade().x << ' '
			<< this->getVelocidade().y << ' '
			<< this->getAmigavel() << endl;

		gravadorProjetil.close();
	}
}
