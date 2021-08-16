#include "MenuFases.h"
#include "Jogo.h"

Menus::MenuFases::MenuFases(Jogo* jg):
	Menu(jg)
{
	Texto* novo = new Texto();
	novo->setCor("Vermelho");
	novo->setDimensao(24);
	novo->setMensagem("Fase 1");
	novo->setPosicoes(COMPRIMENTO_RESOLUCAO / 4, 250);
	novo->setFonte("KidsPlay");
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	novo = novo;
	novo->setCor("Preto");
	novo->setDimensao(24);
	novo->setMensagem("Fase 2");
	novo->setPosicoes(COMPRIMENTO_RESOLUCAO / 4, 350);
	novo->setFonte("KidsPlay");
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	novo->setCor("Preto");
	novo->setDimensao(24);
	novo->setMensagem("Voltar");
	novo->setPosicoes(COMPRIMENTO_RESOLUCAO / 4, 450);
	novo->setFonte("KidsPlay");
	Textos.push_back(novo);
	Tamanho++;
}

Menus::MenuFases::~MenuFases()
{
}

void Menus::MenuFases::LoopMenu(char tecla)
{

		if (tecla == 'w' || tecla == 'W')
			moverCima();
		if (tecla == 's' || tecla == 'S')
			moverBaixo();
		if (tecla == 13)
		{
			switch (Indice)
			{
			case 0:
				jogo->InicializaJogadores();
				jogo->InicializaFases();
				jogo->getJogador1()->setFaseAtual(&jogo->getQuintal());
				if (jogo->getMultiplayer())
					jogo->getJogador2()->setFaseAtual(&jogo->getQuintal());
				jogo->setEstado(4);
				break;
			case 1:
				jogo->InicializaJogadores();

				if (jogo->getMultiplayer())
					jogo->getJogador2()->setFaseAtual(&jogo->getQuarto());
				jogo->getJogador1()->setFaseAtual(&jogo->getQuarto());
				jogo->InicializaQuarto();
				jogo->setEstado(5);
				break;
			case 2:
			{
				jogo->setMultiplayer(false);
				jogo->setEstado(1);
				moverCima();
				moverCima();
			}
				break;
			}
		}
	
}
