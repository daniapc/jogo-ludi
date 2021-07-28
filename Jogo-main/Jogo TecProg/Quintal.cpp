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

void Quintal::Inicializa()
{
	ListaEntidades.push_back(static_cast <Entidade*> (&Cenario));

	Fazendeira.setJanela(Janela);
	Fazendeira.setDimensoes(sf::Vector2f(45.f, 75.f));
	Fazendeira.setPosicao(sf::Vector2f(0.f, 0.f));
	Fazendeira.setTextura("HeavyBandit_Attack_2.png");
	Fazendeira.setTeclas(sf::Keyboard::D, sf::Keyboard::A, sf::Keyboard::S, sf::Keyboard::W);
	Fazendeira.setVelocidade(sf::Vector2f(0.1f, 0.1f));

	Cenario.setJanela(Janela);
	Cenario.setTextura("Background.png");
	Cenario.setDimensoes(sf::Vector2f(4000.f, 720.f));
	Cenario.setPosicao(sf::Vector2f(0.f, 0.f));

	Plataforma* nova = NULL;


	nova = new Plataforma();
	nova->setDimensoes(sf::Vector2f(32.f, 32.f));
	nova->setPosicao(sf::Vector2f(500.f, 500.f));
	nova->setTextura("ground_top.png");
	nova->setJanela(Janela);
	ListaPlataformas.push_back(nova);
	ListaEntidades.push_back(static_cast <Entidade*> (nova));

	nova = new Plataforma();
	nova->setDimensoes(sf::Vector2f(32.f, 32.f));
	nova->setPosicao(sf::Vector2f(532.f, 500.f));
	nova->setTextura("ground_top.png");
	nova->setJanela(Janela);
	ListaPlataformas.push_back(nova);
	ListaEntidades.push_back(static_cast <Entidade*> (nova));

	nova = new Plataforma();
	nova->setDimensoes(sf::Vector2f(32.f, 32.f));
	nova->setPosicao(sf::Vector2f(564.f, 500.f));
	nova->setTextura("ground_top.png");
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
