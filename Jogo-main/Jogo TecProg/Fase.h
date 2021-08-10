#pragma once
#include "stdafx.h"
#include "Ente.h"
#include "Plataforma.h"
#include "Jogador.h"
#include "GerenciadorFisica.h"
#include "Obstaculo.h"
#include "Espinho.h"
#include "Estatico.h"
#include "ListaEntidades.h"
#include "Projetil.h"

class Jogo;

class Fase : public Ente
{
protected:
	Entidade Cenario;
	Jogador* Fazendeira;
	Jogador* Bruxo;
	GerenciadorFisica gerenciadorFisica;
	ListaEntidades listaEntidades;
	vector<Projetil*> PiscinaProjeteis;
	Jogo* jogo;

	sf::View* View;

public:
	Fase();
	virtual ~Fase();

	virtual void inicializa() = 0;
	virtual void desenhar() = 0;

	virtual void criaEntidades();
	virtual void criaPlataformas() = 0;

	//Cria objetos que estão em ambas as fases
	void criaPlataforma(sf::Vector2f posicao, const string textura = "textures/Plataforma_meio.png" ,sf::Vector2f tamanho = sf::Vector2f(COMPRIMENTO_PLATAFORMA, ALTURA_PLATAFORMA));
	void criaChao();
	void criaEstatico(sf::Vector2f posicao, const string textura = "");
	void criaEspinho(sf::Vector2f posicao, const string textura = "");
	void criaTeia(sf::Vector2f posicao, const string textura = "");


	vector<Projetil*>& getPiscinaProjeteis();
	Jogador* getFazendeira();
	GerenciadorFisica getGerenciadorFisica();
	void setFazendeira(Jogador* fazendeira);
	void setBruxo(Jogador* bruxo);

	virtual void atualiza(float deltaTempo);
	void atualizaView();

	void incluaProjetil(Projetil* projetil);
	void setView(sf::View* view);
	void setJogo(Jogo* jg);
	void salvar();

	void recuperarEstaticos();
	void recuperarEspinhos();
	void recuperarTeias();
	void recuperarJogadores();
};

