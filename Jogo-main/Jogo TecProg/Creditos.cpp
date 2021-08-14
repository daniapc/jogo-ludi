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


void Creditos::LoopMenu(char tecla)
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
