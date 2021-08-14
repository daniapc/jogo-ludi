#include "MenuPause.h"
#include "Jogo.h"

MenuPause::MenuPause(unsigned int comprimento, unsigned int altura, int tamanho, Jogo* jg):
	Menu(comprimento, altura, tamanho, jg)
{
	Inicializa();
}

MenuPause::~MenuPause()
{
}

void MenuPause::setEstadoAtual(int estadoatual)
{
	EstadoAtual = estadoatual;
}

int MenuPause::getEstadoAtual()
{
	return EstadoAtual;
}

void MenuPause::LoopMenu(char tecla)
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

void MenuPause::Inicializa()
{
	menu = new sf::Text[Tamanho];
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setCharacterSize(24);
	menu[0].setString("Retomar");
	menu[0].setPosition(sf::Vector2f(COMPRIMENTO_RESOLUCAO / 4, 150));
	menu[0].setFont(Fonte);

	menu[1].setFillColor(sf::Color::Green);
	menu[1].setCharacterSize(24);
	menu[1].setString("Salvar jogo");
	menu[1].setPosition(sf::Vector2f(COMPRIMENTO_RESOLUCAO / 4, 250));
	menu[1].setFont(Fonte);

	menu[2].setFillColor(sf::Color::Green);
	menu[2].setCharacterSize(24);
	menu[2].setString("Salvar pontuação");
	menu[2].setPosition(sf::Vector2f(COMPRIMENTO_RESOLUCAO / 4, 350));
	menu[2].setFont(Fonte);

	menu[3].setFillColor(sf::Color::Green);
	menu[3].setCharacterSize(24);
	menu[3].setString("Voltar ao Menu Principal");
	menu[3].setPosition(sf::Vector2f(COMPRIMENTO_RESOLUCAO / 4, 450));
	menu[3].setFont(Fonte);	

	menu[4].setFillColor(sf::Color::Green);
	menu[4].setCharacterSize(24);
	menu[4].setString("Sair do Jogo");
	menu[4].setPosition(sf::Vector2f(COMPRIMENTO_RESOLUCAO / 4, 550));
	menu[4].setFont(Fonte);


}
