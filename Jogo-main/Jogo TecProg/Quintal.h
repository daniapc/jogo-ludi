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

	void Inicializa();
	void desenhar();
	void criaPassaro();
	
};

