#include "Espinho.h"

Espinho::Espinho()
{
}

Espinho::~Espinho()
{
}

void Espinho::colidir(Personagem* personagem)
{
	if (personagem->getAmigavel())
		cout << "Colidiu Espinho!" << endl;
		//personagem->setVida(personagem->getVida() - 1);
}

void Espinho::salvar()
{
	ofstream gravadorEspinho("saves/Espinhos.dat", ios::app);

	if (!gravadorEspinho)
		cout << "Erro." << endl;

	gravadorEspinho << this->getPosicao().x << ' '
		<< this->getPosicao().y << ' ' <<  endl;
		//<< this->CooldownAtaque << endl;

	gravadorEspinho.close();
}

//FALTA COOLDOWN DE ATAQUE
