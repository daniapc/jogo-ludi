#pragma once
#include "Fase.h"
#include "Espinho.h"
#include "Fantasma.h"
#include "Estatico.h"
#include "GerenciadorFisica.h"
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

	void setChefaoMorreu(bool chefaomorreu);

	void recuperar();
	void recuperarFantasmas();
	void recuperarChefao();
	void recuperarPorta();

	void criaFantasma(sf::Vector2f posicao);
	void criaChefao(sf::Vector2f posicao);
	void criaPlataformas();
};

