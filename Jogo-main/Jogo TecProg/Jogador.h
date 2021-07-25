#pragma once
#include "stdafx.h"
#include "Entidade.h"

class Jogador : public Entidade
{
private:

public:
	Jogador();
	~Jogador();
	
	void Inicializa(sf::Vector2f dimensoes, sf::Vector2f posicao);

};

