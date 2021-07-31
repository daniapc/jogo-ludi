#include "Jogo.h"

const float Jogo::Altura = 720;
const float Jogo::Comprimento = 1280;

Jogo::Jogo() :
    Janela(sf::VideoMode(1280, 720), "Jogo", sf::Style::Fullscreen),
    View(sf::Vector2f(640.f, 360.f), sf::Vector2f(1280, 720))
{
	Executar();
}

Jogo::~Jogo()
{
}

const float Jogo::getAltura()
{
    return Altura;
}

const float Jogo::getComprimento()
{
    return Comprimento;
}

void Jogo::Atualiza()
{
    Fase_Quintal.atualiza();
}

void Jogo::Inicializa()
{
    Janela.setView(View);

    InicializaFases();
}

void Jogo::InicializaFases()
{
    Fase_Quintal.setJanela(&Janela);
    Fase_Quintal.setView(&View);
    Fase_Quintal.inicializa();
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
    
        Janela.clear();

        Atualiza();
       
        Janela.setView(View);
        Janela.display();

    }
    
}
