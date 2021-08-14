#pragma once
#include "Fase.h"
#include "Espinho.h"
#include "Fantasma.h"
#include "Estatico.h"
#include "Chefao.h"
#include "Porta.h"

class Jogo;

class Quarto : public Fase
{
private:
	bool ChefaoMorreu;

public:
	Quarto();
	~Quarto();

	void inicializa();
	void desenhar();
	void atualiza(float deltaTempo);
	void limparTudo();

	void recuperar();
	void recuperarFantasmas();
	void recuperarChefao();

	void setChefaoMorreu(bool chefaomorreu);

	void criaPlataforma( float posx, float posy);
	void criaPlataformas();
};

