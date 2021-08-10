#pragma once
#include "stdafx.h"
#include "Entidade.h"

class Personagem : public Entidade   
{
protected:
	int Vida;
	float Velocidade, alturaPulo;
	bool podePular,olharDireita;
	bool Amigavel, colidePlataforma;
	float CooldownAtaque, CooldownAtaqueMax;
	float CooldownInvencibilidade, CooldownInvencibilidadeMax;
	int Neutralizavel;

public:
	Personagem();
	~Personagem();

	virtual void inicializa() = 0;
	virtual void atualiza(float deltaTempo);
	virtual void colidir();

	bool podeMorrer();
	void setCooldownAtaque(float cooldownataque);
	void setOlhaDireita(bool olhardireita);
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
	void setPodePular(bool podepular);
	void setAlturaPulo(float alturapulo);
	float getVelocidade();
	virtual void salvar() = 0;
};

