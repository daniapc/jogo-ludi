#include "Fase.h"
#include "Jogo.h"
#include "Jogador.h"

Fase::Fase():
	Ente(),
	pJogador1(NULL),
	pJogador2(NULL),
	pJogo(NULL)
{
}

Fase::~Fase()
{
}

void Fase::criaObstaculo(Entidade* pentidade, float dimx, float dimy, float posx, float posy, const string textura)
{
	pentidade->setGerenciadorGrafico(pGerenciadorGrafico);
	pGerenciadorGrafico->criaCorpo(static_cast<Entidade*>(pentidade), dimx, dimy, posx, posy, textura);
	listaEntidades.inclua(static_cast <Entidade*>(pentidade));
}

void Fase::criaInimigo(Personagem* ppersonagem, float dimx, float dimy, float posx, float posy, const string textura)
{
	ppersonagem->setGerenciadorGrafico(pGerenciadorGrafico);
	pGerenciadorGrafico->criaCorpo(static_cast <Entidade*>(ppersonagem), dimx, dimy, posx, posy, textura);
	listaEntidades.inclua(static_cast <Entidade*>(ppersonagem));
	listaPersonagens.inclua(static_cast <Personagem*> (ppersonagem));
}

void Fase::criaBordas()
{

	Plataforma* chao = new Plataforma();
	criaObstaculo(chao, COMPRIMENTO_CENARIO, ALTURA_PLATAFORMA,
		COMPRIMENTO_CENARIO / 2, ALTURA_RESOLUCAO - ALTURA_PLATAFORMA / 2,
		"textures/Bruxo_menu.png"); //Aproveitando apenas o espaço vazio 
	chao->setSubTextura("Transparente");
	Plataforma* esquerda = new Plataforma();
	criaObstaculo(esquerda, COMPRIMENTO_PLATAFORMA, ALTURA_RESOLUCAO*2,
		-COMPRIMENTO_PLATAFORMA / 2, ALTURA_RESOLUCAO / 2,
		"");
	Plataforma* direita = new Plataforma();
	criaObstaculo(direita, COMPRIMENTO_PLATAFORMA, ALTURA_RESOLUCAO*2,
		COMPRIMENTO_CENARIO + COMPRIMENTO_PLATAFORMA / 2, ALTURA_RESOLUCAO / 2,
		"");
}

void Fase::setChefaoMorreu(bool chefaomorreu)
{
}

Jogador* Fase::getJogador1() const
{
	return pJogador1;
}

void Fase::setJogador1(Jogador* Jogador1)
{
	pJogador1 = Jogador1;
}

void Fase::setJogador2(Jogador* Jogador2)
{
	pJogador2 = Jogador2;
}

Jogador* Fase::getJogador2() const
{
	return pJogador2;
}

void Fase::atualizaView()
{
	if (pJogador1->getPosicaoX()  > COMPRIMENTO_RESOLUCAO / 2 && pJogador1->getPosicaoX()  < COMPRIMENTO_CENARIO - COMPRIMENTO_RESOLUCAO / 2)
		pGerenciadorGrafico->atualizaView(pJogador1->getPosicaoX(), ALTURA_RESOLUCAO/2);
	else if (pJogador1->getPosicaoX()  > COMPRIMENTO_CENARIO - COMPRIMENTO_RESOLUCAO / 2)
		pGerenciadorGrafico->atualizaView(COMPRIMENTO_CENARIO - COMPRIMENTO_RESOLUCAO / 2, ALTURA_RESOLUCAO/2);
	else
		pGerenciadorGrafico->atualizaView(COMPRIMENTO_RESOLUCAO / 2, ALTURA_RESOLUCAO/2);
}

void Fase::incluaProjetil(Projetil* projetil)
{
	listaEntidades.inclua(projetil);
}

void Fase::setJogo(Jogo* jg)
{
	pJogo = jg;
}

Jogo* Fase::getJogo() const
{
	return pJogo;
}

void Fase::salvar()
{
	listaEntidades.salvar();
}

void Fase::recuperarProjeteis(Fase* fase, const string textura)
{
	ifstream recuperadorProjeteis("saves/Projeteis.dat", ios::in);

	if (!recuperadorProjeteis)
		cout << "Erro Projeteis." << endl;

	while (!recuperadorProjeteis.eof())
	{
		Projetil* novo = NULL;
		float posx, posy, velx, vely, lado;
		bool amigavel;
		string textura;

		recuperadorProjeteis >> posx >> posy >> velx >> vely >> amigavel >> textura >> lado;

		novo = new Projetil();

		novo->setGerenciadorGrafico(pGerenciadorGrafico);
		pGerenciadorGrafico->criaCorpo(novo, lado, lado, posx, posy, "textures/Projeteis.png");
		novo->setSubTextura(textura);
		novo->setVelocidade(velx, vely);
		novo->setAmigavel(amigavel);
		novo->setFaseAtual(fase);

		incluaProjetil(novo);
		
	}

	recuperadorProjeteis.close();
}

void Fase::recuperarEstaticos(bool Quintal, const string textura)
{
	ifstream recuperadorEstaticos("saves/Estaticos.dat", ios::in);

	if (!recuperadorEstaticos)
		cout << "Erro Estaticos." << endl;

	while (!recuperadorEstaticos.eof())
	{
		Estatico* novo = NULL;
		int vida;
		float posx, posy, cooldown;

		recuperadorEstaticos >> vida >> posx >> posy >> cooldown;

		novo = new Estatico();

		novo->setVida(vida);
		novo->setCooldownAtaque(cooldown);
		criaInimigo(static_cast <Personagem*> (novo), COMPRIMENTO_ESTATICO, ALTURA_ESTATICO ,
			 posx, posy , textura);
		novo->setTexturas(Quintal);
	}

	recuperadorEstaticos.close();
}

void Fase::recuperarEspinhos(const string textura)
{
	ifstream recuperadorEspinhos("saves/Espinhos.dat", ios::in);

	if (!recuperadorEspinhos)
		cout << "Erro Espinhos." << endl;

	while (!recuperadorEspinhos.eof())
	{
		Espinho* novo = NULL;
		float posx, posy;

		recuperadorEspinhos >> posx >> posy;

		novo = new Espinho();

		criaObstaculo(static_cast <Entidade*>(novo),  COMPRIMENTO_ESPINHO, ALTURA_ESPINHO ,
			 posx, posy , textura);
	}

	recuperadorEspinhos.close();
}

void Fase::recuperarTeias()
{
	ifstream recuperadorTeias("saves/Teias.dat", ios::in);

	if (!recuperadorTeias)
		cout << "Erro Teias." << endl;

	while (!recuperadorTeias.eof())
	{
		Teia* novo = NULL;
		float posx, posy;

		recuperadorTeias >> posx >> posy;

		novo = new Teia();

		criaObstaculo(static_cast <Entidade*>(novo),  COMPRIMENTO_TEIA, ALTURA_TEIA ,
			 posx, posy , "textures/Teia.png");
	}

	recuperadorTeias.close();
}


