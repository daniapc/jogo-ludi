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
