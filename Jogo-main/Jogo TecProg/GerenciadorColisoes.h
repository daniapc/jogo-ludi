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

class GerenciadorColisoes
{
private:
	ListaEntidades* plistaEntidades;
	ListaPersonagens* plistaPersonagens;

public:
	GerenciadorColisoes();
	~GerenciadorColisoes();
	
	void setListaEntidades(ListaEntidades* plistaentidades);
	void setListaPersonagens(ListaPersonagens* plistapersonagens);

	void incluaEntidade(Entidade* entidade);

	void checaColisoes();
	void checaColisao(Personagem* personagem, Entidade* entidade);
};

