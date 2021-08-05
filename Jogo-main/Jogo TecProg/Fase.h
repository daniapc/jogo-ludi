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

class Fase : public Ente
{
protected:
	Entidade Cenario;
	Jogador Fazendeira;
	GerenciadorFisica gerenciadorFisica;
	ListaEntidades listaEntidades;

	sf::View* View;

public:
	Fase();
	virtual ~Fase();

	virtual void inicializa() = 0;
	virtual void desenhar() = 0;

	virtual void criaEntidades();
	virtual void criaPlataformas() = 0;

	//Cria objetos que estão em ambas as fases
	void criaPlataforma(sf::Vector2f posicao,sf::Vector2f tamanho = sf::Vector2f(COMPRIMENTO_PLATAFORMA,ALTURA_PLATAFORMA), const string textura = "textures/Plataforma_meio.png");
	void criaChao();
	void criaEstatico(sf::Vector2f posicao);
	void criaEspinho(sf::Vector2f posicao);

	Jogador& getFazendeira();
	GerenciadorFisica getGerenciadorFisica();

	virtual void atualiza(float deltaTempo);
	void atualizaView();

	void incluaProjetil(Projetil* projetil);
	void setView(sf::View* view);
};

