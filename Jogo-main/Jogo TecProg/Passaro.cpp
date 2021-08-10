#include "Passaro.h"
#include "Fase.h"

Passaro::Passaro():Inimigo()
{
}

Passaro::~Passaro()
{
}

void Passaro::setLimiteXEsq(float limesq)
{
	limiteXEsq = limesq;
}

void Passaro::setLimiteXDir(float limdir)
{
	limiteXDir = limdir;
}

void Passaro::colidir(Personagem* personagem)
{
	if (personagem->getAmigavel())
		cout << "Colidiu com Passaro!" << endl;
}

void Passaro::inicializa()
{
	Neutralizavel = true;
	Amigavel = false;
	CooldownAtaque = 0.f;
	CooldownAtaqueMax = 2.f;
	CooldownInvencibilidade = 0;
	CooldownInvencibilidadeMax = -1;
	limiteXEsq = getPosicao().x;
	limiteXDir = getPosicao().x + 300;
}

void Passaro::setFaseAtual(Fase* faseatual)
{
	faseAtual = faseatual;
}

void Passaro::atualiza(float deltaTempo)
{
	if (Desalocavel)
	{
		this->setDimensoes(sf::Vector2f(0.f, 0.f));
		this->setVelocidade(0.f);
		this->setPosicao(sf::Vector2f(0.f, 0.f));
		/*
		Jogador::setPontuacao(Jogador::getPontuacao() + 1);
		cout << "Score: " << Jogador::getPontuacao() << endl;
		*/
	}

	Movimento = sf::Vector2f(0.f, 0.f);
	sf::Vector2f posicao = getPosicao();

	if (posicao.x <= limiteXEsq)
		olharDireita = true;
	else if (posicao.x >= limiteXDir)
		olharDireita = false;
	if (olharDireita && posicao.x < limiteXDir)
		Movimento.x += Velocidade;
	else if (!olharDireita && posicao.x > limiteXEsq)
		Movimento.x -= Velocidade;

	this->movimenta(Movimento * deltaTempo);
	srand(time(NULL));

	CooldownAtaque += deltaTempo;

	if (!Desalocavel && this->podeAtacar())
		this->atiraProjetil();
}

void Passaro::atiraProjetil()
{
	Projetil* novo = NULL;

	if (faseAtual->getPiscinaProjeteis().empty()) {
		novo = new Projetil();
	}
	else {
		novo = faseAtual->getPiscinaProjeteis().back();
		faseAtual->getPiscinaProjeteis().pop_back();
	}

	float deltax = faseAtual->getFazendeira()->getPosicao().x - this->getPosicao().x;
	float deltay = faseAtual->getFazendeira()->getPosicao().y - this->getPosicao().y;
	float modulo = sqrt(deltax*deltax + deltay*deltay);

	if (olharDireita)
	{
		novo->setPosicao(sf::Vector2f(this->getPosicao().x + this->getDimensoes().x / 2, this->getPosicao().y));
		novo->setVelocidade(sf::Vector2f(400 * deltax / modulo, 400 * deltay / modulo));
	}
	else
	{
		novo->setPosicao(sf::Vector2f(this->getPosicao().x - this->getDimensoes().x / 2, this->getPosicao().y));
		novo->setVelocidade(sf::Vector2f(400 * deltax / modulo, 400 * deltay / modulo));
	}
	novo->setDimensoes(sf::Vector2f(10.f, 10.f));
	novo->setOrigem();
	novo->setJanela(Janela);
	novo->setAmigavel(false);
	novo->setDesalocavel(false);
	novo->setFaseAtual(faseAtual);
	novo->setNaPiscina(false);

	if (faseAtual->getPiscinaProjeteis().empty())
		faseAtual->incluaProjetil(novo); //Incluído na fase
}

void Passaro::salvar()
{
	if (!this->getDesalocavel())
	{
		ofstream gravadorPassaro("saves/Passaros.dat", ios::app);

		if (!gravadorPassaro)
			cout << "Erro." << endl;

		gravadorPassaro << this->getVida() << ' '
			<< this->getPosicao().x << ' '
			<< this->getPosicao().y << ' '
			<< this->getMovimento().x << ' '
			<< this->getMovimento().y << ' '
			<< this->limiteXDir << ' '
			<< this->limiteXEsq << ' '
			<< this-> CooldownAtaque << endl;

		gravadorPassaro.close();
	}
}

