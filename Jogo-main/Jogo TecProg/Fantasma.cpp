#include "Fantasma.h"

Fantasma::Fantasma():
	Inimigo(),
	cima(false)
{
	
}

Fantasma::~Fantasma()
{
}

void Fantasma::colidir(Personagem* personagem)
{
	if (personagem->getAmigavel())
		cout << "Colidiu Fantasma!" << endl;
}

void Fantasma::inicializa()
{
	Neutralizavel = true;
	Amigavel = false;
	limiteXEsq = getPosicao().x;
	limiteXDir = getPosicao().x + 200;
	limiteYBaixo = ALTURA_RESOLUCAO - (ALTURA_PLATAFORMA + ALTURA_FANTASMA/2);
	limiteYCima = DimensoesCorpo.y / 2;
	CooldownInvencibilidade = 0;
	CooldownInvencibilidadeMax = -1;
	CooldownAtaque = 0;
	CooldownAtaqueMax = 1;
}

void Fantasma::atualiza(float deltaTempo)
{
	if (Desalocavel)
	{
		this->setDimensoes(sf::Vector2f(0.f, 0.f));
		this->setVelocidade(0.f);
		this->setPosicao(sf::Vector2f(0.f, 0.f));
		/*
		Jogador::setPontuacao(Jogador::getPontuacao() + 1);
		cout << "Score: " << Jogador::getPontuacao() << endl;
		*/
	}

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
