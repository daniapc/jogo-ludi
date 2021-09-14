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
	//Id = 0;
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
	{
		Textos[Indice]->setCor("Preto");
		Indice--;
		Textos[Indice]->setCor("Vermelho");
	}

}

void Menus::Menu::moverBaixo()
{
	if (Indice >= Tamanho - 1)
		Indice = Tamanho - 1;
	else
	{
		Textos[Indice]->setCor("Preto");
		Indice++;
		Textos[Indice]->setCor("Vermelho");
	}
}

void Menus::Menu::desenhar()
{
	for (int i = 0; i < TamIds; i++)
		pGerenciadorGrafico->desenhar(Ids[i], false);
	for (int i = 0; i < Tamanho; i++) 
		pGerenciadorGrafico->desenhar(*Textos[i]);
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

	Cenario* titulo = new Cenario(); //id = 2
	titulo->setGerenciadorGrafico(pGerenciadorGrafico);
	pGerenciadorGrafico->criaCorpo(static_cast<Entidade*>(titulo), COMPRIMENTO_RESOLUCAO/4, ALTURA_RESOLUCAO/4,
		COMPRIMENTO_RESOLUCAO / 2, ALTURA_RESOLUCAO * 2/8, "textures/Titulo1.png");
}
