#include "Espinho.h"

Espinho::Espinho():
	Obstaculo(),
	CooldownDano(0.0f),
	CooldownDanoMax(0.75f)
{
}

Espinho::~Espinho()
{
}

void Espinho::atualiza(float deltaTempo)
{
	CooldownDano += deltaTempo;
}

bool Espinho::podeDarDano()
{
	if (CooldownDano >= CooldownDanoMax)
		return true;
	return false;
}

void Espinho::colidir(Personagem* personagem)
{
	if (personagem->getAmigavel() && this->podeDarDano())
	{
		personagem->setVida(personagem->getVida() - 1);
		CooldownDano = 0.0f;
		if (personagem->getVida() <= 0)
			personagem->setDesalocavel(true);
	}
}

void Espinho::salvar()
{
	ofstream gravadorEspinho("saves/Espinhos.dat", ios::app);

	if (!gravadorEspinho)
		cout << "Erro." << endl;

	gravadorEspinho << this->getPosicaoX()  << ' '
		<< this->getPosicaoY()  << ' ' <<  endl;

	gravadorEspinho.close();
}

