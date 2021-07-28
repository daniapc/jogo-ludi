#pragma once
#include "Inimigo.h"

class Passaro : public Inimigo
{
private:

public:
	Passaro();
	~Passaro();

	void movimenta();
	void atiraProjetil();
};

