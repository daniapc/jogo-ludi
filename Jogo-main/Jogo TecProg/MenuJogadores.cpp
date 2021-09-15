#include "MenuJogadores.h"
#include "Jogo.h"

Menus::MenuJogadores::MenuJogadores(Jogo* jg):
	Menu(jg),
	LimiteBaixo(2),
	LimiteCima(0)
{
	Inicializa();
}

Menus::MenuJogadores::~MenuJogadores()
{
}

void Menus::MenuJogadores::LoopMenu(char tecla)
{
	
		if (tecla == 'w' || tecla == 'W' || tecla == 'a' || tecla == 'A')
			if (Indice > LimiteCima)
				moverCima();
		if (tecla == 's' || tecla == 'S' || tecla == 'd' || tecla == 'D')
			if (Indice < LimiteBaixo)
				moverBaixo();
		if (tecla == 13)
		{
			switch (Indice)
			{
			case 0:
				Textos[0]->setCor("Transparente");
				Textos[1]->setCor("Transparente");
				Textos[2]->setCor("Transparente");
				Textos[3]->setCor("Preto");
				Textos[4]->setCor("Preto");
				Textos[5]->setCor("Preto");
				Textos[6]->setCor("Preto");
				TamIds = 3;
				LimiteCima = 4;
				LimiteBaixo = 6;
				Indice = 4;
				break;
			case 1:
				jogo->setMultiplayer(true);
				Indice = 0;
				jogo->setEstado(2);
				break;
			case 2:
			{
				Indice = 0;
				jogo->setEstado(0);
				moverCima();
				moverCima();
			}
			break;
			case 4:
				jogo->setJogador1Fazendeira(true);
				Indice = 4;
				jogo->setEstado(2);
				break;
			case 5:
				jogo->setJogador1Fazendeira(false);
				Indice = 4;
				jogo->setEstado(2);
				break;
			case 6:
				Textos[0]->setCor("Preto");
				Textos[1]->setCor("Preto");
				Textos[2]->setCor("Preto");
				Textos[3]->setCor("Transparente");
				Textos[4]->setCor("Transparente");
				Textos[5]->setCor("Transparente");
				Textos[6]->setCor("Transparente");
				TamIds = 1;
				LimiteCima = 0;
				LimiteBaixo = 2;
				Indice = 0;
				break;
			}
		}
}

void Menus::MenuJogadores::Inicializa() {

	TamIds = 3;
	Ids = new int[TamIds];
	Ids[0] = 1;
	Ids[1] = 4;
	Ids[2] = 5;

	TamIds = 1;

	Texto* novo = new Texto();
	criaTexto(novo, "1 Jogador", "Preto", "KidsPlay", 35, COMPRIMENTO_RESOLUCAO * 1 / 2, 250);
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	criaTexto(novo, "2 Jogadores", "Preto", "KidsPlay", 35, COMPRIMENTO_RESOLUCAO * 1 / 2, 350);
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	criaTexto(novo, "Voltar", "Preto", "KidsPlay", 35, COMPRIMENTO_RESOLUCAO * 1 / 2, 450);
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	criaTexto(novo, "Escolha com qual jogador jogar:", "Transparente", "KidsPlay", 35, COMPRIMENTO_RESOLUCAO * 1 / 2, 150);
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	criaTexto(novo, "Fazendeira", "Transparente", "KidsPlay", 35, COMPRIMENTO_RESOLUCAO * 7 / 16 - 50.f, 500);
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	criaTexto(novo, "Bruxo", "Transparente", "KidsPlay", 35, COMPRIMENTO_RESOLUCAO * 9 / 16 + 50.f, 500);
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	criaTexto(novo, "Voltar", "Transparente", "KidsPlay", 35, COMPRIMENTO_RESOLUCAO * 1 / 2, 600);
	Textos.push_back(novo);
	Tamanho++;

}
