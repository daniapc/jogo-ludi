#include "Jogo.h"

Jogo::Jogo() :
    gerenciadorGrafico(),
    menuPrincipal(COMPRIMENTO_RESOLUCAO,ALTURA_RESOLUCAO, 3, this),
    menuJogadores(COMPRIMENTO_RESOLUCAO,ALTURA_RESOLUCAO, 3, this),
    menuFases(COMPRIMENTO_RESOLUCAO,ALTURA_RESOLUCAO, 3, this),
    menuPause(COMPRIMENTO_RESOLUCAO, ALTURA_RESOLUCAO, 3, this),
    Estado(0)
{
	Executar();
}

Jogo::~Jogo()
{
}

void Jogo::setEstado(int estado)
{
    Estado = estado;
}

void Jogo::Atualiza(float deltaTempo)
{
    //Estado = MenuPrincipal.getEstado();
    switch (Estado) {
        case 0: //Menu Principal
            menuPrincipal.desenhar();
            break;
        case 1: //Menu Jogadores
            menuJogadores.desenhar();
            break;
        case 2: //Menu Fases
            menuFases.desenhar();
            break;
        case 3: //Menu Colocações
            break;
        case 4: //Fase Quintal
            Fase_Quintal.atualiza(deltaTempo);
            break; 
        case 5: //Fase Quarto
            Fase_Quarto.atualiza(deltaTempo);
            break;
        case 6: //Pausar Tela
            menuPause.desenhar();
            break;
        case 7: //Tela salvamento
            break;
    }
}

void Jogo::Inicializa()
{
    gerenciadorGrafico.getJanela().setView(gerenciadorGrafico.getView());
    //Janela.setView(View);

    menuPrincipal.setJanela(&gerenciadorGrafico.getJanela());
    menuJogadores.setJanela(&gerenciadorGrafico.getJanela());
    menuFases.setJanela(&gerenciadorGrafico.getJanela());
    menuPause.setJanela(&gerenciadorGrafico.getJanela());

    InicializaFases();
}

void Jogo::InicializaFases()
{
    Fase_Quintal.setJanela(&gerenciadorGrafico.getJanela());
    Fase_Quintal.setView(&gerenciadorGrafico.getView());
    Fase_Quintal.setJogo(this);
    Fase_Quintal.inicializa();
    Fase_Quarto.setJanela(&gerenciadorGrafico.getJanela());
    Fase_Quarto.setView(&gerenciadorGrafico.getView());
    Fase_Quarto.setJogo(this);
    Fase_Quarto.inicializa();
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

            if (evento.type == sf::Event::KeyPressed)
                if (evento.key.code == sf::Keyboard::Key::Escape)
                {
                    Estado = 6;
                    gerenciadorGrafico.resetaView();
                }

            switch (Estado) {
                case 0: //Menu Principal
                    menuPrincipal.LoopMenu(&evento);
                    break;
                case 1: //Menu Jogadores
                    menuJogadores.LoopMenu(&evento);
                    break;
                case 2: //Menu Fases
                    menuFases.LoopMenu(&evento);
                    break;
                case 3: //Menu Colocações
                    break;
                case 6:
                    menuPause.LoopMenu(&evento);
                case 7: //Tela salvamento
                    break;
            }
        }
    
    
        gerenciadorGrafico.getJanela().clear();

        float DeltaTempo = Tempo.restart().asSeconds();

        Atualiza(DeltaTempo);
        
        gerenciadorGrafico.getJanela().setView(gerenciadorGrafico.getView());
        gerenciadorGrafico.getJanela().display();
    }

}
