#include "Chefao.h"
#include "Fase.h"

Chefao::Chefao(): Inimigo(), Atirador()
{
	CooldownAtaqueMax = 1;
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

void Chefao::inicializa()
{
}

/*
void Chefao::setFaseAtual(Fase* faseatual)
{
	faseAtual = faseatual;
}

*/

void Chefao::atualiza(float deltaTempo)
{
	if (Desalocavel)
		faseAtual->setChefaoMorreu(true);

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

	if (this->podeAtacar())
	{
		this->atiraProjeteis();
		CooldownAtaque = 0;
	}

	this->movimenta(Movimento * deltaTempo);
}




void Chefao::atiraProjeteis()
{
	atiraProjetilHorizontal(this, getPosicao().y);
	atiraProjetilHorizontal(this, getPosicao().y +  getDimensoes().y/2);
	atiraProjetilHorizontal(this, getPosicao().y - getDimensoes().y/2);
	atiraProjetilDirecionado(this, 20.0f);
	/*
	atiraProjetil2();
	atiraProjetil(this->getPosicao().y + this->getDimensoes().y / 2);
	atiraProjetil(this->getPosicao().y);
	atiraProjetil(this->getPosicao().y - this->getDimensoes().y / 2);
	*/

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
			<< this->CooldownAtaque << endl;

		gravadorChefao.close();
	}
}
