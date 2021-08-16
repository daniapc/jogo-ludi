#include "MenuPrincipal.h"
#include "Jogo.h"

Menus::MenuPrincipal::MenuPrincipal(Jogo* jg):
Menu(jg)
{
	Tamanho = 0;
	Texto* novo = new Texto();
	novo->setCor("Vermelho");
	novo->setDimensao(30);
	novo->setMensagem("Novo Jogo");
	novo->setPosicoes(COMPRIMENTO_RESOLUCAO / 4, 250);
	novo->setFonte("KidsPlay");
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	novo->setCor("Preto");
	novo->setDimensao(30);
	novo->setMensagem("Recuperar Jogo Salvo");
	novo->setPosicoes(COMPRIMENTO_RESOLUCAO / 4, 350);
	novo->setFonte("KidsPlay");
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	novo->setCor("Preto");
	novo->setDimensao(30);
	novo->setMensagem("Scoreboard");
	novo->setPosicoes(COMPRIMENTO_RESOLUCAO / 4, 450);
	novo->setFonte("KidsPlay");
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	novo->setCor("Preto");
	novo->setDimensao(30);
	novo->setMensagem("Sair");
	novo->setPosicoes(COMPRIMENTO_RESOLUCAO / 4, 550);
	novo->setFonte("KidsPlay");
	Textos.push_back(novo);
	Tamanho++;

	
}

Menus::MenuPrincipal::~MenuPrincipal()
{
}

void Menus::MenuPrincipal::InicializaPlanoFundo(){
	PlanoFundo.setGerenciadorGrafico(pGerenciadorGrafico);
pGerenciadorGrafico->criaCorpo(static_cast<Entidade*>(&PlanoFundo), COMPRIMENTO_RESOLUCAO, ALTURA_RESOLUCAO,
		COMPRIMENTO_RESOLUCAO / 2, ALTURA_RESOLUCAO / 2, "textures/Menu1.png");
	Cenario* novo = new Cenario();
	novo->setGerenciadorGrafico(pGerenciadorGrafico);
	pGerenciadorGrafico->criaCorpo(static_cast<Entidade*>(novo), COMPRIMENTO_RESOLUCAO, ALTURA_RESOLUCAO,
		COMPRIMENTO_RESOLUCAO / 2, ALTURA_RESOLUCAO / 2, "textures/Menu2.png");
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
				jogo->setEstado(1);
				jogo->getQuintal().limparTudo();
				jogo->getQuarto().limparTudo();
				break;
			case 1:
				jogo->getQuintal().limparTudo();
				jogo->getQuarto().limparTudo();
				jogo->Recuperar();
				break;
			case 2:
				jogo->getMenuColocacao().setEstadoAnterior(jogo->getEstado());
				jogo->getMenuColocacao().setEditavel(false);
				jogo->setEstado(3);
				break;
			case 3:
				pGerenciadorGrafico->fechar();
				break;
			}
		}
	
}

