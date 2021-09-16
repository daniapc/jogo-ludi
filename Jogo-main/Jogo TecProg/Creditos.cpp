#include "Creditos.h"
#include "Jogo.h"

Menus::Creditos::Creditos(Jogo* jg) :
	Menu(jg), Limite(1)
{
	MensagemFinal = "Perdeu o jogo.";

	TamIds = 1;
	Ids = new int[TamIds];
	Ids[0] = 1;

	Texto* novo = new Texto();
	criaTexto(novo, "Salvar Scoreboard", "Preto", "KidsPlay", 35, COMPRIMENTO_RESOLUCAO * 13 / 16, 575);
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	criaTexto(novo, "Voltar ao Menu Principal", "Preto", "KidsPlay", 35, COMPRIMENTO_RESOLUCAO * 13 / 16, 625);
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	criaTexto(novo, MensagemFinal, "Preto", "KidsPlay", 100, COMPRIMENTO_RESOLUCAO * 2/4, 100);
	Textos.push_back(novo);
	Tamanho++;

	string MensagemCreditos;
	MensagemCreditos = "\n           Desenvolvimento:\n  Daniel Augusto Pires de Castro\n";
	MensagemCreditos += "     Francisco Cardoso Becheli\n\n           Arte e texturas:\nMartemis (Maira Pires de Castro)\n";
	MensagemCreditos += "\n             Trilha sonora:\n      Milena Lais Garcia de Lima\n";
	MensagemCreditos += "\n    Agradecimentos Especiais:\n Professor Jean Marcelo Simao\n     Colegas e amigos da UTFPR\n             Carl Wheezer";

	novo = new Texto();
	criaTexto(novo, MensagemCreditos, "Preto", "KidsPlay", 20, COMPRIMENTO_RESOLUCAO * 4 / 8, 375);
	Textos.push_back(novo);
	Tamanho++;
}

Menus::Creditos::~Creditos()
{
}

void Menus::Creditos::setMensagemFinal(string mensagemfinal){
	MensagemFinal = mensagemfinal;

	criaTexto(Textos[2], MensagemFinal, "Preto", "KidsPlay", 100, COMPRIMENTO_RESOLUCAO * 2/ 4, 100);
	Ids[0] = 0;
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
				pGerenciadorGrafico->tocarMusica("Menu_e_Quintal");
				jogo->mensagemCreditos("Perdeu o jogo.");
				Ids[0] = 1;
				break;
			}
		}
	

}
