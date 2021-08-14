#include "Menu.h"
#include "Jogo.h"

Menu::Menu(unsigned int comprimento, unsigned int altura, int tamanho, Jogo* jg)
{
	if (!Fonte.loadFromFile("arial.ttf"))
		cout << "Erro ao carregar fonte." << endl;

	jogo = jg;
	Indice = 0;
	Tamanho = tamanho;
}

Menu::~Menu()
{
}

void Menu::moverCima()
{

	if (Indice <= 0)
		Indice = 0;
	else
	{
		menu[Indice].setFillColor(sf::Color::Green);
		Indice--;
		menu[Indice].setFillColor(sf::Color::Red);
	}

}

void Menu::moverBaixo()
{
	if (Indice >= Tamanho - 1)
		Indice = Tamanho - 1;
	else
	{
		menu[Indice].setFillColor(sf::Color::Green);
		Indice++;
		menu[Indice].setFillColor(sf::Color::Red);
	}
}

void Menu::desenhar()
{
	for (int i = 0; i < Tamanho; i++)
		pGerenciadorGrafico->desenhar(menu[i]);
}
