#include "Jogo.h"

Jogo::Jogo():
	Janela(sf::VideoMode(1920,1080), "Jogo", sf::Style::Fullscreen),
    View(sf::Vector2f(400.f, 225.f), sf::Vector2f(800.0f, 450.0f))
{
	Executar();
}


Jogo::~Jogo()
{
}

void Jogo::Inicializa()
{
    Janela.setView(View);

    InicializaJogadores();
}

void Jogo::InicializaJogadores()
{
   
    Background.setJanela(&Janela);
    Background.setDimensoes(sf::Vector2f(1920.f, 450.f));
    Background.setPosicao(sf::Vector2f(0.f, 0.f));
    Background.setCor(sf::Color::White);
    Background.setTextura("Background.png");

    //Perguntar se isso deveria estar em um gerenciador gráfico
    Bruxo.setJanela(&Janela);
    Bruxo.setDimensoes(sf::Vector2f(75.f, 75.f));
    Bruxo.setPosicao(sf::Vector2f(0.f, 0.f));
    Bruxo.setTextura("HeavyBandit_Attack_2.png");
    Bruxo.setTeclas(sf::Keyboard::D, sf::Keyboard::A, sf::Keyboard::S, sf::Keyboard::W);

    Fazendeira.setJanela(&Janela);
    Fazendeira.setDimensoes(sf::Vector2f(50.f, 50.f));
    Fazendeira.setPosicao(sf::Vector2f(100.f, 100.f));
    Fazendeira.setCor(sf::Color::Red);
    Fazendeira.setTeclas(sf::Keyboard::Right, sf::Keyboard::Left, sf::Keyboard::Down, sf::Keyboard::Up);
}

void Jogo::Executar()
{
    Inicializa();
        
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

        Bruxo.movimenta();
        View.setCenter(Bruxo.getPosicao());
        Fazendeira.movimenta();
        Janela.clear();

        Background.desenhar();
        Fazendeira.desenhar();
        Bruxo.desenhar();
        
        
        Janela.setView(View);
        Janela.display();
    

    }
}
