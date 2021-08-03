#include "GerenciadorGrafico.h"

GerenciadorGrafico::GerenciadorGrafico():
	Janela(sf::VideoMode(static_cast <unsigned int>(COMPRIMENTO_RESOLUCAO), static_cast <unsigned int>(ALTURA_RESOLUCAO)),
			"Jogo", sf::Style::Fullscreen),
    View(sf::Vector2f(COMPRIMENTO_RESOLUCAO/2, ALTURA_RESOLUCAO/2), sf::Vector2f(COMPRIMENTO_RESOLUCAO, ALTURA_RESOLUCAO))
{
//
}

GerenciadorGrafico::~GerenciadorGrafico()
{
}

sf::RenderWindow& GerenciadorGrafico::getJanela()
{
	return Janela;
}

sf::View& GerenciadorGrafico::getView()
{
	return View;
}
