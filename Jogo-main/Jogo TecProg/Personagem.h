#pragma once
#include "stdafx.h"
#include "Entidade.h"

class Personagem : public Entidade   
{
protected:
	int Vida;
	float Velocidade;
	bool olharDireita;
	bool Amigavel, colidePlataforma;
	float CooldownAtaque, CooldownAtaqueMax;
	int Neutralizavel;

public:
	Personagem();
	~Personagem();

	void setOlhaDireita(bool olhardireita);
	bool getOlharDireita();
	void setColidePlataforma(bool colideplataforma);
	bool getColidePlataforma();
	void setVida(int vida);
	int getVida();
	void setAmigavel(bool amigavel);
	bool getAmigavel();
	float getVelocidade();
	void setCooldownAtaque(float cooldownataque);
	void setMovimentoX(float movimentox);
	void setMovimentoY(float movimentoy);
	void setVelocidade(float velocidade);

	bool podeAtacar();

	virtual void setPodePular(bool podepular);
	virtual bool podeMorrer();

	virtual void salvar() = 0;
	virtual void atualiza(float deltaTempo) = 0;
	virtual void colidir(Personagem* personagem);
};

