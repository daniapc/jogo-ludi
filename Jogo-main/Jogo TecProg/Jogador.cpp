#include "Jogador.h"

Jogador::Jogador():
	Entidade()
{

}

Jogador::~Jogador()
{
}

void Jogador::Inicializa(sf::Vector2f dimensoes, sf::Vector2f posicao)
{
	Corpo.setSize(dimensoes);
	Corpo.setPosition(posicao.x, posicao.y);
}


