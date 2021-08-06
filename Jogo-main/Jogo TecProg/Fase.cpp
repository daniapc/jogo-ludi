#include "Fase.h"
#include "Jogo.h"

Fase::Fase()
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

void Fase::criaEspinho(sf::Vector2f posicao)
{
	Espinho* novo = NULL; 
	novo = new Espinho();

	//Setar posição aleatoriamente
	novo->setPosicao(posicao);
	novo->setDimensoes(sf::Vector2f(COMPRIMENTO_ESPINHO, ALTURA_ESPINHO));
	novo->setOrigem();
	novo->setJanela(Janela);
	novo->setTextura("");

	//listaEspinhos.push_back(novo);
	listaEntidades.inclua(static_cast <Entidade*>(novo));
	//listaObstaculos.push_back(static_cast<Obstaculo*>(novo));
	gerenciadorFisica.incluaEntidade(static_cast <Entidade*>(novo));
}

void Fase::criaEstatico(sf::Vector2f posicao)
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
	novo->setTextura("textures/Estatico_vulneravel.png");
	novo->setColidePlataforma(true);

	//listaEstaticos.push_back(novo);
	listaEntidades.inclua(static_cast <Entidade*> (novo));
	gerenciadorFisica.incluaPersonagem(novo);
	gerenciadorFisica.incluaEntidade(static_cast <Entidade*>(novo));
}

Jogador& Fase::getFazendeira()
{
	return Fazendeira;
}

GerenciadorFisica Fase::getGerenciadorFisica()
{
	return gerenciadorFisica;
}

void Fase::atualiza(float deltaTempo)
{
	gerenciadorFisica.checaColisoes();

	atualizaView();

    Fazendeira.atualiza(deltaTempo);

    desenhar();
}

void Fase::atualizaView()
{
	if (Fazendeira.getPosicao().x > COMPRIMENTO_RESOLUCAO / 2 && Fazendeira.getPosicao().x < COMPRIMENTO_CENARIO - COMPRIMENTO_RESOLUCAO / 2)
		View->setCenter(sf::Vector2f(Fazendeira.getPosicao().x, ALTURA_RESOLUCAO/2));
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
