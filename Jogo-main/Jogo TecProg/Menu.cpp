#include "Menu.h"
#include "Jogo.h"

Menus::Menu::Menu(Jogo* jg): PlanoFundo()
{
	srand(time(NULL));
	jogo = jg;
	Indice = 0;
	Tamanho = 0;
	Id = rand() % 2;
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
	pGerenciadorGrafico->desenhar(PlanoFundo.getId() + Id, false);
	for (int i = 0; i < Tamanho; i++) 
		pGerenciadorGrafico->desenhar(*Textos[i]);
}
