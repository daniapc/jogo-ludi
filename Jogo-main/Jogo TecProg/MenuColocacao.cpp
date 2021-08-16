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
	cout << "Indice: " << Indice << endl;
	Textos[Indice]->setCor("Vermelho");

	if (Digitando)
	{
			if (tecla == 13)
			{
				Textos[Indice]->setCor("Preto");
				Textos[5]->setCor("Vermelho");
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
				cout << ss.str() << endl;
				Textos[Indice]->setMensagem(saux);
			}
	}
	 
	else {
		cout << "Digitando = " << Digitando << endl;
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
					Textos[Indice]->setCor("Preto");
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
	Texto* novo = new Texto();
	novo->setCor("Azul");
	novo->setDimensao(24);
	novo->setMensagem("Pontuacao:");
	novo->setPosicoes(COMPRIMENTO_RESOLUCAO / 4, 150);
	novo->setFonte("KidsPlay");
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	novo->setCor("Preto");
	novo->setDimensao(24);
	novo->setMensagem("0 - Vazio");
	novo->setPosicoes(COMPRIMENTO_RESOLUCAO / 4, 200);
	novo->setFonte("KidsPlay");
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	novo->setCor("Preto");
	novo->setDimensao(24);
	novo->setMensagem("0 - Vazio");
	novo->setPosicoes(COMPRIMENTO_RESOLUCAO / 4, 250);
	novo->setFonte("KidsPlay");
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	novo->setCor("Preto");
	novo->setDimensao(24);
	novo->setMensagem("0 - Vazio");
	novo->setPosicoes(COMPRIMENTO_RESOLUCAO / 4, 300);
	novo->setFonte("KidsPlay");
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	novo->setCor("Preto");
	novo->setDimensao(24);
	novo->setMensagem("0 - Vazio");
	novo->setPosicoes(COMPRIMENTO_RESOLUCAO / 4, 350);
	novo->setFonte("KidsPlay");
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	novo->setCor("Preto");
	novo->setDimensao(24);
	novo->setMensagem("Salvar Scoreboard");
	novo->setPosicoes(COMPRIMENTO_RESOLUCAO / 4, 500);
	novo->setFonte("KidsPlay");
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	novo->setCor("Preto");
	novo->setDimensao(24);
	novo->setMensagem("Apagar Tudo");
	novo->setPosicoes(COMPRIMENTO_RESOLUCAO / 4, 550);
	novo->setFonte("KidsPlay");
	Textos.push_back(novo);
	Tamanho++;

	novo = new Texto();
	novo = novo;
	novo->setCor("Preto");
	novo->setDimensao(24);
	novo->setMensagem("Voltar");
	novo->setPosicoes(COMPRIMENTO_RESOLUCAO / 4, 600);
	novo->setFonte("KidsPlay");
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
