#pragma once
#include "Inimigo.h"
#include "Atirador.h"

class Fase;

class Chefao : public Inimigo, public Atirador
{
private:
	int EstadoChefao;

public:
	Chefao();
	~Chefao();

	void atiraProjeteis();

	void colidir(Personagem* personagem);
	void atualiza(float deltaTempo);
	void salvar();

	void setEstado(int estado);
	void atualizaEstado0(float deltaTempo);
	void atualizaEstado1(float deltaTempo);
	void atualizaEstado2(float deltaTempo);
};

