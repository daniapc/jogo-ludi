#include "Creditos.h"
#include "Jogo.h"

Creditos::Creditos(unsigned int comprimento, unsigned int altura, int tamanho, Jogo* jg) :
	Menu(comprimento, altura, tamanho, jg)
{

	//setDimensoes(sf::Vector2f(COMPRIMENTO_JOGADOR, ALTURA_JOGADOR));
    //setOrigem();
    //setPosicao(sf::Vector2f(COMPRIMENTO_RESOLUCAO/2, ALTURA_RESOLUCAO));
    //setTextura("");
	
	menu = new sf::Text[Tamanho];
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setCharacterSize(24);
	menu[0].setString("Salvar Pontuação");
	menu[0].setPosition(sf::Vector2f(COMPRIMENTO_RESOLUCAO*3/4, 500));
	menu[0].setFont(Fonte);
	menu[1].setFillColor(sf::Color::Green);
	menu[1].setCharacterSize(24);
	menu[1].setString("Voltar ao Menu Principal");
	menu[1].setPosition(sf::Vector2f(COMPRIMENTO_RESOLUCAO * 3/4, 550));
	menu[1].setFont(Fonte);
}

Creditos::~Creditos()
{
}


void Creditos::LoopMenu(sf::Event* evento)
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
				jogo->getMenuColocacao().setEstadoAnterior(jogo->getEstado());
				jogo->getMenuColocacao().setEditavel(true);
				jogo->setEstado(3);
				break;
			case 1:
				jogo->setEstado(0);
				break;
			}
		}
	}

}
