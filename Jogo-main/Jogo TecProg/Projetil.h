#pragma once
#include "Entidade.h"
#include "Personagem.h"
class Projetil : public Entidade
{
private:
	sf::Vector2f Velocidade;
	sf::Vector2f Movimento;
	bool Amigavel; //Se o projétil mata inimigo ou jogador.

public:
	Projetil();
	~Projetil();

	void setAmigavel(bool amigavel);
	bool getAmigavel();
	void colidir(Personagem* personagem);
	void atualiza(float deltaTempo);
	void movimenta(sf::Vector2f movimento);
	void setVelocidade(sf::Vector2f velocidade);
};

