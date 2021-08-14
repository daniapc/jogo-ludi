#pragma once
#include "Entidade.h"
#include "Personagem.h"

class Fase;

class Projetil : public Entidade
{
private:

	float VelocidadeX, VelocidadeY;
	//sf::Vector2f Movimento;
	bool Amigavel;
	Fase* faseAtual;

public:
	Projetil();
	~Projetil();

	//void setMovimento(sf::Vector2f movimento);
	void setAmigavel(bool amigavel);
	bool getAmigavel();
	void colidir(Personagem* personagem);
	void atualiza(float deltaTempo);
	void setVelocidade(float velx, float vely);

	float getVelocidadeX();
	float getVelocidadeY();
	//sf::Vector2f getVelocidade();

	void setFaseAtual(Fase* faseatual);
	void salvar();
};

