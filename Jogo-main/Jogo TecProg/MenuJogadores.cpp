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
	
		if (tecla == 'w' || tecla == 'W')
			if (Indice > LimiteCima)
				moverCima();
		if (tecla == 's' || tecla == 'S')
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
				Textos[4]->setCor("Vermelho");
				Textos[5]->setCor("Preto");
				Textos[6]->setCor("Preto");
				LimiteCima = 4;
				LimiteBaixo = 6;
				Indice = 4;
				break;
			case 1:
				jogo->setMultiplayer(true);
				jogo->setEstado(2);
				break;
			case 2:
			{
				jogo->setEstado(0);
				moverCima();
				moverCima();
			}
			break;
			case 4:
				jogo->setJogador1Fazendeira(true);
				jogo->setEstado(2);
				break;
			case 5:
				jogo->setJogador1Fazendeira(false);
				jogo->setEstado(2);
				break;
			case 6:
				Textos[0]->setCor("Vermelho");
				Textos[1]->setCor("Preto");
				Textos[2]->setCor("Preto");
				Textos[3]->setCor("Transparente");
				Textos[4]->setCor("Transparente");
				Textos[5]->setCor("Transparente");
				Textos[6]->setCor("Transparente");
				LimiteCima = 0;
				LimiteBaixo = 2;
				Indice = 0;
				break;
			}
		}
}

void Menus::MenuJogadores::Inicializa() {

	Texto* novo = new Texto();
	novo->setCor("Vermelho");
	novo->setDimensao(30);
	novo->setMensagem("1 Jogador");
	novo->setPosicoes(COMPRIMENTO_RESOLUCAO / 4, 250);
	novo->setFonte("KidsPlay");
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	novo->setCor("Preto");
	novo->setDimensao(30);
	novo->setMensagem("2 Jogadores");
	novo->setPosicoes(COMPRIMENTO_RESOLUCAO / 4, 350);
	novo->setFonte("KidsPlay");
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	novo->setCor("Preto");
	novo->setDimensao(30);
	novo->setMensagem("Voltar");
	novo->setPosicoes(COMPRIMENTO_RESOLUCAO / 4, 450);
	novo->setFonte("KidsPlay");
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	novo->setCor("Transparente");
	novo->setDimensao(30);
	novo->setMensagem("Escolha com qual jogador jogar:");
	novo->setPosicoes(COMPRIMENTO_RESOLUCAO / 4, 250);
	novo->setFonte("KidsPlay");
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	novo->setCor("Transparente");
	novo->setDimensao(30);
	novo->setMensagem("Fazendeira");
	novo->setPosicoes(COMPRIMENTO_RESOLUCAO / 4, 350);
	novo->setFonte("KidsPlay");
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	novo->setCor("Transparente");
	novo->setDimensao(30);
	novo->setMensagem("Bruxo");
	novo->setPosicoes(COMPRIMENTO_RESOLUCAO / 4, 400);
	novo->setFonte("KidsPlay");
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	novo->setCor("Transparente");
	novo->setDimensao(30);
	novo->setMensagem("Voltar");
	novo->setPosicoes(COMPRIMENTO_RESOLUCAO / 4, 500);
	novo->setFonte("KidsPlay");
	Textos.push_back(novo);
	Tamanho++;

}
