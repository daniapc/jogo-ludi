#include "Jogador.h"

Jogador::Jogador():Personagem()
{
}

Jogador::~Jogador()
{
}

void Jogador::inicializa()
{
}

void Jogador::atualiza(float deltaTempo)
{
	Movimento.x = 0.f;

	if (sf::Keyboard::isKeyPressed(Direita))
	{
		Movimento.x += Velocidade;
		direita = true;
	}
	if (sf::Keyboard::isKeyPressed(Esquerda))
	{
		Movimento.x -= Velocidade;
		direita = false;
	}
	if (podePular && sf::Keyboard::isKeyPressed(Pulo))
	{
		podePular = false;
		Movimento.y = -sqrt(2 * 981.f * alturaPulo);
	}
	if (sf::Keyboard::isKeyPressed(Atira))
	{
		atiraProjetil();
	}

	Movimento.y += 981.f * deltaTempo;

	this->movimenta(Movimento * deltaTempo);
}

void Jogador::setTeclas(sf::Keyboard::Key direita, sf::Keyboard::Key esquerda, sf::Keyboard::Key pulo, sf::Keyboard::Key atira)
{
	Direita = direita;
	Esquerda = esquerda;
	Pulo = pulo;
	Atira = atira;
}

void Jogador::atiraProjetil()
{
	Projetil* novo = NULL;
	novo = new Projetil();
	if (direita)
	{
		novo->setPosicao(sf::Vector2f(this->getPosicao().x + this->getDimensoes().x / 2, this->getPosicao().y));
		novo->setDimensoes(sf::Vector2f(10.f, 10.f));
		novo->setOrigem();
		novo->setJanela(Janela);
		novo->setVelocidade(sf::Vector2f(400.f, 0.f));
	}
	else
	{
		novo->setPosicao(sf::Vector2f(this->getPosicao().x - this->getDimensoes().x / 2, this->getPosicao().y));
		novo->setDimensoes(sf::Vector2f(10.f, 10.f));
		novo->setOrigem();
		novo->setJanela(Janela);
		novo->setVelocidade(sf::Vector2f(-400.f, 0.f));
	}
}


