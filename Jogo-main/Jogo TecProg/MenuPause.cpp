#include "MenuPause.h"
#include "Jogo.h"

Menus::MenuPause::MenuPause(Jogo* jg):
	Menu(jg)
{
	Inicializa();
}

Menus::MenuPause::~MenuPause()
{
}

void Menus::MenuPause::setEstadoAtual(int estadoatual)
{
	EstadoAtual = estadoatual;
}

int Menus::MenuPause::getEstadoAtual() const
{
	return EstadoAtual;
}

void Menus::MenuPause::LoopMenu(char tecla)
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
				jogo->setEstado(EstadoAtual);
				break;
			case 1:
				jogo->Salvar();
				criaTexto(Textos[1], "(Jogo salvo com sucesso)", "Preto", "KidsPlay", 35, COMPRIMENTO_RESOLUCAO * 1 / 2, 250);
				break;
			case 2:
				jogo->getMenuColocacao().setEstadoAnterior(6);
				jogo->getMenuColocacao().setEditavel(true);
				Indice = 0;
				jogo->setEstado(3);
				break;
			case 3:
				Indice = 0;
				pGerenciadorGrafico->tocarMusica("Menu_e_Quintal");
				jogo->setEstado(0);
				break;
			case 4:
				pGerenciadorGrafico->fechar();
				break;
			}
		}
		if (jogo->getEstado() != 6) {
			criaTexto(Textos[1], "Salvar jogo", "Preto", "KidsPlay", 35, COMPRIMENTO_RESOLUCAO * 1 / 2, 250);
		}
}

void Menus::MenuPause::Inicializa()
{
	TamIds = 1;
	Ids = new int[TamIds];
	Ids[0] = 1;

	Texto* novo = new Texto();
	criaTexto(novo, "Retomar", "Preto", "KidsPlay", 35, COMPRIMENTO_RESOLUCAO * 1 / 2, 150);
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	criaTexto(novo, "Salvar jogo", "Preto", "KidsPlay", 35, COMPRIMENTO_RESOLUCAO * 1 / 2, 250);
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	criaTexto(novo, "Salvar Scoreboard", "Preto", "KidsPlay", 35, COMPRIMENTO_RESOLUCAO * 1 / 2, 350);
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	criaTexto(novo, "Voltar ao Menu Principal", "Preto", "KidsPlay", 35, COMPRIMENTO_RESOLUCAO * 1 / 2, 450);
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	criaTexto(novo, "Sair do jogo", "Preto", "KidsPlay", 35, COMPRIMENTO_RESOLUCAO * 1 / 2, 550);
	Textos.push_back(novo);
	Tamanho++;
}
