#include "Chefao.h"

Chefao::Chefao():Inimigo()
{
}

Chefao::~Chefao()
{
}

void Chefao::colidir(Personagem* personagem)
{
	if (personagem->getAmigavel())
		cout << "Colidiu chefao" << endl;

}

void Chefao::inicializa()
{
	Desalocavel = false;
	Neutralizavel = true;
	Amigavel = false;
	CooldownAtaque = 0;
	CooldownAtaqueMax = 2000;
	CooldownInvencibilidade = 0;
	CooldownInvencibilidadeMax = -1;
}

void Chefao::setFaseAtual(Fase* faseatual)
{
	faseAtual = faseatual;
}

void Chefao::atualiza(float deltaTempo)
{
	if (Desalocavel)
	{
		this->setDimensoes(sf::Vector2f(0.f, 0.f));
		this->setVelocidade(0.f);
		this->setPosicao(sf::Vector2f(0.f, 0.f));
	}

	Movimento = sf::Vector2f(0.f, 0.f);

	float deltax = faseAtual->getFazendeira().getPosicao().x - this->getPosicao().x;
	float modulo = sqrt(deltax*deltax);

	Movimento.x += Velocidade * deltax / modulo;
	Movimento.y += 981.f;

	if (Movimento.x > 0)
		olharDireita = true;
	else
		olharDireita = false;

	CooldownAtaque++;

	if (!Desalocavel && this->podeAtacar())
		this->atiraProjeteis();

	this->movimenta(Movimento * deltaTempo);
}

void Chefao::atiraProjetil(float altura)
{
	Projetil* novo = NULL;
	novo = new Projetil();
	novo->setDesalocavel(false);

	if (olharDireita)
	{
		novo->setPosicao(sf::Vector2f(this->getPosicao().x + this->getDimensoes().x / 2, altura));
		novo->setVelocidade(sf::Vector2f(600.f, 0.f));
	}
	else
	{
		novo->setPosicao(sf::Vector2f(this->getPosicao().x - this->getDimensoes().x / 2, altura));
		novo->setVelocidade(sf::Vector2f(-600.f, 0.f));
	}
	novo->setDimensoes(sf::Vector2f(10.f, 10.f));
	novo->setOrigem();
	novo->setJanela(Janela);
	novo->setAmigavel(false);

	faseAtual->incluaProjetil(novo); //Incluído na fase
}

void Chefao::atiraProjetil2()
{
	Projetil* novo = NULL;
	novo = new Projetil();
	novo->setDesalocavel(false);

	float deltax = faseAtual->getFazendeira().getPosicao().x - this->getPosicao().x;
	float deltay = faseAtual->getFazendeira().getPosicao().y - this->getPosicao().y;
	float modulo = sqrt(deltax * deltax + deltay * deltay);

	if (olharDireita)
	{
		novo->setPosicao(sf::Vector2f(this->getPosicao().x + this->getDimensoes().x / 2, this->getPosicao().y));
		novo->setVelocidade(sf::Vector2f(400 * deltax / modulo, 400 * deltay / modulo));
	}
	else
	{
		novo->setPosicao(sf::Vector2f(this->getPosicao().x - this->getDimensoes().x / 2, this->getPosicao().y));
		novo->setVelocidade(sf::Vector2f(400 * deltax / modulo, 400 * deltay / modulo));
	}
	novo->setDimensoes(sf::Vector2f(20.f, 20.f));
	novo->setOrigem();
	novo->setJanela(Janela);
	novo->setAmigavel(false);

	faseAtual->incluaProjetil(novo); //Incluído na fase
}

void Chefao::atiraProjeteis()
{
	atiraProjetil2();
	atiraProjetil(this->getPosicao().y + this->getDimensoes().y / 2);
	atiraProjetil(this->getPosicao().y);
	atiraProjetil(this->getPosicao().y - this->getDimensoes().y / 2);
}
