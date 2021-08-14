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
	//Entidade Cenario;
	Jogador* pFazendeira;
	Jogador* pBruxo;
	Jogo* pJogo;
	//sf::View* pView; //pGerenciadorGrafico

	GerenciadorColisoes gerenciadorColisoes;
	ListaEntidades listaEntidades;
	ListaPersonagens listaPersonagens;
	
public:
	Fase();
	virtual ~Fase();

	void setJogo(Jogo* pjogo);
	Jogo* getJogo();
	void setFazendeira(Jogador* pfazendeira);
	Jogador* getFazendeira();
	void setBruxo(Jogador* pbruxo);

	void criaObstaculo(Entidade* pentidade, float dimx, float dimy, float posx, float posy, const string textura);
	void criaInimigo(Personagem* ppersonagem, float dimx, float dimy, float posx, float posy, const string textura);
	void criaBordas();

	//Cria objetos que estão em ambas as fases

	void atualizaView();
	void incluaProjetil(Projetil* projetil);
	void salvar();

	void recuperarProjeteis(Fase* fase, const string textura = "");
	void recuperarEstaticos(const string textura = "");
	void recuperarEspinhos(const string textura = "");
	void recuperarTeias();
	
	virtual void setChefaoMorreu(bool chefaomorreu);

	virtual void inicializa() = 0;
	virtual void atualiza(float deltaTempo) = 0;
	virtual void criaPlataformas() = 0;
};

