#pragma once
#include "stdafx.h"
#include "Plataforma.h"
#include "Jogador.h"

class Fase
{
protected:
	Entidade Cenario;
	Jogador Fazendeira;
	vector <Entidade*> ListaEntidades;
	vector <Plataforma*> ListaPlataformas;

	sf::RenderWindow* Janela;
	sf::View* View;

public:
	Fase();
	virtual ~Fase();

	virtual void inicializa() = 0;
	virtual void desenhar() = 0;

	virtual void criaEntidades();
	void criaPlataforma(sf::Vector2f posicao,sf::Vector2f tamanho = sf::Vector2f(32.f,32.f), const string textura = "ground_top.png");

	Jogador& getFazendeira();
	void atualiza();
	void atualizaView();
	virtual void checaColisoes() = 0;
	void checaColisao(Personagem* personagem, Entidade* entidade);

	void setJanela(sf::RenderWindow* janela);
	void setView(sf::View* view);
};

