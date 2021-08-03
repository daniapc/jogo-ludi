#pragma once
#include "Inimigo.h"

class Passaro : public Inimigo
{
private:

public:
	Passaro();
	~Passaro();

	void inicializa();
	void atiraProjetil();
};

