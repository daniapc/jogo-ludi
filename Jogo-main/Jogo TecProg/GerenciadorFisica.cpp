#include "GerenciadorFisica.h"

GerenciadorFisica::GerenciadorFisica()
{
}

GerenciadorFisica::~GerenciadorFisica()
{
}

void GerenciadorFisica::setFazendeira(Jogador* fazendeira)
{
	pFazendeira = fazendeira;
}

void GerenciadorFisica::incluaPlataforma(Plataforma* plataforma)
{
	ListaPlataformas.push_back(plataforma);
}

void GerenciadorFisica::incluaEspinho(Espinho* espinho)
{
	ListaEspinhos.push_back(espinho);
}

void GerenciadorFisica::incluaFantasma(Fantasma* fantasma)
{
	ListaFantasmas.push_back(fantasma);
}

void GerenciadorFisica::incluaPersonagem(Personagem* personagem)
{
	ListaPersonagens.push_back(personagem);
}

void GerenciadorFisica::checaColisoes()
{
	
	for (unsigned int i = 0; i < ListaPlataformas.size(); i++)
		checaColisao(pFazendeira, ListaPlataformas[i]);

	for (unsigned int i = 0; i < ListaEspinhos.size(); i++)
	{
		sf::FloatRect hitbox_espinho = ListaEspinhos[i]->getHitbox();
		sf::FloatRect hitbox_jogador = pFazendeira->getHitbox();

		if (hitbox_jogador.intersects(hitbox_espinho))
		{
			cout << "Colidiu Espinho!" << endl;
		}
	}

	for (unsigned int i = 0; i < ListaFantasmas.size(); i++)
	{
		sf::FloatRect hitbox_fantasma = ListaFantasmas[i]->getHitbox();
		sf::FloatRect hitbox_jogador = pFazendeira->getHitbox();

		if (hitbox_jogador.intersects(hitbox_fantasma))
		{
			cout << "Colidiu Fantasma!" << endl;
		}
	}

	checaColisaoParede(pFazendeira);
}

void GerenciadorFisica::checaColisao(Personagem* personagem, Entidade* entidade)
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
				personagem->movimenta(sf::Vector2f(intersecaoX, 0.f));
				personagem->setMovimentoX(0.f);
			}

			else
			{
				personagem->movimenta(sf::Vector2f(-intersecaoX, 0.f));
				personagem->setMovimentoX(0.f);
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

void GerenciadorFisica::checaColisaoParede(Personagem* personagem)
{
	if (personagem->getPosicao().x <= personagem->getDimensoes().x / 2)
		personagem->movimenta(sf::Vector2f(personagem->getDimensoes().x / 2 - personagem->getPosicao().x, 0.f));
	if (personagem->getPosicao().x >= COMPRIMENTO_CENARIO - personagem->getDimensoes().x / 2)
		personagem->movimenta(sf::Vector2f(COMPRIMENTO_CENARIO - (personagem->getPosicao().x + personagem->getDimensoes().x / 2), 0.f));
}
	
