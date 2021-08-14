#include "Plataforma.h"

Plataforma::Plataforma():Obstaculo()
{
}

Plataforma::~Plataforma()
{
}

void Plataforma::colidir(Personagem* personagem)
{
	if (personagem->getColidePlataforma())
	{
		float deltaX = this->getPosicaoX()  - personagem->getPosicaoX() ;
		float deltaY = this->getPosicaoY() - personagem->getPosicaoY() ;
		float intersecaoX = abs(deltaX) - (personagem->getDimensoesX()  / 2 + this->getDimensoesX() / 2);
		float intersecaoY = abs(deltaY) - (personagem->getDimensoesY() / 2 + this->getDimensoesY() / 2);

			if (intersecaoX > intersecaoY) //Lógica invertida pois são valores negativos
			{
				if (deltaX > 0.f)
				{
					personagem->movimenta( intersecaoX, 0.f );
					personagem->setMovimentoX(0.f);
					personagem->setOlhaDireita(false);
				}

				else
				{
					personagem->movimenta( -intersecaoX, 0.f );
					personagem->setMovimentoX(0.f);
					personagem->setOlhaDireita(true);
				}
			}
			else
			{
				if (deltaY > 0.f)
				{
					personagem->setPodePular(true);
					personagem->movimenta( 0.f, intersecaoY );
					personagem->setMovimentoY(0.f);
				}
				else
				{
					personagem->movimenta( 0.f, -intersecaoY );
					personagem->setMovimentoY(0.f);
				}
			}
	}
}

void Plataforma::salvar()
{
}
