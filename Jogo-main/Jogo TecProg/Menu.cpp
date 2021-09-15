#include "Menu.h"
#include "Jogo.h"

Menus::Menu::Menu(Jogo* jg)
{
	srand(time(NULL));
	jogo = jg;
	Indice = 0;
	Tamanho = 0;
	TamIds = 0;
	Ids = NULL;
}

Menus::Menu::~Menu()
{
}

void Menus::Menu::criaTexto(Texto* t, string mens, string cor, string font, float dim, float posx, float posy)
{
	t->setMensagem(mens);
	t->setCor(cor);
	t->setFonte(font);
	t->setDimensao(dim);
	t->setPosicoes(posx, posy);
}

void Menus::Menu::moverCima()
{

	if (Indice <= 0)
		Indice = 0;
	else
		Indice--;

}

void Menus::Menu::moverBaixo()
{
	if (Indice >= Tamanho - 1)
		Indice = Tamanho - 1;
	else
		Indice++;
}

void Menus::Menu::desenhar()
{
	for (int i = 0; i < TamIds; i++)
		pGerenciadorGrafico->desenhar(Ids[i], false);
	for (int i = 0; i < Tamanho; i++) 
		pGerenciadorGrafico->desenhar(*Textos[i], i, Indice);
}

void Menus::Menu::InicializaPlanoFundo() {
	Cenario* verde = new Cenario(); //id = 0
	verde->setGerenciadorGrafico(pGerenciadorGrafico);
	pGerenciadorGrafico->criaCorpo(static_cast<Entidade*>(verde), COMPRIMENTO_RESOLUCAO, ALTURA_RESOLUCAO,
		COMPRIMENTO_RESOLUCAO / 2, ALTURA_RESOLUCAO / 2, "textures/Menu1.png");

	Cenario* beje = new Cenario(); //id = 1
	beje->setGerenciadorGrafico(pGerenciadorGrafico);
	pGerenciadorGrafico->criaCorpo(static_cast<Entidade*>(beje), COMPRIMENTO_RESOLUCAO, ALTURA_RESOLUCAO,
		COMPRIMENTO_RESOLUCAO / 2, ALTURA_RESOLUCAO / 2, "textures/Menu2.png");

	Cenario* selecao = new Cenario(); //id = 2
	selecao->setGerenciadorGrafico(pGerenciadorGrafico);
	pGerenciadorGrafico->criaCorpo(static_cast<Entidade*>(selecao), 40.f, 40.f,
		COMPRIMENTO_RESOLUCAO / 2, ALTURA_RESOLUCAO * 2 / 8, "textures/Selecao.png");

	Cenario* titulo = new Cenario(); //id = 3
	titulo->setGerenciadorGrafico(pGerenciadorGrafico);
	pGerenciadorGrafico->criaCorpo(static_cast<Entidade*>(titulo), COMPRIMENTO_RESOLUCAO/4, ALTURA_RESOLUCAO/4,
		COMPRIMENTO_RESOLUCAO / 2, ALTURA_RESOLUCAO * 2/8, "textures/Titulo1.png");

	Cenario* fazendeira = new Cenario(); //id = 4
	fazendeira->setGerenciadorGrafico(pGerenciadorGrafico);
	pGerenciadorGrafico->criaCorpo(static_cast<Entidade*>(fazendeira), 700*1/4, 820*1/4,
		COMPRIMENTO_RESOLUCAO * 7 / 16 - 50.f, ALTURA_RESOLUCAO * 8 / 16, "textures/Fazendeira_menu.png");

	Cenario* bruxo = new Cenario(); //id = 5
	bruxo->setGerenciadorGrafico(pGerenciadorGrafico);
	pGerenciadorGrafico->criaCorpo(static_cast<Entidade*>(bruxo), 640 * 1 / 4, 830 * 1 / 4,
		COMPRIMENTO_RESOLUCAO* 9 / 16 + 50.f, ALTURA_RESOLUCAO * 8 / 16, "textures/Bruxo_menu.png");

	Cenario* quintal = new Cenario(); //id = 6
	quintal->setGerenciadorGrafico(pGerenciadorGrafico);
	pGerenciadorGrafico->criaCorpo(static_cast<Entidade*>(quintal), COMPRIMENTO_RESOLUCAO*5/16, ALTURA_RESOLUCAO * 5 / 16,
		COMPRIMENTO_RESOLUCAO * 5 / 16, ALTURA_RESOLUCAO * 7 / 16, "textures/Quintal.png");
	quintal->setSubTextura("Quintal_Menu");

	Cenario* quarto = new Cenario(); //id = 7
	quarto->setGerenciadorGrafico(pGerenciadorGrafico);
	pGerenciadorGrafico->criaCorpo(static_cast<Entidade*>(quarto), COMPRIMENTO_RESOLUCAO * 5 / 16, ALTURA_RESOLUCAO * 5 / 16,
		COMPRIMENTO_RESOLUCAO * 11 / 16, ALTURA_RESOLUCAO * 7 / 16, "textures/Quarto.png");
	quarto->setSubTextura("Quarto_Menu");

}
