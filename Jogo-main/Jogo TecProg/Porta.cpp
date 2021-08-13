#include "Porta.h"
#include "Jogo.h"


Porta::Porta():
	Obstaculo(),
	jogo(NULL)
{
	this->setPosicao(sf::Vector2f(COMPRIMENTO_CENARIO - 150.f , ALTURA_RESOLUCAO - (ALTURA_PLATAFORMA + 50.f)));
	this->setDimensoes(sf::Vector2f(50.f, 100.f));
	//this->setOrigem();
	//this->setTextura("");
}

Porta::~Porta()
{
}

void Porta::salvar()
{
	ofstream gravadorPorta("saves/Porta.dat", ios::app);

	if (!gravadorPorta)
		cout << "Erro." << endl;

	gravadorPorta << this->getPosicao().x << ' '
		<< this->getPosicao().y << ' ' << endl;

	gravadorPorta.close();
}

void Porta::setJogo(Jogo* jg)
{
	jogo = jg;
}

void Porta::colidir(Personagem* personagem)
{
	if (personagem->getAmigavel())
	{
		if (jogo->getEstado() == 4)
		{

			jogo->getFazendeira()->setPosicao(sf::Vector2f(200.f, 200.f));
			jogo->getFazendeira()->setFaseAtual(&jogo->getQuarto());
			if (jogo->getMultiplayer())
			{
				jogo->getBruxo()->setPosicao(sf::Vector2f(200.f, 200.f));
				jogo->getBruxo()->setFaseAtual(&jogo->getQuarto());
			}
		
			//jogo->InicializaQuarto();

			jogo->setEstado(5);
			jogo->getQuintal().limparTudo();
		}
		else 
		{
			//jogo->getMenuColocacao().setEditavel(true);
			jogo->setEstado(7);	
			jogo->getQuarto().limparTudo();
		}
	}
}
