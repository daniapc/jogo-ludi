#include "Chefao.h"
#include "Fase.h"

Chefao::Chefao(): Inimigo(), Atirador(), EstadoChefao(0)
{
	CooldownAtaqueMax = 2.0f;
	this->setVida(666);
	this->setVelocidade(50.f);
	this->setColidePlataforma(false);
	this->setTexturaProjetil("Projeteis_8", "Projeteis_9");

}

Chefao::~Chefao()
{
}

void Chefao::colidir(Personagem* personagem)
{
	if (personagem->getAmigavel())
	{
		personagem->setVida(personagem->getVida()-1);
	}
}

void Chefao::atualiza(float deltaTempo)
{
	switch (EstadoChefao){
		case 0:
			atualizaEstado0(deltaTempo);
			break;
		case 1:
			atualizaEstado1(deltaTempo);
			break;
		case 2:
			atualizaEstado2(deltaTempo);
			if (Desalocavel)
				faseAtual->setChefaoMorreu(true);
			break;
	}
}

void Chefao::atiraProjeteis()
{
	atiraProjetilHorizontal(this, getPosicaoY() );
	atiraProjetilHorizontal(this, getPosicaoY()  +  getDimensoesY() /2);
	atiraProjetilHorizontal(this, getPosicaoY()  - getDimensoesY() /2);
	atiraProjetilDirecionado(this, LADO_PROJETIL*2);
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
			<< this->getPosicaoY() << ' '
			<< this->CooldownAtaque << ' '
			<< EstadoChefao << endl;

		gravadorChefao.close();
	}
}

void Chefao::setEstado(int estado)
{
	EstadoChefao = estado;
}

void Chefao::atualizaEstado0(float deltaTempo)
{
	float posJogador2 = 0;
	if (faseAtual->getJogador2() != NULL)
		posJogador2 = faseAtual->getJogador2()->getPosicaoX();
	if (faseAtual->getJogador1()->getPosicaoX() >= COMPRIMENTO_CENARIO -550 
		|| posJogador2 >= COMPRIMENTO_CENARIO - 550) {
		EstadoChefao = 1;
		this->setDimensoes(COMPRIMENTO_CHEFAO, ALTURA_CHEFAO);
		this->setSubTextura("textures/Bicho_Papao.png");
		this->setPosicao(COMPRIMENTO_CENARIO - 200.f, ALTURA_RESOLUCAO - ALTURA_CHEFAO/2 - ALTURA_PLATAFORMA);	
		this->setVida(20);
	}
}

void Chefao::atualizaEstado1(float deltaTempo)
{

	MovimentoX = 0.f;
	MovimentoY = 0.f;;
	float modulo, deltax;

	float deltax1 = faseAtual->getJogador1()->getPosicaoX() - this->getPosicaoX();

	if (faseAtual->getJogador2() != NULL) {
		float deltax2 = faseAtual->getJogador2()->getPosicaoX() - this->getPosicaoX();
		if (deltax1 < deltax2) {
			modulo = sqrt(deltax1 * deltax1);
			deltax = deltax1;
		}
		else {
			modulo = sqrt(deltax2 * deltax2);
			deltax = deltax2;
		}
	}
	else {
		modulo = sqrt(deltax1 * deltax1);
		deltax = deltax1;
	}
	if (modulo != 0.f)
		MovimentoX += Velocidade * deltax / modulo;
	if (MovimentoX > 0) {
		olharDireita = true;
		if (CooldownAtaque >= CooldownAtaqueMax / 4)
			("Bicho_Papao_4");
	}
	else {
		olharDireita = false;
		if (CooldownAtaque >= CooldownAtaqueMax / 2)
			setSubTextura("textures/Bicho_Papao.png");
	}
	CooldownAtaque += deltaTempo;
	if (this->podeAtacar())
	{
		 if(olharDireita)
			setSubTextura("Bicho_Papao_5");
		else
			setSubTextura("Bicho_Papao_2");
		this->atiraProjeteis();
		CooldownAtaque = 0;
	}
	this->movimenta(MovimentoX * deltaTempo, MovimentoY * deltaTempo);

	if (getVida() <= 10) {
		EstadoChefao = 2;
		CooldownAtaqueMax /= 4.f;
		setPosicao(COMPRIMENTO_CENARIO / 2, ALTURA_CHEFAO);
	}
}

void Chefao::atualizaEstado2(float deltaTempo)
{
	float deltax = faseAtual->getJogador1()->getPosicaoX() - this->getPosicaoX();
	
	if (this->podeAtacar())
	{
		this->atiraProjetilDirecionado(this, LADO_PROJETIL * 3);
		CooldownAtaque = 0;
	}

	if (deltax >= 0) {
		olharDireita = true;
		setSubTextura("Bicho_Papao_6");
	}
	else {
		olharDireita = false;
		setSubTextura("Bicho_Papao_3");
	}

	CooldownAtaque += deltaTempo;
}
