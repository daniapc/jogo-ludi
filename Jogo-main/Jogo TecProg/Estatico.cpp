#include "Estatico.h"

Estatico::Estatico():
	Inimigo(),
	CooldownInvencibilidadeMax(3.0f),
	CooldownInvencibilidade(0.0f)
{
	CooldownAtaqueMax = 1.0f;
}

Estatico::~Estatico()
{
}

bool Estatico::podeMorrer()
{
	if (CooldownInvencibilidade >= CooldownInvencibilidadeMax)
		CooldownInvencibilidade = 0;
	if ((CooldownInvencibilidade) / (CooldownInvencibilidadeMax) <= 0.5)
		return true;
	else
		return false;
}

void Estatico::atualiza(float deltaTempo)
{
	if (podeMorrer()) {
		this->setDimensoes(sf::Vector2f(COMPRIMENTO_ESTATICO + 20.f, ALTURA_ESTATICO + 2 * 6.3f));
		this->setOrigem();
	}
	else {
		this->setDimensoes(sf::Vector2f(COMPRIMENTO_ESTATICO, ALTURA_ESTATICO));
		this->setOrigem();
	}

	Movimento.y += 981.f * deltaTempo;
	this->movimenta(Movimento * deltaTempo);

	CooldownAtaque += deltaTempo;
	CooldownInvencibilidade += deltaTempo;
}

void Estatico::colidir(Personagem* personagem)
{
	if (personagem->getAmigavel() && this->podeAtacar())
	{
		cout << "Colidiu Estático!" << endl;
		CooldownAtaque = 0;
		personagem->setVida(personagem->getVida() - 1);
		if (personagem->getVida() <= 0)
			personagem->setDesalocavel(true);
	}
}

void Estatico::inicializa()
{	
}

void Estatico::movimenta(sf::Vector2f movimento)
{
	Corpo.move(movimento);
}

void Estatico::salvar()
{
	if (!this->getDesalocavel())
	{
		ofstream gravadorEstatico("saves/Estaticos.dat", ios::app);

		if (!gravadorEstatico)
			cout << "Erro." << endl;

		gravadorEstatico << this->getVida() << ' '
			<< this->getPosicao().x << ' '
			<< this->getPosicao().y << ' '
			<< this->CooldownAtaque << endl;

		gravadorEstatico.close();
	}
}
