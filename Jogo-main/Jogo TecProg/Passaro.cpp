#include "Passaro.h"
#include "Fase.h"

Passaro::Passaro():
	Inimigo(),
	limiteXDir(0.0f),
	limiteXEsq(0.0f)
{
	CooldownAtaqueMax = 3.5f;
	this->setVida(3);
	this->setVelocidade(200.f);
	this->setTexturaProjetil("Projeteis_5", "Projeteis_6");
	CooldownAnimacaoMax = 0.25f;
	CooldownAnimacao = 0.f;
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
	float posicaox = getPosicaoX(), posicaoy = getPosicaoY();

	if (posicaox <= limiteXEsq) {
		olharDireita = true;
	}
	else if (posicaox >= limiteXDir) {
		olharDireita = false;
	}
	if (olharDireita && posicaox < limiteXDir) {
		MovimentoX += Velocidade;
		setSubTextura("textures/Passaro.png");
		if (CooldownAnimacao <= CooldownAnimacaoMax/2) {
			setSubTextura("Passaro_2");
		}
	}
	else if (!olharDireita && posicaox > limiteXEsq) {
		MovimentoX -= Velocidade;
		setSubTextura("Passaro_3");
		if (CooldownAnimacao <= CooldownAnimacaoMax/2) {
			setSubTextura("Passaro_4");
		}
	}

	this->movimenta(MovimentoX * deltaTempo, MovimentoY * deltaTempo);
	srand(time(NULL));

	CooldownAtaque += deltaTempo;
	CooldownAnimacao += deltaTempo;

	if (this->podeAtacar())
	{
		CooldownAtaque = 0;
		this->atiraProjetilDirecionado(this, LADO_PROJETIL);
	}

	if (CooldownAnimacao >= CooldownAnimacaoMax)
		CooldownAnimacao = 0.f;
}

void Passaro::salvar()
{
	if (!this->getDesalocavel())
	{
		ofstream gravadorPassaro("saves/Passaros.dat", ios::app);

		if (!gravadorPassaro)
			cout << "Erro Gravar Passaro." << endl;

		gravadorPassaro << this->getVida() << ' '
			<< this->getPosicaoX() << ' '
			<< this->getPosicaoY() << ' '
			<< this->limiteXDir << ' '
			<< this->limiteXEsq << ' '
			<< this-> CooldownAtaque << endl;

		gravadorPassaro.close();
	}
}

