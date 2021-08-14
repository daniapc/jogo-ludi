#include "MenuColocacao.h"
#include "Jogo.h"

MenuColocacao::MenuColocacao(unsigned int comprimento, unsigned int altura, int tamanho, Jogo* jg):
	Menu(comprimento, altura, tamanho, jg),
	EstadoAnterior(0)
{	
	Inicializa();
}

MenuColocacao::~MenuColocacao()
{
}

void MenuColocacao::LoopMenu(char tecla)
{
	menu[Indice].setFillColor(sf::Color::Red);

	if (Digitando)
	{
			if (tecla == 13)
			{
				menu[Indice].setFillColor(sf::Color::Green);
				menu[5].setFillColor(sf::Color::Red);
				Indice = 5;
				Digitando = false;
				Nome.clear();
			}
			else
			{
				string saux;
				stringstream ss;

				if (tecla == '\b') {
					if (Nome.getSize() != 0)
						Nome.erase(Nome.getSize() - 1);
				}
				else if (tecla > 31 && tecla < 128) {
					Nome.insert(Nome.getSize(), tecla);
				}

				ss << jogo->getFazendeira()->getPontuacao();

				saux = ss.str() + " - " + Nome;
				cout << ss.str() << endl;
				menu[Indice].setString(saux);
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
				menu[Indice].setString("0 - ");
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
						string saux = menu[i].getString();
						while (saux.back() == ' ')
							saux.pop_back();

						gravadorColocacao << saux << '\n';
					}


					gravadorColocacao.close();
				}
				break;
				case 6:
					menu[1].setString("0 - Vazio");
					menu[2].setString("0 - Vazio");
					menu[3].setString("0 - Vazio");
					menu[4].setString("0 - Vazio");
					break;
				case 7:
					menu[Indice].setFillColor(sf::Color::Green);
					jogo->setEstado(EstadoAnterior);
					break;
				}

		}
	}
}

void MenuColocacao::Recupera() 
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
			menu[i].setString(string);
			i++;
			string = "";
		}
	}

	recuperadorColocacao.close();

}

void MenuColocacao::Inicializa() 
{
	
	Digitando = false;

	menu = new sf::Text[Tamanho];
	menu[0].setFillColor(sf::Color::Green);
	menu[0].setCharacterSize(24);
	menu[0].setString("Pontuacao:");
	menu[0].setPosition(sf::Vector2f(COMPRIMENTO_RESOLUCAO / 4, 150));
	menu[0].setFont(Fonte);
	menu[1].setFillColor(sf::Color::Green);
	menu[1].setCharacterSize(24);
	menu[1].setString("0 - Vazio");
	menu[1].setPosition(sf::Vector2f(COMPRIMENTO_RESOLUCAO / 4, 200));
	menu[1].setFont(Fonte);
	menu[2].setFillColor(sf::Color::Green);
	menu[2].setCharacterSize(24);
	menu[2].setString("0 - Vazio");
	menu[2].setPosition(sf::Vector2f(COMPRIMENTO_RESOLUCAO / 4, 250));
	menu[2].setFont(Fonte);
	menu[3].setFillColor(sf::Color::Green);
	menu[3].setCharacterSize(24);
	menu[3].setString("0 - Vazio");
	menu[3].setPosition(sf::Vector2f(COMPRIMENTO_RESOLUCAO / 4, 300));
	menu[3].setFont(Fonte);
	menu[4].setFillColor(sf::Color::Green);
	menu[4].setCharacterSize(24);
	menu[4].setString("0 - Vazio");
	menu[4].setPosition(sf::Vector2f(COMPRIMENTO_RESOLUCAO / 4, 350));
	menu[4].setFont(Fonte);
	menu[5].setFillColor(sf::Color::Green);
	menu[5].setCharacterSize(24);
	menu[5].setString("Salvar Pontuação");
	menu[5].setPosition(sf::Vector2f(COMPRIMENTO_RESOLUCAO / 4, 500));
	menu[5].setFont(Fonte);
	menu[6].setFillColor(sf::Color::Green);
	menu[6].setCharacterSize(24);
	menu[6].setString("Apagar Tudo");
	menu[6].setPosition(sf::Vector2f(COMPRIMENTO_RESOLUCAO / 4, 550));
	menu[6].setFont(Fonte);
	menu[7].setFillColor(sf::Color::Green);
	menu[7].setCharacterSize(24);
	menu[7].setString("Voltar");
	menu[7].setPosition(sf::Vector2f(COMPRIMENTO_RESOLUCAO / 4, 600));
	menu[7].setFont(Fonte);

}

void MenuColocacao::setEditavel(bool Editavel)
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

void MenuColocacao::setEstadoAnterior(int estadoanterior)
{
	EstadoAnterior = estadoanterior;
}
