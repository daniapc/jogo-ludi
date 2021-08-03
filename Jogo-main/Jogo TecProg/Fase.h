#pragma once
#include "stdafx.h"
#include "Ente.h"
#include "Plataforma.h"
#include "Jogador.h"
#include "GerenciadorFisica.h"
#include "ListaEntidades.h"

class Fase : public Ente
{
protected:
	Entidade Cenario;
	Jogador Fazendeira;
	GerenciadorFisica gerenciadorFisica;
	ListaEntidades listaEntidades;
	vector <Plataforma*> ListaPlataformas;

	sf::View* View;

public:
	Fase();
	virtual ~Fase();

	virtual void inicializa() = 0;
	virtual void desenhar() = 0;

	virtual void criaEntidades();
	virtual void criaPlataformas() = 0;
	void criaPlataforma(sf::Vector2f posicao,sf::Vector2f tamanho = sf::Vector2f(COMPRIMENTO_PLATAFORMA,ALTURA_PLATAFORMA), const string textura = "ground_top.png");
	void criaChao();

	Jogador& getFazendeira();
	GerenciadorFisica getGerenciadorFisica();

	virtual void atualiza(float deltaTempo);
	void atualizaView();

	void setView(sf::View* view);
};

