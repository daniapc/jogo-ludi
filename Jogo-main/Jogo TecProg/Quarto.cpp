#include "Quarto.h"
#include "Jogo.h"

Quarto::Quarto() :
	Fase(), ChefaoMorreu(false)
{
}

Quarto::~Quarto()
{
	this->limparTudo();
}

void Quarto::inicializa()
{
	//pView->setCenter(sf::Vector2f(COMPRIMENTO_RESOLUCAO/2, ALTURA_RESOLUCAO/2));
	pGerenciadorGrafico->atualizaView( COMPRIMENTO_RESOLUCAO / 2, ALTURA_RESOLUCAO / 2 );

	srand(time(NULL));

	gerenciadorColisoes.setListaEntidades(&listaEntidades);
	gerenciadorColisoes.setListaPersonagens(&listaPersonagens);

	listaEntidades.inclua(static_cast <Entidade*> (&Background));

	criaPlataformas();

	Background.setGerenciadorGrafico(pGerenciadorGrafico);
	pGerenciadorGrafico->criaCorpo(&Background, COMPRIMENTO_CENARIO, ALTURA_RESOLUCAO,
		COMPRIMENTO_RESOLUCAO, ALTURA_RESOLUCAO / 2, "textures/Background_quarto.jpg");
	Background.setTextura("textures/Background_quarto.jpg");
	Background.setDimensoes( COMPRIMENTO_CENARIO, ALTURA_RESOLUCAO) ;
	Background.setPosicao( COMPRIMENTO_RESOLUCAO, ALTURA_RESOLUCAO / 2 );




	for (int i = 0; i < rand() % 4 + 3; i++)
	{
		Fantasma* fantasma = new Fantasma();
		criaInimigo(static_cast<Personagem*>(fantasma),  COMPRIMENTO_FANTASMA, ALTURA_FANTASMA ,
			 rand() % (static_cast<int>(COMPRIMENTO_CENARIO - 400)) + 200,
				rand() % static_cast<int>(ALTURA_RESOLUCAO / 2) + ALTURA_FANTASMA / 2 ,
			"textures/Fantasma_direita.png");
		fantasma->setLimitesX(fantasma->getPosicaoX() , fantasma->getPosicaoX() + 200.0f);
		
	}
	for (int i = 0; i < rand() % 4 + 3; i++)
	{
		Estatico* estatico = new Estatico();
		criaInimigo(static_cast<Personagem*>(estatico),  COMPRIMENTO_ESTATICO, ALTURA_ESTATICO ,
			 rand() % (static_cast<int>(COMPRIMENTO_CENARIO - 400)) + 200,
				rand() % static_cast<int>(ALTURA_RESOLUCAO) - (ALTURA_PLATAFORMA + ALTURA_ESTATICO / 2 ),
			"textures/Estatico_vulneravel_quarto.png");
	}

	for (int i = 0; i < rand() % 6 + 3; i++)
	{
		Teia* teia = new Teia();
		criaObstaculo(static_cast <Entidade*>(teia), COMPRIMENTO_TEIA, ALTURA_TEIA ,
			 rand() % (static_cast<int>(COMPRIMENTO_CENARIO - 400)) + 200,
				ALTURA_RESOLUCAO - (ALTURA_PLATAFORMA + ALTURA_TEIA / 2) , "");
	}

	for (int i = 0; i < rand() % 6 + 3; i++)
	{
		Espinho* espinho = new Espinho();
		criaObstaculo(static_cast <Entidade*>(espinho),  COMPRIMENTO_ESPINHO, ALTURA_ESPINHO ,
			 rand() % (static_cast<int>(COMPRIMENTO_CENARIO - 400)) + 200,
				ALTURA_RESOLUCAO - (ALTURA_PLATAFORMA + ALTURA_ESPINHO / 2) , "");
	}
	
	//criaChefao(sf::Vector2f(2000.f,600.f));

	Chefao* chefao = NULL;
	chefao = new Chefao();
	chefao->setFaseAtual(this);
	criaInimigo(static_cast <Personagem*>(chefao),  COMPRIMENTO_CHEFAO, ALTURA_CHEFAO ,
				 2000.f, 600.f , "");


	if (pFazendeira == NULL)
		cout << "Eh null" << endl;

	listaEntidades.inclua(static_cast <Entidade*> (pFazendeira));
	listaPersonagens.inclua(static_cast <Personagem*> (pFazendeira));
	if (pJogo->getMultiplayer())
	{
		listaEntidades.inclua(static_cast <Entidade*> (pBruxo));
		listaPersonagens.inclua(static_cast <Personagem*> (pBruxo));
	}

}

void Quarto::desenhar()
{
	listaEntidades.desenhar();
}

void Quarto::atualiza(float deltaTempo)
{
	listaPersonagens.limpar();
	listaEntidades.limpar();

	atualizaView();

	gerenciadorColisoes.checaColisoes();

	listaEntidades.atualiza(deltaTempo);

	if (ChefaoMorreu)
	{
		cout << "Sumonando porta." << endl;
		ChefaoMorreu = false;
		Porta* cabideiro = new Porta();

		cabideiro->setGerenciadorGrafico(pGerenciadorGrafico);
		pGerenciadorGrafico->criaCorpo(cabideiro, 50.f, 100.f, COMPRIMENTO_CENARIO - 150.f,
			ALTURA_RESOLUCAO - (ALTURA_PLATAFORMA + 50.f), "");
		cabideiro->setPosicao(COMPRIMENTO_CENARIO - 150.f, ALTURA_RESOLUCAO - (ALTURA_PLATAFORMA + 50.f));
		cabideiro->setDimensoes(50.f, 100.f);
		cabideiro->setTextura("");
		cabideiro->setJogo(pJogo);
		listaEntidades.inclua(static_cast<Entidade*> (cabideiro));

		
		listaEntidades.inclua(static_cast<Entidade*> (cabideiro));
	}

	desenhar();
}

void Quarto::limparTudo()
{
	listaPersonagens.limparTudo();
	listaEntidades.limparTudo();
	//pView = NULL;
	pFazendeira = NULL;
	pBruxo = NULL;
	pJogo = NULL;
}

void Quarto::recuperar()
{
	listaEntidades.inclua(static_cast<Entidade*> (&Background));

	listaEntidades.inclua(static_cast <Entidade*> (&Background));
	Background.setGerenciadorGrafico(pGerenciadorGrafico);
	pGerenciadorGrafico->criaCorpo(&Background, COMPRIMENTO_CENARIO, ALTURA_RESOLUCAO,
		COMPRIMENTO_RESOLUCAO, ALTURA_RESOLUCAO / 2, "textures/Background_quarto.jpg");
	Background.setTextura("textures/Background_quarto.jpg");
	Background.setDimensoes(COMPRIMENTO_CENARIO, ALTURA_RESOLUCAO);
	Background.setPosicao(COMPRIMENTO_RESOLUCAO, ALTURA_RESOLUCAO / 2);

	gerenciadorColisoes.setListaEntidades(&listaEntidades);
	gerenciadorColisoes.setListaPersonagens(&listaPersonagens);
	recuperarProjeteis(this);
	recuperarEstaticos();
	recuperarFantasmas();
	recuperarTeias();
	recuperarEspinhos();
	recuperarChefao();

	criaPlataformas();

	pFazendeira->setFaseAtual(this);
	listaEntidades.inclua(static_cast<Entidade*>(pFazendeira));
	listaPersonagens.inclua(static_cast <Personagem*> (pFazendeira));

	if (pJogo->getMultiplayer()) {
		pBruxo->setFaseAtual(this);
		listaEntidades.inclua(static_cast<Entidade*>(pBruxo));
		listaPersonagens.inclua(static_cast <Personagem*> (pBruxo));
	}
	else
	{
		pBruxo = NULL;
	}

}

void Quarto::recuperarFantasmas()
{
	ifstream recuperadorFantasmas("saves/Fantasmas.dat", ios::in);

	if (!recuperadorFantasmas)
		cout << "Erro Fantasmas." << endl;

	while (!recuperadorFantasmas.eof())
	{
		Fantasma* novo = NULL;
		int vida;
		float posx, posy, limxdir, limxesq, cooldown;

		recuperadorFantasmas >> vida >> posx >> posy >> limxdir >> limxesq >> cooldown;

		novo = new Fantasma();
		novo->setVida(vida);
		novo->setLimitesX(limxesq, limxdir);
		novo->setCooldownAtaque(cooldown);

		criaInimigo(static_cast <Personagem*> (novo),  COMPRIMENTO_FANTASMA, ALTURA_FANTASMA ,
			 posx, posy , "textures/Fantasma_direita.png");

	}

	recuperadorFantasmas.close();
}

void Quarto::recuperarChefao()
{
	ifstream recuperadorChefao("saves/Chefao.dat", ios::in);

	if (!recuperadorChefao)
		cout << "Erro Chefao." << endl;

	if (recuperadorChefao.eof())
		ChefaoMorreu = true;

	while (!recuperadorChefao.eof())
	{
		Chefao* novo = NULL;
		int vida;
		float posx, posy, cooldown;

		recuperadorChefao >> vida >> posx >> posy >> cooldown;

		novo = new Chefao();
		novo->setVida(vida);
		novo->setCooldownAtaque(cooldown);
		novo->setFaseAtual(this);

		criaInimigo(static_cast <Personagem*> (novo),  COMPRIMENTO_CHEFAO, ALTURA_CHEFAO ,
			 posx, posy, "") ;

	}

}

void Quarto::setChefaoMorreu(bool chefaomorreu)
{
	ChefaoMorreu = chefaomorreu;
}

void Quarto::criaPlataforma(float posx, float posy)
{
	Plataforma* plataforma = new Plataforma();
	criaObstaculo(plataforma, COMPRIMENTO_PLATAFORMA, ALTURA_PLATAFORMA,
		posx, posy, "textures/Estante_meio.png");
}

void Quarto::criaPlataformas()
{
	criaBordas();
	//Plataformas específicas
	for (int i = 0; i < 10; i++) {
		criaPlataforma(900.f + COMPRIMENTO_PLATAFORMA * i, 337.5f);
	}
	for (int i = 0; i < 10; i++) {
		criaPlataforma(1500.f + COMPRIMENTO_PLATAFORMA * i, 337.5f);
	}
	for (int i = 0; i < 10; i++) {
		criaPlataforma(500.f + COMPRIMENTO_PLATAFORMA * i, 517.5f);
	}
	for (int i = 0; i < 10; i++) {
		criaPlataforma(1800.f + COMPRIMENTO_PLATAFORMA * i, 157.5f);
	}

	for (int i = 0; i < 5; i++) {
		criaPlataforma(2000.f + COMPRIMENTO_PLATAFORMA * i, 517.5f);
	}
}

