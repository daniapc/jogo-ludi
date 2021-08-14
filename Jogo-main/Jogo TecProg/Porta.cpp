#include "Porta.h"
#include "Jogo.h"

Porta::Porta():
	Obstaculo(),
	jogo(NULL)
{

}

Porta::~Porta()
{
}

void Porta::salvar()
{
	ofstream gravadorPorta("saves/Porta.dat", ios::app);

	if (!gravadorPorta)
		cout << "Erro Gravar Porta." << endl;

	gravadorPorta << this->getPosicaoX()  << ' '
		<< this->getPosicaoY()  << ' ' << endl;

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
			
			jogo->getFazendeira()->setFaseAtual(&jogo->getQuarto());
			jogo->getFazendeira()->setPosicao(200.f, 200.f);
			if (jogo->getMultiplayer())
			{
				jogo->getBruxo()->setFaseAtual(&jogo->getQuarto());
				jogo->getBruxo()->setPosicao(200.f, 200.f);
			}

			jogo->setEstado(5);
			jogo->getQuintal().limparTudo();
		}
		else 
		{
			jogo->setEstado(7);	
			jogo->getQuarto().limparTudo();
		}
	}
}
