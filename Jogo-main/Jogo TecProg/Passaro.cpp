#include "Passaro.h"
#include "Fase.h"

Passaro::Passaro():
	Inimigo(),
	limiteXDir(0.0f),
	limiteXEsq(0.0f)
{
	CooldownAtaqueMax = 2.f;
	this->setVida(3);
	this->setVelocidade(200.f);
}

Passaro::~Passaro()
{
}

void Passaro::setLimites(float limesq, float limdir)
{
	limiteXEsq = limesq;
	limiteXDir = limdir;

}

void Passaro::colidir(Personagem* personagem)
{
	if (personagem->getAmigavel() && this->podeAtacar())
	{
		cout << "Colidiu com Passaro!" << endl;
		personagem->setVida(personagem->getVida() - 1);
		if (personagem->getVida() <= 0)
			personagem->setDesalocavel(true);
	}
}

void Passaro::atualiza(float deltaTempo)
{
	MovimentoX = 0.f;
	MovimentoY = 0.f;
	//Movimento = sf::Vector2f(0.f, 0.f);
	float posicaox = getPosicaoX(), posicaoy = getPosicaoY();
	//sf::Vector2f posicao = getPosicao();

	if (posicaox <= limiteXEsq)
		olharDireita = true;
	else if (posicaox >= limiteXDir)
		olharDireita = false;
	if (olharDireita && posicaox < limiteXDir)
		MovimentoX += Velocidade;
	else if (!olharDireita && posicaox > limiteXEsq)
		MovimentoX -= Velocidade;

	this->movimenta(MovimentoX * deltaTempo, MovimentoY * deltaTempo);
	srand(time(NULL));

	CooldownAtaque += deltaTempo;

	if (this->podeAtacar())
	{
		CooldownAtaque = 0;
		this->atiraProjetilDirecionado(this, 10.0f);
	}
}

void Passaro::salvar()
{
	if (!this->getDesalocavel())
	{
		ofstream gravadorPassaro("saves/Passaros.dat", ios::app);

		if (!gravadorPassaro)
			cout << "Erro Gravar Passaro." << endl;

		gravadorPassaro << this->getVida() << ' '
			<< this->getPosicaoY() << ' '
			<< this->getPosicaoX() << ' '
			<< this->limiteXDir << ' '
			<< this->limiteXEsq << ' '
			<< this-> CooldownAtaque << endl;

		gravadorPassaro.close();
	}
}

