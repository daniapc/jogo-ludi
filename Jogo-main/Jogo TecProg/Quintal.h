#pragma once
#include "Fase.h"
#include "Passaro.h"

class Quintal : public Fase
{
private:
	vector <Passaro*> ListaPassaros;

public:
	Quintal();
	~Quintal();

	void inicializa();
	void desenhar();
	void criaPassaro();
	
};

