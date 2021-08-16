#include "Creditos.h"
#include "Jogo.h"

Menus::Creditos::Creditos(Jogo* jg) :
	Menu(jg), Limite(2)
{
	MensagemFinal = "Voce Perdeu.";

	Texto* novo = new Texto();
	novo->setCor("Vermelho");
	novo->setDimensao(24);
	novo->setMensagem("Salvar Pontuacao");
	novo->setPosicoes(COMPRIMENTO_RESOLUCAO * 3 / 4, 500);
	novo->setFonte("KidsPlay");
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	novo->setCor("Preto");
	novo->setDimensao(24);
	novo->setMensagem("Voltar ao Menu Principal");
	novo->setPosicoes(COMPRIMENTO_RESOLUCAO * 3 / 4, 550);
	novo->setFonte("KidsPlay");
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	criaTexto(novo, MensagemFinal, "Azul", "KidsPlay", 48, COMPRIMENTO_RESOLUCAO * 1/ 4, 200);
	Textos.push_back(novo);
	Tamanho++;

}

Menus::Creditos::~Creditos()
{
}

void Menus::Creditos::setMensagemFinal(string mensagemfinal){
	MensagemFinal = mensagemfinal;

	criaTexto(Textos[2], MensagemFinal, "Azul", "Arial", 48, COMPRIMENTO_RESOLUCAO * 1/ 4, 200);
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
				jogo->setEstado(0);
				jogo->mensagemCreditos("Voce Perdeu.");
				break;
			}
		}
	

}
