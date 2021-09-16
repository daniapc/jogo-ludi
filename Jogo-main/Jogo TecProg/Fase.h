#pragma once
#include "stdafx.h"
#include "Ente.h"
#include "Plataforma.h"
#include "GerenciadorColisoes.h"
#include "Obstaculo.h"
#include "Espinho.h"
#include "Estatico.h"
#include "ListaEntidades.h"
#include "ListaPersonagens.h"
#include "Projetil.h"
#include "Cenario.h"

class Jogo;
class Jogador;

class Fase : public Ente
{
protected:
	Cenario Background;
	Jogador* pJogador1;
	Jogador* pJogador2;
	Jogo* pJogo;

	GerenciadorColisoes gerenciadorColisoes;
	ListaEntidades listaEntidades;
	ListaPersonagens listaPersonagens;
	
public:
	Fase();
	virtual ~Fase();

	void setJogo(Jogo* pjogo);
	Jogo* getJogo() const;
	void setJogador1(Jogador* pJogador1);
	Jogador* getJogador1() const;
	void setJogador2(Jogador* pJogador2);
	Jogador* getJogador2() const;

	void criaObstaculo(Entidade* pentidade, float dimx, float dimy, float posx, float posy, const string textura);
	void criaInimigo(Personagem* ppersonagem, float dimx, float dimy, float posx, float posy, const string textura);
	void criaBordas();


	void atualizaView();
	void incluaProjetil(Projetil* projetil);
	void salvar();

	void recuperarProjeteis(Fase* fase);
	void recuperarEstaticos(bool Quintal, const string textura = "");
	void recuperarEspinhos(const string textura = "");
	void recuperarTeias();
	
	virtual void setChefaoMorreu(bool chefaomorreu);

	virtual void inicializa() = 0;
	virtual void atualiza(float deltaTempo) = 0;
	virtual void criaPlataformas() = 0;
};

