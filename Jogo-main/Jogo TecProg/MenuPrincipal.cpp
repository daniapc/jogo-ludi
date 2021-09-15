#include "MenuPrincipal.h"
#include "Jogo.h"

Menus::MenuPrincipal::MenuPrincipal(Jogo* jg):
Menu(jg)
{
	TamIds = 2;
	Ids = new int[TamIds];
	Ids[0] = 0;
	Ids[1] = 3;

	Texto* novo = new Texto();
	criaTexto(novo, "Novo Jogo", "Preto", "KidsPlay", 35, COMPRIMENTO_RESOLUCAO * 1 / 2, 325);
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	criaTexto(novo, "Recuperar Jogo Salvo", "Preto", "KidsPlay", 35, COMPRIMENTO_RESOLUCAO * 1 / 2, 400);
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	criaTexto(novo, "Scoreboard", "Preto", "KidsPlay", 35, COMPRIMENTO_RESOLUCAO * 1 / 2, 475);
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	criaTexto(novo, "Sair", "Preto", "KidsPlay", 35, COMPRIMENTO_RESOLUCAO * 1 / 2, 550);
	Textos.push_back(novo);
	Tamanho++;

}

Menus::MenuPrincipal::~MenuPrincipal()
{
}

void Menus::MenuPrincipal::LoopMenu(char tecla)
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
				jogo->setMultiplayer(false);
				jogo->setEstado(1);
				jogo->getQuintal().limparTudo();
				jogo->getQuarto().limparTudo();
				break;
			case 1:
				jogo->getQuintal().limparTudo();
				jogo->getQuarto().limparTudo();
				Indice = 0;
				jogo->Recuperar();
				break;
			case 2:
				jogo->getMenuColocacao().setEstadoAnterior(jogo->getEstado());
				jogo->getMenuColocacao().setEditavel(false);
				Indice = 0;
				jogo->setEstado(3);
				break;
			case 3:
				pGerenciadorGrafico->fechar();
				break;
			}
		}
	
}

