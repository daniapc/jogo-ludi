#pragma once
#include "Inimigo.h"
#include "Atirador.h"
//#include "Fase.h"

class Fase;
//
class Chefao : public Inimigo, public Atirador
{
private:

public:
	Chefao();
	~Chefao();

	void atiraProjeteis();

	void colidir(Personagem* personagem);
	void atualiza(float deltaTempo);
	void salvar();
};

