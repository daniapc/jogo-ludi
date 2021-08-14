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
	this->setColidePlataforma(false);
	this->setVelocidade(200.f);
	this->setVida(2);
}

Fantasma::~Fantasma()
{
}

void Fantasma::setLimitesX(float limesq, float limdir)
{
	limiteXEsq = limesq;
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

void Fantasma::atualiza(float deltaTempo)
{
	CooldownAtaque += deltaTempo;

	MovimentoX = 0.f;
	MovimentoY = 0.f;

	float posicaox = getPosicaoX(), posicaoy = getPosicaoY();

	if (posicaox <= limiteXEsq)
		olharDireita = true;
	else if (posicaox >= limiteXDir)
		olharDireita = false;
	if (olharDireita && posicaox < limiteXDir)
		MovimentoX += Velocidade;
	else if (!olharDireita && posicaox > limiteXEsq)
		MovimentoX -= Velocidade;

	if (posicaoy >= limiteYBaixo)
		cima = true;
	else if (posicaoy <= limiteYCima)
		cima = false;
	if (cima && posicaoy > limiteYCima)
		MovimentoY -= Velocidade;
	else if (!cima && posicaoy < limiteYBaixo)
		MovimentoY += Velocidade;

	this->movimenta(MovimentoX* deltaTempo, MovimentoY* deltaTempo);
}

void Fantasma::salvar()
{
	if (!this->getDesalocavel())
	{
		ofstream gravadorFantasma("saves/Fantasmas.dat", ios::app);

		if (!gravadorFantasma)
			cout << "Erro." << endl;

		gravadorFantasma << this->getVida() << ' '
			<< this->getPosicaoX() << ' '
			<< this->getPosicaoY() << ' '
			<< this->limiteXDir << ' '
			<< this->limiteXEsq << ' '
			<< this->CooldownAtaque << endl;

		gravadorFantasma.close();
	}
}
