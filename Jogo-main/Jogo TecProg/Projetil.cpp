#include "Projetil.h"
#include "Fase.h"

Projetil::Projetil()
{
}

Projetil::~Projetil()
{
}

void Projetil::setNaPiscina(bool napiscina)
{
	NaPiscina = napiscina;
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
		this->setDesalocavel(true);
	}

}

void Projetil::atualiza(float deltaTempo)
{
	Movimento = sf::Vector2f(0.f, 0.f);

	if (Desalocavel && !NaPiscina)
	{
		this->setDimensoes(sf::Vector2f(0.f, 0.f));
		this->setVelocidade(sf::Vector2f(0.f, 0.f));
		this->setPosicao(sf::Vector2f(0.f, 0.f));
		this->faseAtual->getPiscinaProjeteis().push_back(this);
		NaPiscina = true;
		cout << this->faseAtual->getPiscinaProjeteis().size() << endl;
	}

	Movimento.x += Velocidade.x;
	Movimento.y += Velocidade.y;

	this->movimenta(Movimento * deltaTempo);
}

void Projetil::movimenta(sf::Vector2f movimento)
{
	Corpo.move(movimento);
}

void Projetil::setVelocidade(sf::Vector2f velocidade)
{
	Velocidade = velocidade;
}

void Projetil::setFaseAtual(Fase* faseatual)
{
	faseAtual = faseatual;
}
