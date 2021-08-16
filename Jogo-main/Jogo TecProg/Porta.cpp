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
			
			jogo->getJogador1()->setFaseAtual(&jogo->getQuarto());
			jogo->getJogador1()->setPosicao(200.f, 200.f);
			if (jogo->getMultiplayer())
			{
				jogo->getJogador2()->setFaseAtual(&jogo->getQuarto());
				jogo->getJogador2()->setPosicao(200.f, 200.f);
			}

			jogo->setEstado(5);
			jogo->getQuintal().limparTudo();
		}
		else 
		{
			jogo->mensagemCreditos("Voce Venceu!");
			jogo->setEstado(7);	
			jogo->getQuarto().limparTudo();
		}
	}
}
