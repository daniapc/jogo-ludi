#include "Jogador.h"
#include "Fase.h"

Jogador::Jogador():Personagem()
{
}

Jogador::~Jogador()
{
}

/*
void Jogador::setPontuacao(int pontuacao)
{
	Pontuacao = pontuacao;
}

int Jogador::getPontuacao()
{
	return Pontuacao;
}
*/

void Jogador::inicializa()
{
	CooldownAtaque = 0.f;
	CooldownAtaqueMax = 500.f;
	Amigavel = true;
	colidePlataforma = true;
	Neutralizavel = true;
	CooldownInvencibilidade = 0;
	CooldownInvencibilidadeMax = -1;
}

void Jogador::colidir()
{
}

void Jogador::atualiza(float deltaTempo)
{
	Movimento.x = 0.f;

	if (sf::Keyboard::isKeyPressed(Direita))
	{
		Movimento.x += Velocidade;
		direita = true;
	}
	if (sf::Keyboard::isKeyPressed(Esquerda))
	{
		Movimento.x -= Velocidade;
		direita = false;
	}
	if (podePular && sf::Keyboard::isKeyPressed(Pulo))
	{
		podePular = false;
		Movimento.y = -sqrt(2 * 981.f * alturaPulo);
	}
	if (sf::Keyboard::isKeyPressed(Atira) && this->podeAtacar())
	{
		atiraProjetil();
	}

	Movimento.y += 981.f * deltaTempo;
	CooldownAtaque++;

	this->movimenta(Movimento * deltaTempo);
}

void Jogador::setTeclas(sf::Keyboard::Key direita, sf::Keyboard::Key esquerda, sf::Keyboard::Key pulo, sf::Keyboard::Key atira)
{
	Direita = direita;
	Esquerda = esquerda;
	Pulo = pulo;
	Atira = atira;
}

void Jogador::setFaseAtual(Fase* faseatual)
{
	faseAtual = faseatual;
}

void Jogador::atiraProjetil()
{
	Projetil* novo = NULL;
	novo = new Projetil();
	novo->setDesalocavel(false);

	if (direita)
	{
		novo->setPosicao(sf::Vector2f(this->getPosicao().x + this->getDimensoes().x / 2, this->getPosicao().y));
		novo->setVelocidade(sf::Vector2f(600.f, 0.f));
	}
	else
	{
		novo->setPosicao(sf::Vector2f(this->getPosicao().x - this->getDimensoes().x / 2, this->getPosicao().y));
		novo->setVelocidade(sf::Vector2f(-600.f, 0.f));
	}
	novo->setDimensoes(sf::Vector2f(10.f, 10.f));
	novo->setOrigem();
	novo->setJanela(Janela);
	novo->setAmigavel(true);

	faseAtual->incluaProjetil(novo); //Incluído na fase
}


