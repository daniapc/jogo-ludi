#pragma once
#include "stdafx.h"
#include "Ente.h"

class Personagem;
class GerenciadorGrafico;

class Entidade : public Ente
{
protected:
	float DimensaoX, DimensaoY;

	float MovimentoX, MovimentoY;

	float PosicaoX, PosicaoY;

	string Textura;

	int IdCorpo;
	static int IdAtual;
	bool Desalocavel;
	
public:
	Entidade();
	virtual ~Entidade();

	void setDimensoes(float x, float y);

	float getDimensoesX();
	float getDimensoesY();
		
;
	void setPosicao(float x, float y);
	float getPosicaoX();
	float getPosicaoY();

	float getMovimentoX();
	float getMovimentoY();

	void setDesalocavel(bool desalocavel);
	bool getDesalocavel();

	void setTextura(const string textura);

	void incrementaIdAtual();
	void setId(int id);
	int getIdAtual();
	int getId();

	void movimenta(float movimentox, float movimentoy);
	void desenhar();

	virtual void colidir(Personagem* personagem);
	virtual void atualiza(float deltaTempo);
	virtual void salvar();
};

