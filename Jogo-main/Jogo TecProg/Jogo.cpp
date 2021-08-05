#include "Jogo.h"

Jogo::Jogo() :
    /*
    Janela(sf::VideoMode(1280, 720), "Jogo", sf::Style::Fullscreen),
    View(sf::Vector2f(640.f, 360.f), sf::Vector2f(1280, 720))
    */
    gerenciadorGrafico()
{
	Executar();
}

Jogo::~Jogo()
{
}

void Jogo::Atualiza(float deltaTempo)
{
    Fase_Quintal.atualiza(deltaTempo);
}

void Jogo::Inicializa()
{
    gerenciadorGrafico.getJanela().setView(gerenciadorGrafico.getView());
    //Janela.setView(View);

    InicializaFases();
}

void Jogo::InicializaFases()
{
    Fase_Quintal.setJanela(&gerenciadorGrafico.getJanela());
    Fase_Quintal.setView(&gerenciadorGrafico.getView());
    Fase_Quintal.inicializa();
}

void Jogo::Executar()
{
    Inicializa();
    LoopJogo();
}

void Jogo::LoopJogo()
{
    sf::Clock Tempo;

    while (gerenciadorGrafico.getJanela().isOpen())
    {
        sf::Event evento;
        while (gerenciadorGrafico.getJanela().pollEvent(evento))
        {
            if (evento.type == sf::Event::Closed)
                gerenciadorGrafico.getJanela().close();
        }
    
        gerenciadorGrafico.getJanela().clear();

        float DeltaTempo = Tempo.restart().asSeconds();

        Atualiza(DeltaTempo);
        
        gerenciadorGrafico.getJanela().setView(gerenciadorGrafico.getView());
        gerenciadorGrafico.getJanela().display();
    }
}
