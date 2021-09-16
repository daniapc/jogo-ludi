#include "Estatico.h"

Estatico::Estatico():
	Inimigo(),
	CooldownInvencibilidadeMax(4.0f)
{
	CooldownAtaqueMax = 1.0f;
	this->setVida(4);
	this->setVelocidade(100.f);
	CooldownInvencibilidade = (float)(rand() % 40) / 10;
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

	setSubTextura(SubTextura[0]);
	if (podeMorrer()) {
		this->setDimensoes(COMPRIMENTO_ESTATICO + 20.f, ALTURA_ESTATICO + 2 * 6.3);
		setSubTextura(SubTextura[2]);
	}
	else {
		this->setDimensoes(COMPRIMENTO_ESTATICO, ALTURA_ESTATICO);
		setPosicao(getPosicaoX(), getPosicaoY() + 3.f);
	}

	if (CooldownInvencibilidade >= CooldownInvencibilidadeMax*7/8)
		setSubTextura(SubTextura[1]);

	MovimentoY += 981.f * deltaTempo;
	this->movimenta(MovimentoX * deltaTempo, MovimentoY* deltaTempo);

	CooldownAtaque += deltaTempo;
	CooldownInvencibilidade += deltaTempo;
}

void Estatico::colidir(Personagem* personagem)
{
	if (personagem->getAmigavel() && this->podeAtacar())
	{
		CooldownAtaque = 0;
		personagem->setVida(personagem->getVida() - 1);
		if (personagem->getVida() <= 0)
			personagem->setDesalocavel(true);
	}
}
void Estatico::setTexturas(bool Quintal)
{
	if (Quintal) {
		SubTextura[0] = "textures/Monstro_Moita.png";
		SubTextura[1] = "Monstro_Moita_2";
		SubTextura[2] = "Monstro_Moita_3";
	}
	else {
		SubTextura[0] = "textures/Monstro_Roupas.png";
		SubTextura[1] = "Monstro_Roupas_2";
		SubTextura[2] = "Monstro_Roupas_3";
	}
}



void Estatico::salvar()
{
	if (!this->getDesalocavel())
	{
		ofstream gravadorEstatico("saves/Estaticos.dat", ios::app);

		if (!gravadorEstatico)
			cout << "Erro." << endl;

		gravadorEstatico << this->getVida() << ' '
			<< this->getPosicaoX() << ' '
			<< this->getPosicaoY() << ' '
			<< this->CooldownAtaque << endl;

		gravadorEstatico.close();
	}
}
