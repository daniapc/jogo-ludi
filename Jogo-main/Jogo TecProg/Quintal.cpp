#include "Quintal.h"

Quintal::Quintal()
{
}

Quintal::~Quintal()
{
	for (unsigned int i = 0; i < ListaPassaros.size(); i++)
		delete ListaPassaros[i];
	ListaPassaros.clear();
	for (unsigned int i = 0; i < ListaEspinhos.size(); i++)
		delete ListaEspinhos[i];
	ListaEspinhos.clear();
	for (unsigned int i = 0; i < ListaPlataformas.size(); i++)
		delete ListaPlataformas[i];
	ListaPlataformas.clear();
	for (unsigned int i = 0; i < ListaFantasmas.size(); i++)
		delete ListaFantasmas[i];
	ListaFantasmas.clear();
}

void Quintal::inicializa()
{
	srand(time(NULL));

	listaEntidades.inclua(static_cast <Entidade*> (&Cenario));
	
	Fazendeira.setJanela(Janela);
	Fazendeira.setDimensoes(sf::Vector2f(COMPRIMENTO_JOGADOR, ALTURA_JOGADOR));
	Fazendeira.setOrigem();
	Fazendeira.setPosicao(sf::Vector2f(640.f, 320.f));
	Fazendeira.setTextura("Fazendeira.png");
	Fazendeira.setTeclas(sf::Keyboard::D, sf::Keyboard::A, sf::Keyboard::W, sf::Keyboard::Space);
	Fazendeira.setVelocidade(400.f);
	Fazendeira.setAlturaPulo(400.f);
	gerenciadorFisica.setFazendeira(&Fazendeira);

	Cenario.setJanela(Janela);
	Cenario.setTextura("Background.png");
	Cenario.setDimensoes(sf::Vector2f(COMPRIMENTO_CENARIO, ALTURA_RESOLUCAO));
	Cenario.setPosicao(sf::Vector2f(0.f, 0.f));

	criaPlataformas();

	//Incluindo Espinhos
	for (int i = 0; i < rand()%6+3; i++)
	{
		//Perguntar se todos os espinhos devem ser necessariamente aleatórios
		criaEspinho(sf::Vector2f(rand() % (static_cast<int>(COMPRIMENTO_CENARIO-400)) + 200,
			ALTURA_RESOLUCAO - (ALTURA_PLATAFORMA + ALTURA_ESPINHO/2)));
	}

	criaFantasma(sf::Vector2f(500.f, 500.f));

	listaEntidades.inclua(static_cast <Entidade*> (&Fazendeira));
}

void Quintal::desenhar()
{
	listaEntidades.desenhar();
}

void Quintal::atualiza(float deltaTempo)
{
	atualizaView();
	
	gerenciadorFisica.checaColisoes();

	Fazendeira.atualiza(deltaTempo);

	atualizaFantasmas(deltaTempo);

	desenhar();
}

void Quintal::atualizaFantasmas(float deltaTempo)
{
	for (unsigned int i = 0; i < ListaFantasmas.size(); i++)
	{
		ListaFantasmas[i]->atualiza(deltaTempo);
	}
}

void Quintal::criaPassaro()
{
	Passaro* novo = NULL;
	novo = new Passaro();

	//Setar posição aleatoriamente

	ListaPassaros.push_back(novo);
	listaEntidades.inclua(static_cast <Entidade*> (novo));
}

void Quintal::criaEspinho(sf::Vector2f posicao)
{
	Espinho* novo = NULL; 
	novo = new Espinho();

	//Setar posição aleatoriamente
	novo->setPosicao(posicao);
	novo->setDimensoes(sf::Vector2f(COMPRIMENTO_ESPINHO, ALTURA_ESPINHO));
	novo->setOrigem();
	novo->setJanela(Janela);
	novo->setTextura("");

	ListaEspinhos.push_back(novo);
	listaEntidades.inclua(static_cast <Entidade*>(novo));
	gerenciadorFisica.incluaEspinho(novo);
}

void Quintal::criaFantasma(sf::Vector2f posicao)
{
	Fantasma* novo = NULL;
	novo = new Fantasma();

	novo->setPosicao(posicao);
	novo->setDimensoes(sf::Vector2f(COMPRIMENTO_FANTASMA,ALTURA_FANTASMA));
	novo->setOrigem();
	novo->setJanela(Janela);
	novo->setTextura("");

	ListaFantasmas.push_back(novo);
	listaEntidades.inclua(static_cast <Entidade*>(novo));
	gerenciadorFisica.incluaFantasma(novo);

	novo->inicializa();
	novo->setVelocidade(200.f);
}

void Quintal::criaPlataformas(){

	//Plataforma principal de baixo.
	criaChao();

	//Plataformas específicas
	for (int i = 0; i < 9; i++){
		criaPlataforma(sf::Vector2f(500.f + COMPRIMENTO_PLATAFORMA*i, 300.f));
	}
	for (int i = 0; i < 9; i++){
		criaPlataforma(sf::Vector2f(1500.f + COMPRIMENTO_PLATAFORMA*i, 300.f));
	}
	for (int i = 0; i < 9; i++){
		criaPlataforma(sf::Vector2f(800.f + COMPRIMENTO_PLATAFORMA*i, 450.f));
	}
	for (int i = 0; i < 9; i++){
		criaPlataforma(sf::Vector2f(1800.f + COMPRIMENTO_PLATAFORMA*i, 150.f));
	}

}

