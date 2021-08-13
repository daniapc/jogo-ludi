#include "Fase.h"
#include "Jogo.h"
#include "Jogador.h"

Fase::Fase():
	Ente(),
	View(NULL),
	Fazendeira(NULL),
	Bruxo(NULL),
	jogo(NULL)
{
}

Fase::~Fase()
{

}

void Fase::criaPlataforma(sf::Vector2f posicao, const string textura)
{
	Plataforma* nova = NULL;
	nova = new Plataforma();
	nova->setDimensoes(sf::Vector2f(COMPRIMENTO_PLATAFORMA,ALTURA_PLATAFORMA));
	nova->setPosicao(posicao);
	//nova->setOrigem();
	nova->setTextura(textura);
	nova->setJanela(Janela);
	listaEntidades.inclua(static_cast <Entidade*> (nova));
}

void Fase::criaPlataforma(sf::Vector2f posicao, const string textura, sf::Vector2f tamanho)
{
	Plataforma* nova = NULL;
	nova = new Plataforma();
	nova->setDimensoes(sf::Vector2f(tamanho));
	nova->setPosicao(posicao);
	//nova->setOrigem();
	nova->setTextura(textura);
	nova->setJanela(Janela);
	listaEntidades.inclua(static_cast <Entidade*> (nova));

}

void Fase::criaBordas()
{
	Plataforma* nova = NULL;
	nova = new Plataforma();
	nova->getCorpo().setFillColor(sf::Color::Transparent);
	nova->setDimensoes(sf::Vector2f(COMPRIMENTO_CENARIO, ALTURA_PLATAFORMA));
	nova->setPosicao(sf::Vector2f(COMPRIMENTO_CENARIO / 2, ALTURA_RESOLUCAO - ALTURA_PLATAFORMA / 2));
	//nova->setOrigem();
	nova->setJanela(Janela);
	listaEntidades.inclua(static_cast <Entidade*> (nova));


	criaPlataforma(sf::Vector2f(-COMPRIMENTO_PLATAFORMA / 2, ALTURA_RESOLUCAO / 2), "textures/Plataforma_meio.png", sf::Vector2f(COMPRIMENTO_PLATAFORMA, ALTURA_RESOLUCAO));
	criaPlataforma(sf::Vector2f(COMPRIMENTO_CENARIO + COMPRIMENTO_PLATAFORMA / 2, ALTURA_RESOLUCAO / 2), "", sf::Vector2f(COMPRIMENTO_PLATAFORMA, ALTURA_RESOLUCAO));
}

void Fase::criaEspinho(sf::Vector2f posicao, const string textura)
{
	Espinho* novo = NULL; 
	novo = new Espinho();

	//Setar posição aleatoriamente
	novo->setPosicao(posicao);
	novo->setDimensoes(sf::Vector2f(COMPRIMENTO_ESPINHO, ALTURA_ESPINHO));
	//novo->setOrigem();
	novo->setJanela(Janela);
	novo->setTextura(textura);

	//listaEspinhos.push_back(novo);
	listaEntidades.inclua(static_cast <Entidade*>(novo));
	//listaObstaculos.push_back(static_cast<Obstaculo*>(novo));
	//gerenciadorFisica.incluaEntidade(static_cast <Entidade*>(novo));
}

void Fase::criaTeia(sf::Vector2f posicao, const string textura)
{
	Teia* novo = NULL;
	novo = new Teia();

	//Setar posição aleatoriamente
	novo->setPosicao(posicao);
	novo->setDimensoes(sf::Vector2f(COMPRIMENTO_TEIA, ALTURA_TEIA));
	//novo->setOrigem();
	novo->setJanela(Janela);
	novo->setTextura("");
	//novo->setLentidao(0.9f);

	//ListaTeias.push_back(novo);
	listaEntidades.inclua(static_cast <Entidade*>(novo));
	//listaObstaculos.push_back(static_cast<Obstaculo*>(novo));
	//gerenciadorFisica.incluaEntidade(static_cast <Entidade*>(novo));
}

void Fase::setChefaoMorreu(bool chefaomorreu)
{

}

void Fase::criaEstatico(sf::Vector2f posicao, const string textura)
{
	Estatico* novo = NULL;
	novo = new Estatico();

	novo->setPosicao(posicao);
	novo->setDimensoes(sf::Vector2f(COMPRIMENTO_ESTATICO, ALTURA_ESTATICO));
	//novo->setOrigem();
	novo->inicializa();
	novo->setVida(1);
	novo->setVelocidade(100.f);
	novo->setJanela(Janela);
	novo->setTextura(textura);
	novo->setColidePlataforma(true);

	//listaEstaticos.push_back(novo);
	listaEntidades.inclua(static_cast <Entidade*> (novo));
	listaPersonagens.inclua(static_cast <Personagem*> (novo));
	//gerenciadorFisica.incluaPersonagem(novo);
	//gerenciadorFisica.incluaEntidade(static_cast <Entidade*>(novo));
}

/*
vector<Projetil*>& Fase::getPiscinaProjeteis()
{
	return PiscinaProjeteis;
}
*/

Jogador* Fase::getFazendeira()
{
	return Fazendeira;
}

GerenciadorFisica Fase::getGerenciadorFisica()
{
	return gerenciadorFisica;
}

void Fase::setFazendeira(Jogador* fazendeira)
{
	Fazendeira = fazendeira;
}

void Fase::setBruxo(Jogador* bruxo)
{
	Bruxo = bruxo;
}

void Fase::atualiza(float deltaTempo)
{
	gerenciadorFisica.checaColisoes();

	atualizaView();

    Fazendeira->atualiza(deltaTempo);

    desenhar();
}

void Fase::atualizaView()
{

	if (Fazendeira->getPosicao().x > COMPRIMENTO_RESOLUCAO / 2 && Fazendeira->getPosicao().x < COMPRIMENTO_CENARIO - COMPRIMENTO_RESOLUCAO / 2)
		View->setCenter(sf::Vector2f(Fazendeira->getPosicao().x, ALTURA_RESOLUCAO/2));
	else if (Fazendeira->getPosicao().x > COMPRIMENTO_CENARIO - COMPRIMENTO_RESOLUCAO / 2)
		View->setCenter(sf::Vector2f(COMPRIMENTO_CENARIO - COMPRIMENTO_RESOLUCAO / 2, ALTURA_RESOLUCAO/2));
	else
		View->setCenter(sf::Vector2f(COMPRIMENTO_RESOLUCAO / 2, ALTURA_RESOLUCAO/2));
}

/*
void Fase::incrementaPontuacao()
{
	//jogo->incrementaPontuacao();
}
*/

void Fase::incluaProjetil(Projetil* projetil)
{
	//listaProjeteis.push_back(projetil);
	listaEntidades.inclua(projetil);
	//gerenciadorFisica.incluaProjetil(projetil);
	//gerenciadorFisica.incluaEntidade(static_cast<Entidade*>(projetil));
}

void Fase::setView(sf::View* view)
{
    View = view;
}

void Fase::setJogo(Jogo* jg)
{
	jogo = jg;
}

Jogo* Fase::getJogo()
{
	return jogo;
}

void Fase::salvar()
{
	listaEntidades.salvar();
}

void Fase::recuperarProjeteis()
{
	ifstream recuperadorProjeteis("saves/Projeteis.dat", ios::in);

	if (!recuperadorProjeteis)
		cout << "Erro Projeteis." << endl;

	while (!recuperadorProjeteis.eof())
	{
		Projetil* novo = NULL;
		float posx, posy, movx, movy, velx, vely;
		bool amigavel;

		recuperadorProjeteis >> posx >> posy >> movx >> movy >> velx >> vely >> amigavel;

		novo = new Projetil();

		novo->setPosicao(sf::Vector2f(posx, posy));
		novo->setVelocidade(sf::Vector2f(velx, vely));
		novo->setMovimento(sf::Vector2f(movx, movy));
		novo->setDimensoes(sf::Vector2f(10.f, 10.f));
		novo->setAmigavel(amigavel);
		//novo->setOrigem();
		novo->setJanela(Janela);
		//novo->setTextura("");
		//novo->setNaPiscina(false);

		incluaProjetil(novo);

		//listaEspinhos.push_back(novo);
		//listaEntidades.inclua(static_cast <Entidade*>(novo));
		//listaObstaculos.push_back(static_cast<Obstaculo*>(novo));
		//gerenciadorFisica.incluaEntidade(static_cast <Entidade*>(novo));
	}
	recuperadorProjeteis.close();

}

void Fase::recuperarEstaticos()
{
	ifstream recuperadorEstaticos("saves/Estaticos.dat", ios::in);

	if (!recuperadorEstaticos)
		cout << "Erro." << endl;

	while (!recuperadorEstaticos.eof())
	{
		Estatico* novo = NULL;
		int vida;
		float posx, posy, cooldown;

		recuperadorEstaticos >> vida >> posx >> posy >> cooldown;

		novo = new Estatico();

		novo->setPosicao(sf::Vector2f(posx,posy));
		novo->setDimensoes(sf::Vector2f(COMPRIMENTO_ESTATICO, ALTURA_ESTATICO));
		//novo->setOrigem();
		novo->inicializa();
		novo->setVida(vida);
		novo->setVelocidade(100.f);
		novo->setJanela(Janela);
		novo->setTextura("textures/Estatico_vulneravel.png");
		novo->setColidePlataforma(true);
		novo->setCooldownAtaque(cooldown);

		listaEntidades.inclua(static_cast <Entidade*> (novo));
		listaPersonagens.inclua(static_cast <Personagem*> (novo));
	}

	recuperadorEstaticos.close();

	//ofstream deletar("saves/Estaticos.dat", ios::out);
	//deletar.close();
}

void Fase::recuperarEspinhos()
{
	ifstream recuperadorEspinhos("saves/Espinhos.dat", ios::in);

	if (!recuperadorEspinhos)
		cout << "Erro." << endl;

	while (!recuperadorEspinhos.eof())
	{
		Espinho* novo = NULL;
		float posx, posy;

		recuperadorEspinhos >> posx >> posy;

		novo = new Espinho();

		//Setar posição aleatoriamente
		novo->setPosicao(sf::Vector2f(posx,posy));
		novo->setDimensoes(sf::Vector2f(COMPRIMENTO_ESPINHO, ALTURA_ESPINHO));
		//novo->setOrigem();
		novo->setJanela(Janela);
		//novo->setTextura("");

		listaEntidades.inclua(static_cast <Entidade*>(novo));
	}
	recuperadorEspinhos.close();

	//ofstream deletar("saves/Espinhos.dat", ios::out);
	//deletar.close();
}

void Fase::recuperarTeias()
{
	ifstream recuperadorTeias("saves/Teias.dat", ios::in);

	if (!recuperadorTeias)
		cout << "Erro." << endl;

	while (!recuperadorTeias.eof())
	{
		Teia* novo = NULL;
		float posx, posy;

		recuperadorTeias >> posx >> posy;

		novo = new Teia();

		//Setar posição aleatoriamente
		novo->setPosicao(sf::Vector2f(posx, posy));
		novo->setDimensoes(sf::Vector2f(COMPRIMENTO_TEIA, ALTURA_TEIA));
		//novo->setOrigem();
		novo->setJanela(Janela);
		//novo->setTextura("");

		listaEntidades.inclua(static_cast <Entidade*>(novo));
	}

	recuperadorTeias.close();

	//ofstream deletar("saves/Teias.dat", ios::out);
	//deletar.close();
}

/*
void Fase::recuperarJogadores()
{
	ifstream recuperadorJogadores("saves/Jogadores.dat", ios::in);

	if (!recuperadorJogadores)
		cout << "Erro Jogadores." << endl;

	int vida;
	float posx, posy, movx, movy, cooldown;

	recuperadorJogadores >> vida >> posx >> posy >> movx >> movy >> cooldown;

	Fazendeira = new Jogador();
	Fazendeira->inicializa();
	Fazendeira->setVida(vida);
	Fazendeira->setPosicao(sf::Vector2f(posx, posy));
	Fazendeira->setTextura("textures/Fazendeira.png");
	Fazendeira->setTeclas(sf::Keyboard::D, sf::Keyboard::A, sf::Keyboard::W, sf::Keyboard::Space);
	Fazendeira->setMovimentoX(movx);
	Fazendeira->setMovimentoY(movy);
	Fazendeira->setCooldownAtaque(cooldown);
	Fazendeira->setVelocidade(400.f);
	Fazendeira->setAlturaPulo(250.f);
	Fazendeira->setJanela(Janela);
	Fazendeira->setColidePlataforma(true);
	Fazendeira->setDimensoes(sf::Vector2f(COMPRIMENTO_JOGADOR, ALTURA_JOGADOR));
	Fazendeira->setOrigem();

	//gerenciadorFisica.setFazendeira(Fazendeira);
	listaEntidades.inclua(static_cast<Entidade*>(Fazendeira));
	listaPersonagens.inclua(static_cast <Personagem*> (Fazendeira));
	//gerenciadorFisica.incluaPersonagem(static_cast<Personagem*>(Fazendeira));

		if (jogo->getMultiplayer())
		{
			cout << "criou bruxo" << endl;
			Bruxo = new Jogador();
			recuperadorJogadores >> vida >> posx >> posy >> movx >> movy >> cooldown;

			Bruxo->setTextura("textures/Bruxo.png");

			Bruxo->inicializa();
			Bruxo->setVida(vida);
			Bruxo->setPosicao(sf::Vector2f(posx, posy));

			Bruxo->setMovimentoX(movx);
			Bruxo->setMovimentoY(movy);
			Bruxo->setCooldownAtaque(cooldown);
			Bruxo->setVelocidade(400.f);
			Bruxo->setAlturaPulo(250.f);
			Bruxo->setJanela(Janela);
			Bruxo->setColidePlataforma(true);
			Bruxo->setDimensoes(sf::Vector2f(COMPRIMENTO_JOGADOR, ALTURA_JOGADOR));
			Bruxo->setOrigem();

			listaEntidades.inclua(static_cast<Entidade*>(Bruxo));
			listaPersonagens.inclua(static_cast <Personagem*> (Bruxo));
		}

	recuperadorJogadores.close();

	//ofstream deletar("saves/Jogadores.dat", ios::out);
	//deletar.close();
}
*/


