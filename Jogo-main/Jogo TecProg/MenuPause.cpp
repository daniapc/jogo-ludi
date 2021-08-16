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
				break;
			case 2:
				jogo->getMenuColocacao().setEstadoAnterior(6);
				jogo->getMenuColocacao().setEditavel(true);
				jogo->setEstado(3);
				break;
			case 3:
				jogo->setEstado(0);
				break;
			case 4:
				pGerenciadorGrafico->fechar();
				break;
			}
		}
	
}

void Menus::MenuPause::Inicializa()
{
	Texto* novo = new Texto();
	novo->setCor("Vermelho");
	novo->setDimensao(24);
	novo->setMensagem("Retomar");
	novo->setPosicoes(COMPRIMENTO_RESOLUCAO / 4, 150);
	novo->setFonte("KidsPlay");
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	novo->setCor("Preto");
	novo->setDimensao(24);
	novo->setMensagem("Salvar jogo");
	novo->setPosicoes(COMPRIMENTO_RESOLUCAO / 4, 250);
	novo->setFonte("KidsPlay");
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	novo->setCor("Preto");
	novo->setDimensao(24);
	novo->setMensagem("Salvar pontuacao");
	novo->setPosicoes(COMPRIMENTO_RESOLUCAO / 4, 350);
	novo->setFonte("KidsPlay");
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	novo->setCor("Preto");
	novo->setDimensao(24);
	novo->setMensagem("Voltar ao Menu Principal");
	novo->setPosicoes(COMPRIMENTO_RESOLUCAO / 4, 450);
	novo->setFonte("KidsPlay");
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	novo->setCor("Preto");
	novo->setDimensao(24);
	novo->setMensagem("Sair do jogo");
	novo->setPosicoes(COMPRIMENTO_RESOLUCAO / 4, 550);
	novo->setFonte("KidsPlay");
	Textos.push_back(novo);
	Tamanho++;
	
}
