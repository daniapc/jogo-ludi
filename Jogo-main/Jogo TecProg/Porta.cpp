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
			jogo->getJogador1()->setPosicao(100.f, ALTURA_RESOLUCAO - ALTURA_PLATAFORMA - ALTURA_JOGADOR/2);
			if (jogo->getMultiplayer())
			{
				jogo->getJogador2()->setFaseAtual(&jogo->getQuarto());
				jogo->getJogador2()->setPosicao(100.f, ALTURA_RESOLUCAO - ALTURA_PLATAFORMA - ALTURA_JOGADOR / 2);
			}
			pGerenciadorGrafico->tocarMusica("Quarto");
			jogo->setEstado(5);
			jogo->getQuintal().limparTudo();
		}
		else 
		{
			pGerenciadorGrafico->tocarMusica("Creditos");
			jogo->mensagemCreditos("Venceu o jogo! ");
			jogo->setEstado(7);	
			jogo->getQuarto().limparTudo();
		}
	}
}
