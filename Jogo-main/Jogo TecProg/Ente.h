#pragma once
#include "stdafx.h"
//#include "GerenciadorGrafico.h"

class GerenciadorGrafico;

class Ente
{
protected:
	GerenciadorGrafico* pGerenciadorGrafico;

public:
	Ente();
	virtual ~Ente();

	void setGerenciadorGrafico(GerenciadorGrafico* pgerenciadorgrafico);
};

