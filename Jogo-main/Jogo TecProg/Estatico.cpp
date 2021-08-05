#include "Estatico.h"

Estatico::Estatico()
{
}

Estatico::~Estatico()
{
}

void Estatico::atualiza(float deltaTempo)
{
	if (Desalocavel)
	{
		this->setDimensoes(sf::Vector2f(0.f, 0.f));
		this->setVelocidade(0.f);
	}

	Movimento.y += 981.f * deltaTempo;
	this->movimenta(Movimento * deltaTempo);

	CooldownAtaque++;
	CooldownInvencibilidade++;
}

void Estatico::colidir(Personagem* personagem)
{
	if (personagem->getAmigavel() && this->podeAtacar())
		cout << "Colidiu Estático!" << endl;
		//Dar dano
}

void Estatico::inicializa()
{
	Amigavel = false;
	Neutralizavel = 1;
	CooldownAtaque = 0.0f;
	CooldownAtaqueMax = 3000.0f;
	CooldownInvencibilidade = 0.0f;
	CooldownInvencibilidadeMax = 10000.0f;
}

void Estatico::movimenta(sf::Vector2f movimento)
{
	Corpo.move(movimento);
}
