#include "Fantasma.h"

Fantasma::Fantasma():
	Inimigo(),
	cima(false),
	limiteXDir(0.0f),
	limiteXEsq(0.0f),
	limiteYCima(0.0f),
	limiteYBaixo(ALTURA_RESOLUCAO - (ALTURA_PLATAFORMA + ALTURA_FANTASMA / 2))
{
	CooldownAtaqueMax = 0.5f;
}

Fantasma::~Fantasma()
{
}

void Fantasma::setLimiteXEsq(float limesq)
{
	limiteXEsq = limesq;
}

void Fantasma::setLimiteXDir(float limdir)
{
	limiteXDir = limdir;
}

void Fantasma::setLimiteYCima(float limiteycima)
{
	limiteYCima = limiteycima;
}

void Fantasma::setLimiteYBaixo(float limiteybaixo)
{
	limiteYBaixo = limiteybaixo;
}

void Fantasma::colidir(Personagem* personagem)
{
	if (personagem->getAmigavel() && this->podeAtacar())
	{
		cout << "Colidiu Fantasma!" << endl;
		personagem->setVida(personagem->getVida() - 1);
		CooldownAtaque = 0.0f;
		if (personagem->getVida() <= 0)
			personagem->setDesalocavel(true);
	}
}

void Fantasma::inicializa()
{
}

void Fantasma::atualiza(float deltaTempo)
{

	CooldownAtaque += deltaTempo;

	Movimento = sf::Vector2f(0.f, 0.f);
	sf::Vector2f posicao = getPosicao();

	if (posicao.x <= limiteXEsq)
		olharDireita = true;
	else if (posicao.x >= limiteXDir)
		olharDireita = false;
	if (olharDireita && posicao.x < limiteXDir)
		Movimento.x += Velocidade;
	else if (!olharDireita && posicao.x > limiteXEsq)
		Movimento.x -= Velocidade;

	if (posicao.y >= limiteYBaixo)
		cima = true;
	else if (posicao.y <= limiteYCima)
		cima = false;
	if (cima && posicao.y > limiteYCima)
		Movimento.y -= Velocidade;
	else if (!cima && posicao.y < limiteYBaixo)
		Movimento.y += Velocidade;

	this->movimenta(Movimento * deltaTempo);
}

void Fantasma::salvar()
{
	if (!this->getDesalocavel())
	{
		ofstream gravadorFantasma("saves/Fantasmas.dat", ios::app);

		if (!gravadorFantasma)
			cout << "Erro." << endl;

		gravadorFantasma << this->getVida() << ' '
			<< this->getPosicao().x << ' '
			<< this->getPosicao().y << ' '
			<< this->getMovimento().x << ' '
			<< this->getMovimento().y << ' '
			<< this->limiteXDir << ' '
			<< this->limiteXEsq << ' '
			<< this->limiteYCima << ' '
			<< this->limiteYBaixo << ' ' 
			<< this->CooldownAtaque << endl;

		gravadorFantasma.close();
	}
}
