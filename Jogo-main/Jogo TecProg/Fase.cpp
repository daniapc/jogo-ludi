#include "Fase.h"

Fase::Fase()
{
	Janela = NULL;
    View = NULL;
}

Fase::~Fase()
{
//Desalocar todas as entidades de uma só vez?
    View = NULL;

}

void Fase::criaEntidades()
{
}

void Fase::criaPlataforma(sf::Vector2f posicao, sf::Vector2f tamanho, const string textura)
{
	Plataforma* nova = NULL;
	nova = new Plataforma();
	nova->setDimensoes(tamanho);
	nova->setPosicao(posicao);
	nova->setOrigem();
	nova->setTextura(textura);
	nova->setJanela(Janela);
	ListaPlataformas.push_back(nova);
	ListaEntidades.push_back(static_cast <Entidade*> (nova));
}

Jogador& Fase::getFazendeira()
{
	return Fazendeira;
}

void Fase::atualiza()
{
	checaColisoes();

    Fazendeira.atualiza();

	atualizaView();

    desenhar();
}

void Fase::atualizaView()
{
	if (Fazendeira.getPosicao().x > 640.f && Fazendeira.getPosicao().x < 3360.f)
		View->setCenter(sf::Vector2f(Fazendeira.getPosicao().x, 360.f));
}

void Fase::checaColisao(Personagem* personagem, Entidade* entidade)
{
	float deltaX = entidade->getPosicao().x - personagem->getPosicao().x;
	float deltaY = entidade->getPosicao().y - personagem->getPosicao().y;
	float intersecaoX = abs(deltaX) - (personagem->getDimensoes().x / 2 + entidade->getDimensoes().x / 2);
	float intersecaoY = abs(deltaY) - (personagem->getDimensoes().y / 2 + entidade->getDimensoes().y / 2);

	if (intersecaoX < 0.f && intersecaoY < 0.f)
	{
		if (intersecaoX > intersecaoY) //Lógica invertida pois são valores negativos
		{
			if (deltaX > 0.f)
			{
				personagem->setVelocidade(sf::Vector2f(intersecaoX, 0.f));
				personagem->movimenta();
			}
				
			else
			{
				personagem->setVelocidade(sf::Vector2f(-intersecaoX, 0.f));
				personagem->movimenta();
			}
		}
		else
		{
			if (deltaY > 0.f)
			{
				personagem->setVelocidade(sf::Vector2f(0.f, intersecaoY));
				personagem->movimenta();
			}
			else
			{
				personagem->setVelocidade(sf::Vector2f(0.f, -intersecaoY));
				personagem->movimenta();
			}
		}
	}
}

void Fase::setJanela(sf::RenderWindow* janela)
{
	Janela = janela;
}

void Fase::setView(sf::View* view)
{
    View = view;
}
