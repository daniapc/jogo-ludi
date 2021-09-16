#include "MenuFases.h"
#include "Jogo.h"

Menus::MenuFases::MenuFases(Jogo* jg):
	Menu(jg)
{
	TamIds = 3;
	Ids = new int[TamIds];
	Ids[0] = 1;
	Ids[1] = 6;
	Ids[2] = 7;

	Texto* novo = new Texto();
	criaTexto(novo, "Fase 1 (Quintal)", "Preto", "KidsPlay", 35, COMPRIMENTO_RESOLUCAO * 5 / 16, 475);
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	criaTexto(novo, "Fase 2 (Quarto)", "Preto", "KidsPlay", 35, COMPRIMENTO_RESOLUCAO * 11 / 16, 475);
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	criaTexto(novo, "Voltar", "Preto", "KidsPlay", 35, COMPRIMENTO_RESOLUCAO * 1 / 2, 600);
	Textos.push_back(novo);
	Tamanho++;
}

Menus::MenuFases::~MenuFases()
{
}

void Menus::MenuFases::LoopMenu(char tecla)
{

		if (tecla == 'w' || tecla == 'W' || tecla == 'a' || tecla == 'A')
			moverCima();
		if (tecla == 's' || tecla == 'S' || tecla == 'd' || tecla == 'D')
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
				pGerenciadorGrafico->tocarMusica("Quarto");
				jogo->InicializaQuarto();
				Indice = 0;
				jogo->setEstado(5);
				break;
			case 2:
			{
				jogo->setMultiplayer(false);
				Indice = 0;
				jogo->setEstado(1);
				moverCima();
				moverCima();
			}
				break;
			}
		}
	
}
