#pragma once
#include "Entidade.h"
#include "Personagem.h"

class Fase;

class Projetil : public Entidade
{
private:

	float VelocidadeX, VelocidadeY;
	string Textura;
	bool Amigavel;
	Fase* faseAtual;

public:
	Projetil();
	~Projetil();

	void setAmigavel(bool amigavel);
	bool getAmigavel() const;
	void colidir(Personagem* personagem);
	void atualiza(float deltaTempo);
	void setVelocidade(float velx, float vely);

	void setTextura(string textura);

	float getVelocidadeX() const;
	float getVelocidadeY() const;

	void setFaseAtual(Fase* faseatual);
	void salvar();
};

