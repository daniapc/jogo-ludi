#include "Fase.h"

Fase::Fase()
{
    
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

void Fase::atualiza()
{
        Fazendeira.movimenta();
        //Condições para a view
        if (Fazendeira.getPosicao().x > 640.f && Fazendeira.getPosicao().x < 3360.f)//
            View->setCenter(sf::Vector2f(Fazendeira.getPosicao().x, 360.f));//
        //Bruxo.movimenta();

        desenhar();
}

void Fase::setJanela(sf::RenderWindow* janela)
{
	Janela = janela;
}

void Fase::setView(sf::View* view)
{
    View = view;
}
