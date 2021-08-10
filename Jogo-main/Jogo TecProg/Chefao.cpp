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
	CooldownAtaqueMax = 1;
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

	float deltax = faseAtual->getFazendeira()->getPosicao().x - this->getPosicao().x;
	float modulo = sqrt(deltax*deltax);

	if (modulo != 0.f)
		Movimento.x += Velocidade * deltax / modulo;
	Movimento.y += 981.f * deltaTempo;

	if (Movimento.x > 0)
		olharDireita = true;
	else
		olharDireita = false;

	CooldownAtaque += deltaTempo;

	if (!Desalocavel && this->podeAtacar())
		this->atiraProjeteis();

	this->movimenta(Movimento * deltaTempo);
}

void Chefao::atiraProjetil(float altura)
{
	Projetil* novo = NULL;

	if (faseAtual->getPiscinaProjeteis().empty())
		novo = new Projetil();
	else {
		novo = faseAtual->getPiscinaProjeteis().back();
		faseAtual->getPiscinaProjeteis().pop_back();
	}


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
	novo->setDesalocavel(false);
	novo->setFaseAtual(faseAtual);
	novo->setNaPiscina(false);

	if (faseAtual->getPiscinaProjeteis().empty())
		faseAtual->incluaProjetil(novo); //Incluído na fase
}

void Chefao::atiraProjetil2()
{
	Projetil* novo = NULL;

	if (faseAtual->getPiscinaProjeteis().empty()) 
		novo = new Projetil();
	else {
		novo = faseAtual->getPiscinaProjeteis().back();
		faseAtual->getPiscinaProjeteis().pop_back();
	}

	float deltax = faseAtual->getFazendeira()->getPosicao().x - this->getPosicao().x;
	float deltay = faseAtual->getFazendeira()->getPosicao().y - this->getPosicao().y;
	float modulo = sqrt(deltax * deltax + deltay * deltay);

	novo->setPosicao(sf::Vector2f(this->getPosicao().x, this->getPosicao().y));
	novo->setVelocidade(sf::Vector2f(400 * deltax / modulo, 400 * deltay / modulo));

	novo->setDimensoes(sf::Vector2f(20.f, 20.f));
	novo->setOrigem();
	novo->setJanela(Janela);
	novo->setAmigavel(false);
	novo->setDesalocavel(false);
	novo->setFaseAtual(faseAtual);
	novo->setNaPiscina(false);

	if (faseAtual->getPiscinaProjeteis().empty())
		faseAtual->incluaProjetil(novo); //Incluído na fase
}

void Chefao::atiraProjeteis()
{
	atiraProjetil2();
	atiraProjetil(this->getPosicao().y + this->getDimensoes().y / 2);
	atiraProjetil(this->getPosicao().y);
	atiraProjetil(this->getPosicao().y - this->getDimensoes().y / 2);
}

void Chefao::salvar()
{
	if (!this->getDesalocavel())
	{
		ofstream gravadorChefao("saves/Chefao.dat", ios::app);

		if (!gravadorChefao)
			cout << "Erro." << endl;

		gravadorChefao << this->getVida() << ' '
			<< this->getPosicao().x << ' '
			<< this->getPosicao().y << ' '
			<< this->getMovimento().x << ' '
			<< this->getMovimento().y << ' '
			<< this->CooldownAtaque << endl;

		gravadorChefao.close();
	}
}
