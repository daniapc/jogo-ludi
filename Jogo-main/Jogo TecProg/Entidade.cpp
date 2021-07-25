#include "Entidade.h"

Entidade::Entidade()
{
	Janela = NULL;
}

Entidade::~Entidade()
{
}

sf::Vector2f Entidade::getDimensoes()
{
	return DimensoesCorpo;
}

sf::RectangleShape& Entidade::getCorpo()
{
	return Corpo;
}

sf::Vector2f Entidade::getPosicao()
{
	return Posicao;
}

void Entidade::setJanela(sf::RenderTarget* janela)
{
	Janela = janela;
}
