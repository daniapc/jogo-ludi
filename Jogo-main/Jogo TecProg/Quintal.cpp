#include "Quintal.h"

Quintal::Quintal()
{
}

Quintal::~Quintal()
{
	for (unsigned int i = 0; i < ListaPassaros.size(); i++)
		delete ListaPassaros[i];

	ListaPassaros.clear();
}

void Quintal::checaColisoes()
{
	for (unsigned int i = 0; i < ListaPlataformas.size(); i++)
		checaColisao(&Fazendeira, ListaPlataformas[i]);

	for (unsigned int i = 0; i < ListaEspinhos.size(); i++)
	{
		sf::FloatRect hitbox_espinho = ListaEspinhos[i]->getHitbox();
		sf::FloatRect hitbox_jogador = Fazendeira.getHitbox();

		if (hitbox_jogador.intersects(hitbox_espinho))
		{ 
			cout << "Colidiu!" << endl;
		}
	}
}

void Quintal::inicializa()
{
	srand(time(NULL));

	ListaEntidades.push_back(static_cast <Entidade*> (&Cenario));
	
	Fazendeira.setJanela(Janela);
	Fazendeira.setDimensoes(sf::Vector2f(45.f, 75.f));
	Fazendeira.setOrigem();
	Fazendeira.setPosicao(sf::Vector2f(640.f, 320.f));
	//Fazendeira.setTextura("HeavyBandit_Attack_2.png");
	Fazendeira.setTeclas(sf::Keyboard::D, sf::Keyboard::A, sf::Keyboard::S, sf::Keyboard::W);
	Fazendeira.setVelocidade(sf::Vector2f(3.f, 3.f));

	Cenario.setJanela(Janela);
	Cenario.setTextura("Background.png");
	Cenario.setDimensoes(sf::Vector2f(4000.f, 720.f));
	Cenario.setPosicao(sf::Vector2f(0.f, 0.f));

	criaPlataforma(sf::Vector2f(500.f, 500.f));
	criaPlataforma(sf::Vector2f(532.f, 500.f));
	criaPlataforma(sf::Vector2f(564.f, 500.f));
	criaPlataforma(sf::Vector2f(596.f, 500.f));
	criaPlataforma(sf::Vector2f(628.f, 500.f));
	criaPlataforma(sf::Vector2f(660.f, 500.f));
	criaPlataforma(sf::Vector2f(692.f, 500.f));
	criaPlataforma(sf::Vector2f(724.f, 500.f));
	criaPlataforma(sf::Vector2f(756.f, 500.f));

	for (int i = 0; i < rand()%6+3; i++)
	{
		criaEspinho(sf::Vector2f(rand() % 3975 + 25, 720 - (32.f + 16.f)));
	}

	Plataforma* nova = NULL;
	nova = new Plataforma();
	nova->getCorpo().setFillColor(sf::Color::Transparent);
	nova->setDimensoes(sf::Vector2f(4000.f, 32.f));
	nova->setPosicao(sf::Vector2f(2000.f, 704.f));
	nova->setOrigem();
	nova->setJanela(Janela);
	ListaPlataformas.push_back(nova);
	ListaEntidades.push_back(static_cast <Entidade*> (nova));

	ListaEntidades.push_back(static_cast <Entidade*> (&Fazendeira));
}

void Quintal::desenhar()
{
	for (unsigned int i = 0; i < ListaEntidades.size(); i++)
		ListaEntidades[i]->desenhar();
}

void Quintal::criaPassaro()
{
	Passaro* novo = NULL;
	novo = new Passaro();

	//Setar posição aleatoriamente

	ListaPassaros.push_back(novo);
	ListaEntidades.push_back(static_cast <Entidade*> (novo));
}

void Quintal::criaEspinho(sf::Vector2f posicao)
{
	Espinho* novo = NULL; 
	novo = new Espinho();

	//Setar posição aleatoriamente
	novo->setPosicao(posicao);
	novo->setDimensoes(sf::Vector2f(50.f, 32.f));
	novo->setOrigem();
	novo->setJanela(Janela);
	novo->setTextura("");

	ListaEspinhos.push_back(novo);
	ListaEntidades.push_back(novo);
}

