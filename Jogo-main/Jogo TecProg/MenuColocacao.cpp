#include "MenuColocacao.h"
#include "Jogo.h"

Menus::MenuColocacao::MenuColocacao(Jogo* jg):
	Menu(jg),
	EstadoAnterior(0)
{	
	Inicializa();
}

Menus::MenuColocacao::~MenuColocacao()
{
}

void Menus::MenuColocacao::LoopMenu(char tecla)
{

	if (Digitando)
	{
			if (tecla == 13)
			{
				Indice = 5;
				Digitando = false;
				Nome.clear();
			}
			else
			{
				string saux;
				stringstream ss;

				if (tecla == '\b') {
					if (Nome.size() != 0)
						Nome.erase(Nome.size() - 1);
				}
				else if (tecla > 31 && tecla < 128) {
					Nome = Nome + tecla;
				}

				ss << jogo->getJogador1()->getPontuacao();

				saux = ss.str() + " - " + Nome;
				Textos[Indice]->setMensagem(saux);
			}
	}
	 
	else {
		if (tecla == 'w' || tecla == 'W')
			if (Indice != Limite)
				moverCima();
		if (tecla == 's' || tecla == 'S')
			moverBaixo();
		if (tecla == 13)
		{
			if (Indice < 5) {
				Digitando = true;
				string saux;
				stringstream ss;
				ss << jogo->getJogador1()->getPontuacao();
				saux = ss.str() + " - ";
				Textos[Indice]->setMensagem(saux);
			}
			else
				switch (Indice)
				{
				case 5:
				{
					ofstream deletarColocacao("saves/Colocacao.dat", ios::out);
					deletarColocacao.close();

					ofstream gravadorColocacao("saves/Colocacao.dat", ios::app);
					if (!gravadorColocacao)
						cout << "Erro Gravar Colocacao." << endl;

					for (int i = 1; i <= 4; i++) {
						string saux = Textos[i]->getMensagem();
						while (saux.back() == ' ')
							saux.pop_back();

						gravadorColocacao << saux << '\n';
					}


					gravadorColocacao.close();
				}
				break;
				case 6:
					for (int i = 1; i <= 4; i++)
						Textos[i]->setMensagem("0 - Vazio");
					break;
				case 7:
					jogo->setEstado(EstadoAnterior);
					break;
				}

		}
	}
}

void Menus::MenuColocacao::Recupera()
{
	ifstream recuperadorColocacao("saves/Colocacao.dat", ios::in);

	if (!recuperadorColocacao)
		cout << "Erro Recuperar Colocacao." << endl;

	int i = 1;
	string aux, string = "";

	while (!recuperadorColocacao.eof()) {
		recuperadorColocacao >> aux;
		string += aux + " ";
		aux = "";
		if (recuperadorColocacao.get() == '\n') {
			Textos[i]->setMensagem(string);
			i++;
			string = "";
		}
	}

	recuperadorColocacao.close();

}

void Menus::MenuColocacao::Inicializa()
{
	Digitando = false;

	TamIds = 1;
	Ids = new int[TamIds];
	Ids[0] = 1;

	Texto* novo = new Texto();
	criaTexto(novo, "Scoreboard", "Preto", "KidsPlay", 50, COMPRIMENTO_RESOLUCAO * 1 / 2, 125);
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	criaTexto(novo, "0 - Vazio", "Preto", "KidsPlay", 35, COMPRIMENTO_RESOLUCAO * 1 / 2, 200);
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	criaTexto(novo, "0 - Vazio", "Preto", "KidsPlay", 35, COMPRIMENTO_RESOLUCAO * 1 / 2, 250);
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	criaTexto(novo, "0 - Vazio", "Preto", "KidsPlay", 35, COMPRIMENTO_RESOLUCAO * 1 / 2, 300);
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	criaTexto(novo, "0 - Vazio", "Preto", "KidsPlay", 35, COMPRIMENTO_RESOLUCAO * 1 / 2, 350);
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	criaTexto(novo, "Salvar Scoreboard", "Preto", "KidsPlay", 35, COMPRIMENTO_RESOLUCAO * 1 / 2, 500);
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	criaTexto(novo, "Apagar Tudo", "Preto", "KidsPlay", 35, COMPRIMENTO_RESOLUCAO * 1 / 2, 550);
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	criaTexto(novo, "Voltar", "Preto", "KidsPlay", 35, COMPRIMENTO_RESOLUCAO * 1 / 2, 600);
	Textos.push_back(novo);
	Tamanho++;
}

void Menus::MenuColocacao::setEditavel(bool Editavel)
{
	if (Editavel) {
		Indice = 1;
		Limite = 1;
	}
	else {
		Indice = 5;
		Limite = 5;
	}
}

void Menus::MenuColocacao::setEstadoAnterior(int estadoanterior)
{
	EstadoAnterior = estadoanterior;
}
