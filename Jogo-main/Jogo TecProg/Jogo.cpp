#include "Jogo.h"

Jogo::Jogo() :
    gerenciadorGrafico(),
    menuPrincipal(COMPRIMENTO_RESOLUCAO, ALTURA_RESOLUCAO, 4, this),
    menuJogadores(COMPRIMENTO_RESOLUCAO, ALTURA_RESOLUCAO, 3, this),
    menuFases(COMPRIMENTO_RESOLUCAO, ALTURA_RESOLUCAO, 3, this),
    menuPause(COMPRIMENTO_RESOLUCAO, ALTURA_RESOLUCAO, 3, this),
    Estado(0),
    Fazendeira(NULL),
    Bruxo(NULL),
    Multiplayer(false)
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

int Jogo::getEstado()
{
    return Estado;
}

Quarto& Jogo::getQuarto()
{
    return Fase_Quarto;
}

Quintal& Jogo::getQuintal()
{
    return Fase_Quintal;
}

void Jogo::setMultiplayer(bool multiplayer)
{
    Multiplayer = multiplayer;
}

bool Jogo::getMultiplayer()
{
    return Multiplayer;
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

    //InicializaFases();

}

void Jogo::InicializaFases()
{
    if (!Multiplayer)
        Bruxo = NULL;    
    Fase_Quintal.setFazendeira(Fazendeira);
    Fase_Quintal.setBruxo(Bruxo);
    Fase_Quarto.setFazendeira(Fazendeira);
    Fase_Quarto.setBruxo(Bruxo);

    InicializaQuintal();
    InicializaQuarto();

}

void Jogo::InicializaQuintal()
{
    Fase_Quintal.setJanela(&gerenciadorGrafico.getJanela());
    Fase_Quintal.setView(&gerenciadorGrafico.getView());
    Fase_Quintal.setJogo(this);
    Fase_Quintal.inicializa();
}

void Jogo::InicializaQuarto()
{
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
                    menuPause.setEstadoAtual(Estado);
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
        if (DeltaTempo > 1.f / 20.f)
            DeltaTempo = 1.f / 20.f;

        Atualiza(DeltaTempo);
        
        gerenciadorGrafico.getJanela().setView(gerenciadorGrafico.getView());
        gerenciadorGrafico.getJanela().display();
    }

}

void Jogo::Salvar()
{
    if (menuPause.getEstadoAtual() == 4)
        Fase_Quintal.salvar();
    else if (menuPause.getEstadoAtual() == 5)
        Fase_Quarto.salvar();

    ofstream gravadorEstado("saves/Estado.dat", ios::app);
    if (!gravadorEstado)
        cout << "Erro." << endl;
    gravadorEstado << menuPause.getEstadoAtual() << endl;
    gravadorEstado.close();
}

void Jogo::Recuperar()
{
    ifstream recuperadorEstado("saves/Estado.dat", ios::in);

    if (!recuperadorEstado)
        cout << "Erro." << endl;

    int estado;

    while (!recuperadorEstado.eof())
        recuperadorEstado >> estado;

    if (estado == 4)
    {
        Fase_Quintal.setJanela(&gerenciadorGrafico.getJanela());
        Fase_Quintal.setView(&gerenciadorGrafico.getView());
        Fase_Quintal.setJogo(this);
        Fase_Quintal.recuperar();
        Estado = estado;
    }
    else if (estado == 5)
    {
        Fase_Quarto.setJanela(&gerenciadorGrafico.getJanela());
        Fase_Quarto.setView(&gerenciadorGrafico.getView());
        Fase_Quarto.setJogo(this);
        Fase_Quarto.recuperar();
        Estado = estado;
    }

    recuperadorEstado.close();
}
