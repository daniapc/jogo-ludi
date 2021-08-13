#include "Entidade.h"
#include "Personagem.h"

Entidade::Entidade():
	Ente(),
	Desalocavel(false)
{
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
	Corpo.setOrigin(DimensoesCorpo.x / 2, DimensoesCorpo.y / 2);
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

sf::Vector2f Entidade::getMovimento()
{
	return Movimento;
}

void Entidade::setDesalocavel(bool desalocavel)
{
	Desalocavel = desalocavel;
}

bool Entidade::getDesalocavel()
{
	return Desalocavel;
}

void Entidade::setOrigem()
{
	
}

void Entidade::setTextura(const string textura)
{
	if (!Textura.loadFromFile(textura))
        cerr << "Erro. Nao foi possivel carregar a textura de uma Entidade." << endl;

	Corpo.setTexture(&Textura);
}

void Entidade::colidir(Personagem* personagem)
{
}

void Entidade::movimenta(sf::Vector2f movimento)
{
	Corpo.move(movimento);
}

void Entidade::atualiza(float deltaTempo)
{
}

void Entidade::desenhar()
{
	Janela->draw(Corpo);
}

void Entidade::salvar()
{
}
