#pragma once
#include "stdafx.h"
#include "Entidade.h"
#include "Personagem.h"
#include "Plataforma.h"
#include "Jogador.h"
#include "Espinho.h"
#include "Teia.h"
#include "Passaro.h"
#include "Fantasma.h" 
//#include "ListaEntidades.h"

class GerenciadorFisica
{
private: //Remover maioria, corrigir teia, remover sets e gets inuteis
	Jogador* pFazendeira;
	//vector <Plataforma*> ListaPlataformas;
	vector <Personagem*> ListaPersonagens;
	//vector <Projetil*> ListaProjeteis;
	//ListaEntidades* listaEntidades;
	vector <Entidade*> ListaEntidades;

public:
	GerenciadorFisica();
	~GerenciadorFisica();
	
	//void setListaEntidades(ListaEntidades* listaentidades);
	void setFazendeira(Jogador* fazendeira);
	//void incluaPlataforma(Plataforma* plataforma);
	void incluaPersonagem(Personagem* personagem);
	//void incluaProjetil(Projetil* projetil);
	void incluaEntidade(Entidade* entidade);

	void checaColisoes();
	void checaColisao(Personagem* personagem, Entidade* entidade);
	void checaColisaoParede(Personagem* personagem);
};

