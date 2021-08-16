#pragma once
#include "stdafx.h"
#include "Ente.h"

class Personagem;
class GerenciadorGrafico;

class Entidade : public Ente
{
protected:

	float MovimentoX, MovimentoY;
	bool Desalocavel;

	int IdCorpo;
	static int IdCorpoAtual;
	
public:
	Entidade();
	virtual ~Entidade();

	void setDimensoes(float x, float y);
	float getDimensoesX() const;
	float getDimensoesY() const;
		
	void setPosicao(float x, float y);
	float getPosicaoX() const;
	float getPosicaoY() const;

	void setMovimento(float x, float y);
	float getMovimentoX() const;
	float getMovimentoY() const;

	void setDesalocavel(bool desalocavel);
	bool getDesalocavel() const;

	void incrementaIdCorpoAtual();
	void setId(int id);
	int getIdCorpoAtual() const;
	int getId() const;

	void setSubTextura(string subtext);

	void movimenta(float movimentox, float movimentoy);
	void desenhar();

	virtual void colidir(Personagem* personagem);
	virtual void atualiza(float deltaTempo);
	virtual void salvar();
};

