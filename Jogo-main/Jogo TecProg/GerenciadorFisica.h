#pragma once
#include "Entidade.h"
#include "Personagem.h"
#include "Plataforma.h"
#include "Jogador.h"
#include "Espinho.h"
#include "Fantasma.h"

class GerenciadorFisica
{
private:
	Jogador* pFazendeira;
	vector <Plataforma*> ListaPlataformas;
	vector <Personagem*> ListaPersonagens;
	vector <Fantasma*> ListaFantasmas;
	vector <Espinho*> ListaEspinhos;

public:
	GerenciadorFisica();
	~GerenciadorFisica();
	
	void setFazendeira(Jogador* fazendeira);
	void incluaPlataforma(Plataforma* plataforma);
	void incluaEspinho(Espinho* espinho);
	void incluaFantasma(Fantasma* fantasma);
	void incluaPersonagem(Personagem* personagem);

	void checaColisoes();
	void checaColisao(Personagem* personagem, Entidade* entidade);
	void checaColisaoParede(Personagem* personagem);
};

