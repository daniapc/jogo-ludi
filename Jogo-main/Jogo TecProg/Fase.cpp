#include "Fase.h"
#include "Jogo.h"
#include "Jogador.h"

Fase::Fase():
	Ente(),
	//pView(NULL),
	pFazendeira(NULL),
	pBruxo(NULL),
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
	
	//pentidade->setDimensoes(dimx, dimy);
	//pentidade->setPosicao(posx, posy);
	//pentidade->setTextura(textura);


	listaEntidades.inclua(static_cast <Entidade*>(pentidade));
}

void Fase::criaInimigo(Personagem* ppersonagem, float dimx, float dimy, float posx, float posy, const string textura)
{
	ppersonagem->setGerenciadorGrafico(pGerenciadorGrafico);

	pGerenciadorGrafico->criaCorpo(static_cast <Entidade*>(ppersonagem), dimx, dimy, posx, posy, textura);
	ppersonagem->setDimensoes(dimx, dimy);
	ppersonagem->setPosicao(posx, posy);
	ppersonagem->setTextura(textura);


	listaEntidades.inclua(static_cast <Entidade*>(ppersonagem));
	listaPersonagens.inclua(static_cast <Personagem*> (ppersonagem));

}

void Fase::criaBordas()
{

	Plataforma* chao = new Plataforma();
	criaObstaculo(chao, COMPRIMENTO_CENARIO, ALTURA_PLATAFORMA,
		COMPRIMENTO_CENARIO / 2, ALTURA_RESOLUCAO - ALTURA_PLATAFORMA / 2,
		"");

	Plataforma* esquerda = new Plataforma();
	criaObstaculo(esquerda, COMPRIMENTO_PLATAFORMA, ALTURA_RESOLUCAO,
		-COMPRIMENTO_PLATAFORMA / 2, ALTURA_RESOLUCAO / 2,
		"");
	Plataforma* direita = new Plataforma();
	criaObstaculo(direita, COMPRIMENTO_PLATAFORMA, ALTURA_RESOLUCAO,
		COMPRIMENTO_CENARIO + COMPRIMENTO_PLATAFORMA / 2, ALTURA_RESOLUCAO / 2,
		"");
}

void Fase::setChefaoMorreu(bool chefaomorreu)
{
}

Jogador* Fase::getFazendeira()
{
	return pFazendeira;
}

void Fase::setFazendeira(Jogador* fazendeira)
{
	pFazendeira = fazendeira;
}

void Fase::setBruxo(Jogador* bruxo)
{
	pBruxo = bruxo;
}



void Fase::atualizaView()
{
	if (pFazendeira->getPosicaoX()  > COMPRIMENTO_RESOLUCAO / 2 && pFazendeira->getPosicaoX()  < COMPRIMENTO_CENARIO - COMPRIMENTO_RESOLUCAO / 2)
		pGerenciadorGrafico->atualizaView(pFazendeira->getPosicaoX(), ALTURA_RESOLUCAO/2);
	else if (pFazendeira->getPosicaoX()  > COMPRIMENTO_CENARIO - COMPRIMENTO_RESOLUCAO / 2)
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

Jogo* Fase::getJogo()
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
		float posx, posy, velx, vely;
		bool amigavel;

		recuperadorProjeteis >> posx >> posy >> velx >> vely >> amigavel;

		novo = new Projetil();
		novo->setVelocidade(velx, vely);
		novo->setPosicao( posx, posy );
		novo->setDimensoes( 10.f, 10.f );
		novo->setAmigavel(amigavel);
		novo->setGerenciadorGrafico(pGerenciadorGrafico);
		novo->setTextura(textura);
		novo->setFaseAtual(fase);
		incluaProjetil(novo);

		pGerenciadorGrafico->criaCorpo(novo, 10.f, 10.f, posx, posy, "");
	}

	recuperadorProjeteis.close();
}

void Fase::recuperarEstaticos(const string textura)
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
			 posx, posy , "");
	}

	recuperadorTeias.close();
}


