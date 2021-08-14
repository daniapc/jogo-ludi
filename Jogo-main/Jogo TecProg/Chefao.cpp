#include "Chefao.h"
#include "Fase.h"

Chefao::Chefao(): Inimigo(), Atirador()
{
	CooldownAtaqueMax = 1;
	this->setVida(3);
	this->setVelocidade(50.f);
	this->setColidePlataforma(false);
}

Chefao::~Chefao()
{
}

void Chefao::colidir(Personagem* personagem)
{
	if (personagem->getAmigavel())
	{
		cout << "Colidiu chefao" << endl;
		personagem->setVida(0);
		personagem->setDesalocavel(true);
	}
}

void Chefao::atualiza(float deltaTempo)
{
	if (Desalocavel)
		faseAtual->setChefaoMorreu(true);

	MovimentoX = 0.f;
	MovimentoY = 0.f;

	cout << "aqui" << endl;
	float deltax = faseAtual->getFazendeira()->getPosicaoX()  - this->getPosicaoX() ;
	float modulo = sqrt(deltax*deltax);

	if (modulo != 0.f)
		MovimentoX += Velocidade * deltax / modulo;
	//Movimento.y += 981.f * deltaTempo;
	
	if (MovimentoX > 0)
		olharDireita = true;
	else
		olharDireita = false;

	CooldownAtaque += deltaTempo;

	if (this->podeAtacar())
	{
		this->atiraProjeteis();
		CooldownAtaque = 0;
	}

	this->movimenta(MovimentoX * deltaTempo, MovimentoY * deltaTempo);
}

void Chefao::atiraProjeteis()
{
	atiraProjetilHorizontal(this, getPosicaoY() );
	atiraProjetilHorizontal(this, getPosicaoY()  +  getDimensoesY() /2);
	atiraProjetilHorizontal(this, getPosicaoY()  - getDimensoesY() /2);
	atiraProjetilDirecionado(this, 20.0f);
}

void Chefao::salvar()
{
	if (!this->getDesalocavel())
	{
		ofstream gravadorChefao("saves/Chefao.dat", ios::app);

		if (!gravadorChefao)
			cout << "Erro Gravar Chefao." << endl;

		gravadorChefao << this->getVida() << ' '
			<< this->getPosicaoX() << ' '
			<< this->getPosicaoY()  << ' '
			<< this->CooldownAtaque << endl;

		gravadorChefao.close();
	}
}
