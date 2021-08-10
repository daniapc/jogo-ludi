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
	menu[2].setString("Pontuação");
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

void MenuPrincipal::LoopMenu(sf::Event* evento)
{
	if (evento->type == sf::Event::KeyPressed)
	{
		if (evento->key.code == sf::Keyboard::Key::W)
			moverCima();
		if (evento->key.code == sf::Keyboard::Key::S)
			moverBaixo();
		if (evento->key.code == sf::Keyboard::Key::Enter)
		{
			switch (Indice)
			{
			case 0:
				jogo->setEstado(1);
				break;
			case 1:
				jogo->Recuperar();
				break;
			case 2:
				break;
			case 3:
				Janela->close();
				break;
			}
		}
	}
}

