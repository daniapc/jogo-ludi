#include "Creditos.h"
#include "Jogo.h"

Menus::Creditos::Creditos(Jogo* jg) :
	Menu(jg), Limite(1)
{
	MensagemFinal = "Perdeu o jogo.";

	TamIds = 1;
	Ids = new int[TamIds];
	Ids[0] = 0;

	Texto* novo = new Texto();
	criaTexto(novo, "Salvar Scoreboard", "Preto", "KidsPlay", 35, COMPRIMENTO_RESOLUCAO * 3 / 4, 500);
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	criaTexto(novo, "Voltar ao Menu Principal", "Preto", "KidsPlay", 35, COMPRIMENTO_RESOLUCAO * 3 / 4, 550);
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	criaTexto(novo, MensagemFinal, "Preto", "KidsPlay", 100, COMPRIMENTO_RESOLUCAO * 3/8, 200);
	Textos.push_back(novo);
	Tamanho++;
}

Menus::Creditos::~Creditos()
{
}

void Menus::Creditos::setMensagemFinal(string mensagemfinal){
	MensagemFinal = mensagemfinal;

	criaTexto(Textos[2], MensagemFinal, "Preto", "KidsPlay", 48, COMPRIMENTO_RESOLUCAO * 1/ 4, 200);
}


void Menus::Creditos::LoopMenu(char tecla)
{
		if (tecla == 'w' || tecla == 'W')
			moverCima();
		if (tecla == 's' || tecla == 'S')
			if(Indice < Limite)
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
				Indice = 0;
				jogo->setEstado(0);
				jogo->mensagemCreditos("Perdeu o jogo.");
				break;
			}
		}
	

}
