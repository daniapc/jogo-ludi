#include "Entidade.h"

Entidade::Entidade()
{
	Janela = NULL;
}

Entidade::~Entidade()
{
}

sf::RectangleShape& Entidade::getCorpo()
{
	return Corpo;
	//return gerenciadorGrafico.
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

void Entidade::setOrigem()
{
	Corpo.setOrigin(DimensoesCorpo.x / 2, DimensoesCorpo.y / 2);
}

void Entidade::setTextura(const string textura)
{
	if (!Textura.loadFromFile(textura))
        cerr << "Erro. Nao foi possivel carregar a textura de uma Entidade." << endl;

	Corpo.setTexture(&Textura);
}

void Entidade::desenhar()
{
	Janela->draw(Corpo);
}
