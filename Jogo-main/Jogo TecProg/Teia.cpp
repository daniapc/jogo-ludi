#include "Teia.h"

Teia::Teia():Obstaculo()
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

void Teia::salvar()
{
	ofstream gravadorTeia("saves/Teias.dat", ios::app);

	if (!gravadorTeia)
		cout << "Erro." << endl;

	gravadorTeia << this->getPosicaoX()  << ' '
		<< this->getPosicaoY()  << ' ' << endl;

	gravadorTeia.close();
}
