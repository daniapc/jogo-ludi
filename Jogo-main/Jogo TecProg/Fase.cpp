#include "Fase.h"
#include "Jogo.h"

Fase::Fase():
	PiscinaProjeteis()
{
	Janela = NULL;
    View = NULL;
}

Fase::~Fase()
{
//Desalocar todas as entidades de uma só vez?
    View = NULL;

}

void Fase::criaEntidades()
{
}

void Fase::criaPlataforma(sf::Vector2f posicao, const string textura, sf::Vector2f tamanho)
{
	Plataforma* nova = NULL;
	nova = new Plataforma();
	nova->setDimensoes(tamanho);
	nova->setPosicao(posicao);
	nova->setOrigem();
	nova->setTextura(textura);
	nova->setJanela(Janela);
	//ListaPlataformas.push_back(nova);
	listaEntidades.inclua(static_cast <Entidade*> (nova));
	//listaObstaculos.push_back(static_cast<Obstaculo*>(nova));
	//gerenciadorFisica.incluaPlataforma(nova);
	gerenciadorFisica.incluaEntidade(static_cast<Entidade*>(nova));
}

void Fase::criaChao(){
	Plataforma* nova = NULL;
	nova = new Plataforma();
	nova->getCorpo().setFillColor(sf::Color::Transparent);
	nova->setDimensoes(sf::Vector2f(COMPRIMENTO_CENARIO, ALTURA_PLATAFORMA));
	nova->setPosicao(sf::Vector2f(COMPRIMENTO_CENARIO / 2, ALTURA_RESOLUCAO - ALTURA_PLATAFORMA / 2));
	nova->setOrigem();
	//nova->setTextura("textures/Plataforma_meio.png");
	nova->setJanela(Janela);
	//ListaPlataformas.push_back(nova);
	listaEntidades.inclua(static_cast <Entidade*> (nova));
	//gerenciadorFisica.incluaPlataforma(nova);
	gerenciadorFisica.incluaEntidade(static_cast<Entidade*>(nova));
}

void Fase::criaEspinho(sf::Vector2f posicao, const string textura)
{
	Espinho* novo = NULL; 
	novo = new Espinho();

	//Setar posição aleatoriamente
	novo->setPosicao(posicao);
	novo->setDimensoes(sf::Vector2f(COMPRIMENTO_ESPINHO, ALTURA_ESPINHO));
	novo->setOrigem();
	novo->setJanela(Janela);
	novo->setTextura(textura);

	//listaEspinhos.push_back(novo);
	listaEntidades.inclua(static_cast <Entidade*>(novo));
	//listaObstaculos.push_back(static_cast<Obstaculo*>(novo));
	gerenciadorFisica.incluaEntidade(static_cast <Entidade*>(novo));
}

void Fase::criaTeia(sf::Vector2f posicao, const string textura)
{
	Teia* novo = NULL;
	novo = new Teia();

	//Setar posição aleatoriamente
	novo->setPosicao(posicao);
	novo->setDimensoes(sf::Vector2f(COMPRIMENTO_TEIA, ALTURA_TEIA));
	novo->setOrigem();
	novo->setJanela(Janela);
	novo->setTextura("");
	//novo->setLentidao(0.9f);

	//ListaTeias.push_back(novo);
	listaEntidades.inclua(static_cast <Entidade*>(novo));
	//listaObstaculos.push_back(static_cast<Obstaculo*>(novo));
	gerenciadorFisica.incluaEntidade(static_cast <Entidade*>(novo));
}

void Fase::criaEstatico(sf::Vector2f posicao, const string textura)
{
	Estatico* novo = NULL;
	novo = new Estatico();

	novo->setPosicao(posicao);
	novo->setDimensoes(sf::Vector2f(COMPRIMENTO_ESTATICO, ALTURA_ESTATICO));
	novo->setOrigem();
	novo->inicializa();
	novo->setVida(5);
	novo->setVelocidade(100.f);
	novo->setJanela(Janela);
	novo->setTextura(textura);
	novo->setColidePlataforma(true);

	//listaEstaticos.push_back(novo);
	listaEntidades.inclua(static_cast <Entidade*> (novo));
	gerenciadorFisica.incluaPersonagem(novo);
	gerenciadorFisica.incluaEntidade(static_cast <Entidade*>(novo));
}

vector<Projetil*>& Fase::getPiscinaProjeteis()
{
	return PiscinaProjeteis;
}

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
}

void Fase::incluaProjetil(Projetil* projetil)
{
	//listaProjeteis.push_back(projetil);
	listaEntidades.inclua(projetil);
	//gerenciadorFisica.incluaProjetil(projetil);
	gerenciadorFisica.incluaEntidade(static_cast<Entidade*>(projetil));
}

void Fase::setView(sf::View* view)
{
    View = view;
}

void Fase::setJogo(Jogo* jg)
{
	jogo = jg;
}

void Fase::salvar()
{
	listaEntidades.salvar();
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
		novo->setOrigem();
		novo->inicializa();
		novo->setVida(vida);
		novo->setVelocidade(100.f);
		novo->setJanela(Janela);
		novo->setTextura("textures/Estatico_vulneravel.png");
		novo->setColidePlataforma(true);
		novo->setCooldownAtaque(cooldown);

		listaEntidades.inclua(static_cast <Entidade*> (novo));
		gerenciadorFisica.incluaPersonagem(novo);
		gerenciadorFisica.incluaEntidade(static_cast <Entidade*>(novo));
	}

	recuperadorEstaticos.close();
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
		novo->setOrigem();
		novo->setJanela(Janela);
		novo->setTextura("");

		//listaEspinhos.push_back(novo);
		listaEntidades.inclua(static_cast <Entidade*>(novo));
		//listaObstaculos.push_back(static_cast<Obstaculo*>(novo));
		gerenciadorFisica.incluaEntidade(static_cast <Entidade*>(novo));
	}
	recuperadorEspinhos.close();
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
		novo->setOrigem();
		novo->setJanela(Janela);
		novo->setTextura("");

		//listaEspinhos.push_back(novo);
		listaEntidades.inclua(static_cast <Entidade*>(novo));
		//listaObstaculos.push_back(static_cast<Obstaculo*>(novo));
		gerenciadorFisica.incluaEntidade(static_cast <Entidade*>(novo));
	}

	recuperadorTeias.close();
}

void Fase::recuperarJogadores()
{
	ifstream recuperadorJogadores("saves/Jogadores.dat", ios::in);

	if (!recuperadorJogadores)
		cout << "Erro." << endl;

	while (!recuperadorJogadores.eof())
	{
		int vida;
		float posx, posy, movx, movy, cooldown;

		recuperadorJogadores >> vida >> posx >> posy >> movx >> movy >> cooldown;

		Fazendeira = new Jogador();
		Fazendeira->inicializa();
		Fazendeira->setVida(vida);
		Fazendeira->setPosicao(sf::Vector2f(posx, posy));
		Fazendeira->setMovimentoX(movx);
		Fazendeira->setMovimentoY(movy);
		Fazendeira->setCooldownAtaque(cooldown);
		Fazendeira->setVelocidade(400.f);
		Fazendeira->setJanela(Janela);
		Fazendeira->setTextura("textures/Fazendeira.png");
		Fazendeira->setColidePlataforma(true);
		Fazendeira->setDimensoes(sf::Vector2f(COMPRIMENTO_JOGADOR, ALTURA_JOGADOR));
		Fazendeira->setTeclas(sf::Keyboard::D, sf::Keyboard::A, sf::Keyboard::W, sf::Keyboard::Space);
		Fazendeira->setOrigem();
		Fazendeira->setFaseAtual(this);

		listaEntidades.inclua(static_cast<Entidade*>(Fazendeira));
		gerenciadorFisica.incluaPersonagem(static_cast<Personagem*>(Fazendeira));
		gerenciadorFisica.setFazendeira(Fazendeira);
	}

	recuperadorJogadores.close();
}
