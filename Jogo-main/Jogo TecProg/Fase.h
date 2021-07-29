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
	virtual void criaEntidades();
	virtual void desenhar() = 0;

	void atualiza();

	void setJanela(sf::RenderWindow* janela);
	void setView(sf::View* view);
};

