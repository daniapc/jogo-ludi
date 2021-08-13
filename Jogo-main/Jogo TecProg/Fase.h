#pragma once
#include "stdafx.h"
#include "Ente.h"
#include "Plataforma.h"
//#include "Jogador.h"
#include "GerenciadorFisica.h"
#include "Obstaculo.h"
#include "Espinho.h"
#include "Estatico.h"
#include "ListaEntidades.h"
#include "ListaPersonagens.h"
#include "Projetil.h"

class Jogo;
class Jogador;

class Fase : public Ente
{
protected:
	Entidade Cenario;
	Jogador* Fazendeira;
	Jogador* Bruxo;
	GerenciadorFisica gerenciadorFisica;
	ListaEntidades listaEntidades;
	ListaPersonagens listaPersonagens;

	//vector<Projetil*> PiscinaProjeteis;
	Jogo* jogo;

	sf::View* View;

public:
	Fase();
	virtual ~Fase();

	virtual void inicializa() = 0;
	virtual void desenhar() = 0;

	virtual void criaPlataformas() = 0;

	//Cria objetos que estão em ambas as fases
	void criaPlataforma(sf::Vector2f posicao, const string textura = "textures/Plataforma_meio.png");
	void criaPlataforma(sf::Vector2f posicao, const string textura, sf::Vector2f tamanho);
	void criaBordas();
	void criaEstatico(sf::Vector2f posicao, const string textura = "");
	void criaEspinho(sf::Vector2f posicao, const string textura = "");
	void criaTeia(sf::Vector2f posicao, const string textura = "");


	virtual void setChefaoMorreu(bool chefaomorreu);

	//vector<Projetil*>& getPiscinaProjeteis();
	Jogador* getFazendeira();
	GerenciadorFisica getGerenciadorFisica();
	void setFazendeira(Jogador* fazendeira);
	void setBruxo(Jogador* bruxo);

	virtual void atualiza(float deltaTempo);
	void atualizaView();

	//void incrementaPontuacao();
	void incluaProjetil(Projetil* projetil);
	void setView(sf::View* view);
	void salvar();

	void setJogo(Jogo* jg);
	Jogo* getJogo();

	void recuperarProjeteis();
	void recuperarEstaticos();
	void recuperarEspinhos();
	void recuperarTeias();
	//void recuperarJogadores();
};

