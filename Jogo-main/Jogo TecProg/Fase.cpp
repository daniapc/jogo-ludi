#include "Fase.h"

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

void Fase::criaPlataforma(sf::Vector2f posicao, sf::Vector2f tamanho, const string textura)
{
	Plataforma* nova = NULL;
	nova = new Plataforma();
	nova->setDimensoes(tamanho);
	nova->setPosicao(posicao);
	nova->setOrigem();
	nova->setTextura(textura);
	nova->setJanela(Janela);
	ListaPlataformas.push_back(nova);
	listaEntidades.inclua(static_cast <Entidade*> (nova));
	gerenciadorFisica.incluaPlataforma(nova);
}

void Fase::criaChao(){
	Plataforma* nova = NULL;
	nova = new Plataforma();
	nova->getCorpo().setFillColor(sf::Color::Transparent);
	nova->setDimensoes(sf::Vector2f(COMPRIMENTO_CENARIO, ALTURA_PLATAFORMA));
	nova->setPosicao(sf::Vector2f(COMPRIMENTO_CENARIO / 2, ALTURA_RESOLUCAO - ALTURA_PLATAFORMA / 2));
	nova->setOrigem();
	nova->setJanela(Janela);
	ListaPlataformas.push_back(nova);
	listaEntidades.inclua(static_cast <Entidade*> (nova));
	gerenciadorFisica.incluaPlataforma(nova);
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
		View->setCenter(sf::Vector2f(Fazendeira.getPosicao().x, 360.f));
}

void Fase::setView(sf::View* view)
{
    View = view;
}
