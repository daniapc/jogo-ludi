#include "Teia.h"

Teia::Teia()
{
}

Teia::~Teia()
{
}

void Teia::colidir(Personagem* personagem)
{
	if (personagem->getAmigavel())
	{
		personagem->setVelocidade(100.f);
		personagem->setPodePular(false);
	}
}

void Teia::setLentidao(float lentidao)
{
	Lentidao = lentidao;
}

float Teia::getLentidao()
{
	return Lentidao;
}

void Teia::salvar()
{
	ofstream gravadorTeia("saves/Teias.dat", ios::app);

	if (!gravadorTeia)
		cout << "Erro." << endl;

	gravadorTeia << this->getPosicao().x << ' '
		<< this->getPosicao().y << ' ' << endl;

	gravadorTeia.close();
}
