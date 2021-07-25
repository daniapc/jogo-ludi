#include "Jogo.h"

Jogo::Jogo():
	Janela(sf::VideoMode(1920,1080), "Jogo", sf::Style::Titlebar | sf::Style::Close)
{
	Executar();
}


Jogo::~Jogo()
{
}

void Jogo::Executar()
{
	Bruxo.setJanela(&Janela);
	Bruxo.Inicializa(sf::Vector2f(50.f, 50.f), sf::Vector2f(500, 500));
    (Bruxo.getCorpo()).setFillColor(sf::Color::Blue);

    LoopJogo();
}

void Jogo::LoopJogo()
{
    while (Janela.isOpen())
    {
        sf::Event evento;
        while (Janela.pollEvent(evento))
        {
            if (evento.type == sf::Event::Closed)
                Janela.close();
        }

        Janela.clear();

        Janela.draw(Bruxo.getCorpo());

        Janela.display();
    

    }
}
