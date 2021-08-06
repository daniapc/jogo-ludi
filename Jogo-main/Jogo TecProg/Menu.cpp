#include "Menu.h"
#include "Jogo.h"

Menu::Menu(unsigned int comprimento, unsigned int altura, int tamanho, Jogo* jg)
{
	if (!Fonte.loadFromFile("arial.ttf"))
		cout << "Erro" << endl;

	jogo = jg;
	Indice = 0;
	Tamanho = tamanho;
}

Menu::~Menu()
{
}

/*
void Menu::LoopMenu(sf::Event* evento)
{
	//sf::Event evento;

	//while (Janela->pollEvent(evento))
	//{
		if (evento->type == sf::Event::KeyPressed)
		{
			if (evento->key.code == sf::Keyboard::Key::W)
				moverCima();
			if (evento->key.code == sf::Keyboard::Key::S)
				moverBaixo();
			if (evento->key.code == sf::Keyboard::Key::Enter)
			{
			}
		}
}
*/

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
	//Janela->draw(PlanoFundo);
	for (int i = 0; i < Tamanho; i++)
		Janela->draw(menu[i]); 
}
