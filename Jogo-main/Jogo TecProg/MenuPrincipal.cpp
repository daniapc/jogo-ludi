#include "MenuPrincipal.h"
#include "Jogo.h"

MenuPrincipal::MenuPrincipal(unsigned int comprimento, unsigned int altura, int tamanho, Jogo* jg):
Menu(comprimento, altura, tamanho, jg)
{
	menu = new sf::Text[Tamanho];
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setCharacterSize(24);
	menu[0].setString("Novo Jogo");
	menu[0].setPosition(sf::Vector2f(COMPRIMENTO_RESOLUCAO/4, 250));
	menu[0].setFont(Fonte);
	menu[1].setFillColor(sf::Color::Green);
	menu[1].setCharacterSize(24);
	menu[1].setString("Carregar Jogo");
	menu[1].setPosition(sf::Vector2f(COMPRIMENTO_RESOLUCAO / 4, 350));
	menu[1].setFont(Fonte);
	menu[2].setFillColor(sf::Color::Green);
	menu[2].setCharacterSize(24);
	menu[2].setString("Verificar Pontuação");
	menu[2].setPosition(sf::Vector2f(COMPRIMENTO_RESOLUCAO / 4, 450));
	menu[2].setFont(Fonte);
	menu[3].setFillColor(sf::Color::Green);
	menu[3].setCharacterSize(24);
	menu[3].setString("Sair");
	menu[3].setPosition(sf::Vector2f(COMPRIMENTO_RESOLUCAO / 4, 550));
	menu[3].setFont(Fonte);

}

MenuPrincipal::~MenuPrincipal()
{
}

void MenuPrincipal::LoopMenu(char tecla)
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
				pGerenciadorGrafico->getJanela().close();
				break;
			}
		}
	
}

