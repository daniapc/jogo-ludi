#include "Entidade.h"

Entidade::Entidade()
{
	Janela = NULL;
}

Entidade::~Entidade()
{
}

void Entidade::setCor(sf::Color cor)
{
	Cor = cor;
	Corpo.setFillColor(Cor);
}

sf::Color Entidade::getCor()
{
	return Cor;
}

void Entidade::setDimensoes(sf::Vector2f dimensoes)
{
	DimensoesCorpo = dimensoes;
	Corpo.setSize(DimensoesCorpo);
}

sf::Vector2f Entidade::getDimensoes()
{
	return DimensoesCorpo;
}

sf::RectangleShape Entidade::getCorpo()
{
	return Corpo;
}

void Entidade::setPosicao(sf::Vector2f posicao)
{
	Posicao = posicao;
	Corpo.setPosition(Posicao);
}

sf::Vector2f Entidade::getPosicao()
{
	Posicao = Corpo.getPosition();
	return Posicao;
}

void Entidade::setTextura(const string textura)
{
	if (!Textura.loadFromFile(textura))
        cerr << "Erro. Nao foi possivel carregar a textura de uma Entidade." << endl;

	Corpo.setTexture(&Textura);
}

void Entidade::setJanela(sf::RenderWindow* janela)
{
	Janela = janela;
}

void Entidade::desenhar()
{
	Janela->draw(Corpo);
}
