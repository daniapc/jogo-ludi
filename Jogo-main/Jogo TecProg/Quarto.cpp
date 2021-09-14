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
	srand(time(NULL));

	pGerenciadorGrafico->atualizaView( COMPRIMENTO_RESOLUCAO / 2, ALTURA_RESOLUCAO / 2 );

	gerenciadorColisoes.setListaEntidades(&listaEntidades);
	gerenciadorColisoes.setListaPersonagens(&listaPersonagens);

	Background.setGerenciadorGrafico(pGerenciadorGrafico);
	pGerenciadorGrafico->criaCorpo(&Background, COMPRIMENTO_CENARIO, ALTURA_RESOLUCAO,
		COMPRIMENTO_RESOLUCAO, ALTURA_RESOLUCAO / 2, "textures/Quarto.png");
	listaEntidades.inclua(static_cast <Entidade*> (&Background));

	criaPlataformas();

	for (int i = 0; i < rand() % 4 + 3; i++)
	{
		Fantasma* fantasma = new Fantasma();
		criaInimigo(static_cast<Personagem*>(fantasma),  COMPRIMENTO_FANTASMA, ALTURA_FANTASMA ,
			 rand() % (static_cast<int>(COMPRIMENTO_CENARIO - 400)) + 200,
				rand() % static_cast<int>(ALTURA_RESOLUCAO / 2) + ALTURA_FANTASMA / 2 ,
			"textures/Fantasma.png");
		fantasma->setLimitesX(fantasma->getPosicaoX() , fantasma->getPosicaoX() + 200.0f);
		
	}
	for (int i = 0; i < rand() % 4 + 3; i++)
	{
		Estatico* estatico = new Estatico();
		criaInimigo(static_cast<Personagem*>(estatico),  COMPRIMENTO_ESTATICO, ALTURA_ESTATICO ,
			 rand() % (static_cast<int>(COMPRIMENTO_CENARIO - 400)) + 200,
				rand() % static_cast<int>(ALTURA_RESOLUCAO) - (ALTURA_PLATAFORMA + ALTURA_ESTATICO / 2 ),
			"textures/Monstro_Roupas.png");
		estatico->setTexturas(false);
	}

	for (int i = 0; i < rand() % 6 + 3; i++)
	{
		Teia* teia = new Teia();
		criaObstaculo(static_cast <Entidade*>(teia), COMPRIMENTO_TEIA, ALTURA_TEIA ,
			 rand() % (static_cast<int>(COMPRIMENTO_CENARIO - 400)) + 200,
				ALTURA_RESOLUCAO - (ALTURA_PLATAFORMA + ALTURA_TEIA / 2) , "textures/Teia.png");
		if (rand() % 2)
			teia->setSubTextura("Teia_2");
	}

	for (int i = 0; i < rand() % 6 + 3; i++)
	{
		Espinho* espinho = new Espinho();
		criaObstaculo(static_cast <Entidade*>(espinho),  COMPRIMENTO_ESPINHO, ALTURA_ESPINHO ,
			 rand() % (static_cast<int>(COMPRIMENTO_CENARIO - 400)) + 200,
				ALTURA_RESOLUCAO - (ALTURA_PLATAFORMA + ALTURA_ESPINHO / 2) , "textures/Espinhos_Materiais.png");
	}
	
	Chefao* chefao = NULL;
	chefao = new Chefao();
	chefao->setFaseAtual(this);
	criaInimigo(static_cast <Personagem*>(chefao),  COMPRIMENTO_CHEFAO/10, ALTURA_CHEFAO/10 ,
				COMPRIMENTO_CENARIO - 200.f, ALTURA_RESOLUCAO - ALTURA_CHEFAO + ALTURA_CHEFAO/10 -ALTURA_PLATAFORMA, 
		"textures/Bicho_Papao.png");
	chefao->setSubTextura("Bicho_Papao_7");

	if (pJogador1 == NULL)
		cout << "Eh null" << endl;

	listaEntidades.inclua(static_cast <Entidade*> (pJogador1));
	listaPersonagens.inclua(static_cast <Personagem*> (pJogador1));
	if (pJogo->getMultiplayer())
	{
		listaEntidades.inclua(static_cast <Entidade*> (pJogador2));
		listaPersonagens.inclua(static_cast <Personagem*> (pJogador2));
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
		ChefaoMorreu = false;
		Porta* cabideiro = new Porta();
		cabideiro->setGerenciadorGrafico(pGerenciadorGrafico);
		pGerenciadorGrafico->criaCorpo(cabideiro, 150.f, 300.f, COMPRIMENTO_CENARIO - 150.f,
			ALTURA_RESOLUCAO - (ALTURA_PLATAFORMA + 150.f), "textures/Inicio_Fim.png");
		cabideiro->setSubTextura("Inicio_Fim_5");
		cabideiro->setJogo(pJogo);
		listaEntidades.inclua(static_cast<Entidade*> (cabideiro));
	}

	desenhar();
}

void Quarto::limparTudo()
{
	listaPersonagens.limparTudo();
	listaEntidades.limparTudo();
	pJogador1 = NULL;
	pJogador2 = NULL;
	pJogo = NULL;
}

void Quarto::recuperar()
{
	Background.setGerenciadorGrafico(pGerenciadorGrafico);
	pGerenciadorGrafico->criaCorpo(&Background, COMPRIMENTO_CENARIO, ALTURA_RESOLUCAO,
		COMPRIMENTO_RESOLUCAO, ALTURA_RESOLUCAO / 2, "textures/Quarto.png");
	listaEntidades.inclua(static_cast<Entidade*> (&Background));

	criaPlataformas();

	gerenciadorColisoes.setListaEntidades(&listaEntidades);
	gerenciadorColisoes.setListaPersonagens(&listaPersonagens);

	recuperarProjeteis(this);
	recuperarEstaticos(false, "textures/Monstro_Roupas.png");
	recuperarFantasmas();
	recuperarTeias();
	recuperarEspinhos("textures/Espinhos_Materiais.png");
	recuperarChefao();

	pJogador1->setFaseAtual(this);
	listaEntidades.inclua(static_cast<Entidade*>(pJogador1));
	listaPersonagens.inclua(static_cast <Personagem*> (pJogador1));

	if (pJogo->getMultiplayer()) {
		pJogador2->setFaseAtual(this);
		listaEntidades.inclua(static_cast<Entidade*>(pJogador2));
		listaPersonagens.inclua(static_cast <Personagem*> (pJogador2));
	}
	else
	{
		pJogador2 = NULL;
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
			 posx, posy , "textures/Fantasma.png");

	}

	recuperadorFantasmas.close();
}

void Quarto::recuperarChefao()
{
	ifstream recuperadorChefao("saves/Chefao.dat", ios::in);

	if (!recuperadorChefao)
		cout << "Erro Chefao." << endl;

	int vida;
	recuperadorChefao >> vida;

	if (recuperadorChefao.eof()) {
		ChefaoMorreu = true;
	}
	else {
		Chefao* novo = NULL;
		float posx, posy, cooldown, estadochefao;

		recuperadorChefao >> posx >> posy >> cooldown >> estadochefao;

		cout << "vida: " << vida << endl;

		novo = new Chefao();
		novo->setVida(vida);
		novo->setCooldownAtaque(cooldown);
		novo->setFaseAtual(this);
		novo->setEstado(estadochefao);

		criaInimigo(static_cast <Personagem*> (novo), COMPRIMENTO_CHEFAO, ALTURA_CHEFAO,
			posx, posy, "textures/Bicho_Papao.png");

		if (estadochefao == 0) {
			novo->setDimensoes(COMPRIMENTO_CHEFAO / 10, ALTURA_CHEFAO / 10);
			novo->setSubTextura("Bicho_Papao_7");
		}
		else if (estadochefao == 2) {
			novo->setCooldownAtaqueMax(0.5f);
		}
	}

}

void Quarto::setChefaoMorreu(bool chefaomorreu)
{
	ChefaoMorreu = chefaomorreu;
}

void Quarto::criaPlataforma(float posx, float posy, string subtextura)
{
	Plataforma* plataforma = new Plataforma();
	criaObstaculo(plataforma, COMPRIMENTO_PLATAFORMA, ALTURA_PLATAFORMA,
		posx, posy, "textures/Plataforma_Quarto.png");
	plataforma->setSubTextura(subtextura);
}

void Quarto::criaPlataformas()
{
	criaBordas();
	for (int i = 0; i < 10; i++) {
		criaPlataforma(900.f + COMPRIMENTO_PLATAFORMA * i, 337.5f , "Plataforma_Quarto_2");
	}
	for (int i = 0; i < 10; i++) {
		criaPlataforma(1500.f + COMPRIMENTO_PLATAFORMA * i, 337.5f, "Plataforma_Quarto_5");
	}
	for (int i = 0; i < 10; i++) {
		criaPlataforma(500.f + COMPRIMENTO_PLATAFORMA * i, 517.5f , "Plataforma_Quarto_4");
	}
	for (int i = 0; i < 10; i++) {
		criaPlataforma(1800.f + COMPRIMENTO_PLATAFORMA * i, 157.5f, "Plataforma_Quarto_3");
	}

	for (int i = 0; i < 5; i++) {
		criaPlataforma(2000.f + COMPRIMENTO_PLATAFORMA * i, 517.5f, "textures/Plataforma_Quarto.png");
	}
}

