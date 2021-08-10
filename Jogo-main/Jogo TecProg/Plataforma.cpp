#include "Plataforma.h"

Plataforma::Plataforma()
{
}

Plataforma::~Plataforma()
{
}

void Plataforma::colidir(Personagem* personagem)
{
	if (personagem->getColidePlataforma())
	{
		float deltaX = this->getPosicao().x - personagem->getPosicao().x;
		float deltaY = this->getPosicao().y - personagem->getPosicao().y;
		float intersecaoX = abs(deltaX) - (personagem->getDimensoes().x / 2 + this->getDimensoes().x / 2);
		float intersecaoY = abs(deltaY) - (personagem->getDimensoes().y / 2 + this->getDimensoes().y / 2);

			if (intersecaoX > intersecaoY) //Lógica invertida pois são valores negativos
			{
				if (deltaX > 0.f)
				{
					personagem->movimenta(sf::Vector2f(intersecaoX, 0.f));
					personagem->setMovimentoX(0.f);
					personagem->setOlhaDireita(false);
				}

				else
				{
					personagem->movimenta(sf::Vector2f(-intersecaoX, 0.f));
					personagem->setMovimentoX(0.f);
					personagem->setOlhaDireita(true);
				}
			}
			else
			{
				if (deltaY > 0.f)
				{
					personagem->setPodePular(true);
					personagem->movimenta(sf::Vector2f(0.f, intersecaoY));
					personagem->setMovimentoY(0.f);
				}
				else
				{
					personagem->movimenta(sf::Vector2f(0.f, -intersecaoY));
					personagem->setMovimentoY(0.f);
			}
		}
	}
}

void Plataforma::salvar()
{
}
