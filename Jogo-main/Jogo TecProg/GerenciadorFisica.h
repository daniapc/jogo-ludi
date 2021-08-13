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
#include "ListaEntidades.h"
#include "ListaPersonagens.h"

class GerenciadorFisica
{
private: //Mudar colisao parede
	ListaEntidades* listaEntidades;
	ListaPersonagens* listaPersonagens;

public:
	GerenciadorFisica();
	~GerenciadorFisica();
	
	void setListaEntidades(ListaEntidades* listaentidades);
	void setListaPersonagens(ListaPersonagens* listapersonagens);

	//void setFazendeira(Jogador* fazendeira); //
	void incluaEntidade(Entidade* entidade);

	void checaColisoes();
	void checaColisao(Personagem* personagem, Entidade* entidade);
	void checaColisaoParede(Personagem* personagem); //
};

