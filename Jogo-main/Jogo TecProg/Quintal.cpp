#include "Quintal.h"
#include "Jogo.h"

Quintal::Quintal() :
	Fase(),
	porta()
{
}

Quintal::~Quintal()
{
	this->limparTudo();
}

void Quintal::inicializa()
{
	srand(time(NULL));

	pGerenciadorGrafico->atualizaView( COMPRIMENTO_RESOLUCAO / 2, ALTURA_RESOLUCAO / 2 );

	gerenciadorColisoes.setListaEntidades(&listaEntidades);
	gerenciadorColisoes.setListaPersonagens(&listaPersonagens);

	Background.setGerenciadorGrafico(pGerenciadorGrafico);
	pGerenciadorGrafico->criaCorpo(&Background, COMPRIMENTO_CENARIO, ALTURA_RESOLUCAO,
		COMPRIMENTO_RESOLUCAO, ALTURA_RESOLUCAO / 2, "textures/Quintal.png");
	listaEntidades.inclua(static_cast <Entidade*> (&Background));

	Cenario* placa = new Cenario();
	placa->setGerenciadorGrafico(pGerenciadorGrafico);
	pGerenciadorGrafico->criaCorpo(placa, 104.f, 116.f, 200.f, ALTURA_RESOLUCAO - (ALTURA_PLATAFORMA + 225.f / 2), "textures/Inicio_Fim.png");
	placa->setSubTextura("textures/Inicio_Fim.png");
	listaEntidades.inclua(static_cast <Entidade*> (placa));

	Cenario* telhado = new Cenario();
	telhado->setGerenciadorGrafico(pGerenciadorGrafico);
	pGerenciadorGrafico->criaCorpo(telhado, 167.f, 272.f, COMPRIMENTO_CENARIO - 167.f / 2 + 3.f, 360.f, "textures/Inicio_Fim.png");
	telhado->setSubTextura("Inicio_Fim_2");
	listaEntidades.inclua(static_cast <Entidade*> (telhado));

	criaPlataformas();

	for (int i = 0; i < rand() % 6 + 3; i++)
	{
		Espinho* espinho = new Espinho();
		criaObstaculo(static_cast <Entidade*>(espinho),  COMPRIMENTO_ESPINHO,ALTURA_ESPINHO ,
			 rand() % (static_cast<int>(COMPRIMENTO_CENARIO - 400)) + 200, 
				ALTURA_RESOLUCAO - (ALTURA_PLATAFORMA + ALTURA_ESPINHO / 2) , "textures/Espinhos_Galhos.png");
	}

	for (int i = 0; i < rand() % 6 + 3; i++)
	{
		Teia* teia = new Teia();
		criaObstaculo(static_cast <Entidade*>(teia),  COMPRIMENTO_TEIA, ALTURA_TEIA ,
			 rand() % (static_cast<int>(COMPRIMENTO_CENARIO - 400)) + 200,
				ALTURA_RESOLUCAO - (ALTURA_PLATAFORMA + ALTURA_TEIA / 2 ), "textures/Teia.png");
		if (rand() % 2)
			teia->setSubTextura("Teia_2");
	}

	for (int i = 0; i < rand() % 4 + 3; i++)
	{
		Estatico* estatico = new Estatico();
		criaInimigo(static_cast<Personagem*>(estatico),  COMPRIMENTO_ESTATICO, ALTURA_ESTATICO ,
			 rand() % (static_cast<int>(COMPRIMENTO_CENARIO - 400)) + 200,
				rand() % static_cast<int>(ALTURA_RESOLUCAO) - (ALTURA_PLATAFORMA + ALTURA_ESTATICO / 2  ),
			"textures/Monstro_Moita.png");
		estatico->setTexturas(true);
	}

	for (int i = 0; i < rand() % 4 + 3; i++)
	{
		Passaro* passaro = new Passaro();
		passaro->setFaseAtual(this);
		criaInimigo(static_cast<Personagem*>(passaro), COMPRIMENTO_PASSARO, ALTURA_PASSARO,
			rand() % (static_cast<int>(COMPRIMENTO_CENARIO - 400)) + 200,
			rand() % static_cast<int>(ALTURA_RESOLUCAO / 2) + ALTURA_PASSARO / 2,
			"textures/Passaro.png");
		passaro->setLimites(passaro->getPosicaoX(), passaro->getPosicaoX() + 300.f);
		passaro->setPosicao(passaro->getPosicaoX() + rand() % 300, passaro->getPosicaoY());
	}

	porta.setGerenciadorGrafico(pGerenciadorGrafico);
	pGerenciadorGrafico->criaCorpo(&porta, 37.5f, 225.f, COMPRIMENTO_CENARIO - 37.5f/2 + 3.f,
		ALTURA_RESOLUCAO - (ALTURA_PLATAFORMA + 225.f/2), "textures/Inicio_Fim.png");
	porta.setSubTextura("Inicio_Fim_3");
	porta.setJogo(pJogo);
	listaEntidades.inclua(static_cast<Entidade*> (&porta));

	listaEntidades.inclua(static_cast <Entidade*> (pJogador1));
	listaPersonagens.inclua(static_cast <Personagem*> (pJogador1));

	if (pJogo->getMultiplayer())
	{
		listaEntidades.inclua(static_cast <Entidade*> (pJogador2));
		listaPersonagens.inclua(static_cast <Personagem*> (pJogador2));
	}
}

void Quintal::atualiza(float deltaTempo)
{
	listaPersonagens.limpar();
	listaEntidades.limpar();

	atualizaView();

	gerenciadorColisoes.checaColisoes();

	listaEntidades.atualiza(deltaTempo);

	listaEntidades.desenhar();
}

void Quintal::limparTudo()
{
	listaPersonagens.limparTudo();
	listaEntidades.limparTudo();
	pJogador1 = NULL;
	pJogador2 = NULL;
	pJogo = NULL;
}
void Quintal::criaPlataforma(float posx, float posy, string subtextura)
{
	Plataforma* plataforma = new Plataforma();
	criaObstaculo(plataforma, COMPRIMENTO_PLATAFORMA, ALTURA_PLATAFORMA,
		posx, posy, "textures/Plataforma_Quintal.png");
	plataforma->setSubTextura(subtextura);
}

void Quintal::criaPlataformas()
{
	criaBordas();

	criaPlataforma(900.f + COMPRIMENTO_PLATAFORMA * 0, 337.5f, "Plataforma_Quintal_4");
	for (int i = 1; i < 9; i++)
		criaPlataforma(900.f + COMPRIMENTO_PLATAFORMA * i, 337.5f, "Plataforma_Quintal_2");
	criaPlataforma(900.f + COMPRIMENTO_PLATAFORMA * 9, 337.5f, "Plataforma_Quintal_3");

	criaPlataforma(1500.f + COMPRIMENTO_PLATAFORMA * 0, 337.5f, "textures/Plataforma_Quintal.png");
	for (int i = 1; i < 9; i++)
		criaPlataforma(1500.f + COMPRIMENTO_PLATAFORMA * i, 337.5f, "Plataforma_Quintal_2");
	criaPlataforma(1500.f + COMPRIMENTO_PLATAFORMA * 9, 337.5f, "Plataforma_Quintal_5");

	criaPlataforma(500.f + COMPRIMENTO_PLATAFORMA * 0, 517.5f, "textures/Plataforma_Quintal.png");
	for (int i = 1; i < 9; i++) 
		criaPlataforma(500.f + COMPRIMENTO_PLATAFORMA * i, 517.5f, "Plataforma_Quintal_2");
	criaPlataforma(500.f + COMPRIMENTO_PLATAFORMA * 9, 517.5f, "Plataforma_Quintal_5");

	criaPlataforma(1800.f + COMPRIMENTO_PLATAFORMA * 0, 157.5f, "Plataforma_Quintal_4");
	for (int i = 1; i < 9; i++) 
		criaPlataforma(1800.f + COMPRIMENTO_PLATAFORMA * i, 157.5f, "Plataforma_Quintal_2");
	criaPlataforma(1800.f + COMPRIMENTO_PLATAFORMA * 9, 157.5f, "Plataforma_Quintal_3");

	criaPlataforma(2000.f + COMPRIMENTO_PLATAFORMA * 0, 517.5f, "textures/Plataforma_Quintal.png");
	for (int i = 1; i < 4; i++) 
		criaPlataforma(2000.f + COMPRIMENTO_PLATAFORMA * i, 517.5f, "Plataforma_Quintal_2");
	criaPlataforma(2000.f + COMPRIMENTO_PLATAFORMA * 4, 517.5f, "Plataforma_Quintal_5");
}

void Quintal::recuperar()
{	
	Background.setGerenciadorGrafico(pGerenciadorGrafico);
	pGerenciadorGrafico->criaCorpo(&Background, COMPRIMENTO_CENARIO, ALTURA_RESOLUCAO,
		COMPRIMENTO_RESOLUCAO, ALTURA_RESOLUCAO / 2, "textures/Quintal.png");
	listaEntidades.inclua(static_cast <Entidade*> (&Background));

	Cenario* placa = new Cenario();
	placa->setGerenciadorGrafico(pGerenciadorGrafico);
	pGerenciadorGrafico->criaCorpo(placa, 104.f, 116.f, 200.f, ALTURA_RESOLUCAO - (ALTURA_PLATAFORMA + 225.f / 2), "textures/Inicio_Fim.png");
	placa->setSubTextura("textures/Inicio_Fim.png");
	listaEntidades.inclua(static_cast <Entidade*> (placa));

	Cenario* telhado = new Cenario();
	telhado->setGerenciadorGrafico(pGerenciadorGrafico);
	pGerenciadorGrafico->criaCorpo(telhado, 167.f, 272.f, COMPRIMENTO_CENARIO - 167.f / 2 + 3.f, 360.f, "textures/Inicio_Fim.png");
	telhado->setSubTextura("Inicio_Fim_2");
	listaEntidades.inclua(static_cast <Entidade*> (telhado));

	criaPlataformas();

	porta.setGerenciadorGrafico(pGerenciadorGrafico);
	pGerenciadorGrafico->criaCorpo(&porta, 37.5f, 225.f, COMPRIMENTO_CENARIO - 37.5f / 2 + 3.f,
		ALTURA_RESOLUCAO - (ALTURA_PLATAFORMA + 225.f / 2), "textures/Inicio_Fim.png");
	porta.setSubTextura("Inicio_Fim_3");
	porta.setJogo(pJogo);
	listaEntidades.inclua(static_cast<Entidade*> (&porta));

	gerenciadorColisoes.setListaEntidades(&listaEntidades);
	gerenciadorColisoes.setListaPersonagens(&listaPersonagens);
	
	pJogo->InicializaQuarto();

	recuperarProjeteis(this);
	recuperarEspinhos("textures/Espinhos_Galhos.png");
	recuperarEstaticos(true, "textures/Monstro_Moita.png");
	recuperarPassaros();
	recuperarTeias();

	pJogador1->setFaseAtual(this);
	listaEntidades.inclua(static_cast<Entidade*>(pJogador1));
	listaPersonagens.inclua(static_cast <Personagem*> (pJogador1));

	if (pJogo->getMultiplayer()) {
		pJogador2->setFaseAtual(this);
		listaEntidades.inclua(static_cast<Entidade*>(pJogador2));
		listaPersonagens.inclua(static_cast <Personagem*> (pJogador2));
	}
	else
		pJogador2 = NULL;
}

void Quintal::recuperarPassaros()
{
	ifstream recuperadorPassaros("saves/Passaros.dat", ios::in);

	if (!recuperadorPassaros)
		cout << "Erro Passaros." << endl;

	int vida;
	float posx, posy, limxdir, limxesq, cooldown;

	recuperadorPassaros >> vida >> posx >> posy >> limxdir >> limxesq >> cooldown;

	while (!recuperadorPassaros.eof())
	{
		Passaro* novo = NULL;

		novo = new Passaro();
		novo->setVida(vida);
		novo->setLimites(limxesq, limxdir);
		novo->setCooldownAtaque(cooldown);
		novo->setFaseAtual(this);

		criaInimigo(static_cast <Personagem*> (novo),  COMPRIMENTO_PASSARO, ALTURA_PASSARO ,
			 posx, posy , "textures/Passaro.png");

		recuperadorPassaros >> vida >> posx >> posy >> limxdir >> limxesq >> cooldown;
	}

	recuperadorPassaros.close();
}


