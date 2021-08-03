#include "Fantasma.h"

Fantasma::Fantasma():Inimigo(),
	direita(true),
	cima(false)
{
	

}

Fantasma::~Fantasma()
{
}

void Fantasma::inicializa()
{
	limiteXEsq = getPosicao().x;
	limiteXDir = getPosicao().x + 200;
	limiteYBaixo = ALTURA_RESOLUCAO - (ALTURA_PLATAFORMA + ALTURA_FANTASMA/2);
	limiteYCima = DimensoesCorpo.y / 2;
}

void Fantasma::atualiza(float deltaTempo)
{
	Movimento = sf::Vector2f(0.f, 0.f);
	sf::Vector2f posicao = getPosicao();

	if (posicao.x <= limiteXEsq)
		direita = true;
	else if (posicao.x >= limiteXDir)
		direita = false;
	if (direita && posicao.x < limiteXDir)
		Movimento.x += Velocidade;
	else if (!direita && posicao.x > limiteXEsq)
		Movimento.x -= Velocidade;

	if (posicao.y >= limiteYBaixo)
		cima = true;
	else if (posicao.y <= limiteYCima)
		cima = false;
	if (cima && posicao.y > limiteYCima)
		Movimento.y -= Velocidade;
	else if (!cima && posicao.y < limiteYBaixo)
		Movimento.y += Velocidade;


	this->movimenta(Movimento * deltaTempo);
}
