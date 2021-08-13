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

	virtual void inicializa() = 0;
	virtual void atualiza(float deltaTempo);
	virtual void colidir();

	virtual bool podeMorrer();
	void setCooldownAtaque(float cooldownataque);
	void setOlhaDireita(bool olhardireita);
	bool getOlharDireita();
	void setColidePlataforma(bool colideplataforma);
	bool getColidePlataforma();
	void setVida(int vida);
	int getVida();
	void setAmigavel(bool amigavel);
	bool getAmigavel();
	bool podeAtacar();
	void setMovimentoX(float movimentox);
	void setMovimentoY(float movimentoy);
	void setVelocidade(float velocidade);
	float getVelocidade();
	virtual void setPodePular(bool podepular);
	virtual void salvar() = 0;
};

