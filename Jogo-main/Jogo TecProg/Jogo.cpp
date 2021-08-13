#include "Jogo.h"

Jogo::Jogo() :
    gerenciadorGrafico(),
    menuPrincipal(COMPRIMENTO_RESOLUCAO, ALTURA_RESOLUCAO, 4, this),
    menuJogadores(COMPRIMENTO_RESOLUCAO, ALTURA_RESOLUCAO, 3, this),
    menuFases(COMPRIMENTO_RESOLUCAO, ALTURA_RESOLUCAO, 3, this),
    menuPause(COMPRIMENTO_RESOLUCAO, ALTURA_RESOLUCAO, 5, this),
    menuColocacao(COMPRIMENTO_RESOLUCAO, ALTURA_RESOLUCAO, 8, this),
    creditos(COMPRIMENTO_RESOLUCAO, ALTURA_RESOLUCAO, 2, this),
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

Jogador* Jogo::getBruxo()
{
    return Bruxo;
}

Jogador* Jogo::getFazendeira()
{
    return Fazendeira;
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

MenuColocacao& Jogo::getMenuColocacao()
{
    return menuColocacao;
}

void Jogo::Atualiza(float deltaTempo)
{
    //Estado = MenuPrincipal.getEstado();
    switch (Estado) {
        case 0: //Menu Principal
            gerenciadorGrafico.resetaView();
            menuPrincipal.desenhar();
            break;
        case 1: //Menu Jogadores
            gerenciadorGrafico.resetaView();
            menuJogadores.desenhar();
            break;
        case 2: //Menu Fases
            gerenciadorGrafico.resetaView();
            menuFases.desenhar();
            break;
        case 3: //Menu Colocações
            gerenciadorGrafico.resetaView();
            menuColocacao.desenhar();
            break;
        case 4: //Fase Quintal
            Fase_Quintal.atualiza(deltaTempo);
            break; 
        case 5: //Fase Quarto
            Fase_Quarto.atualiza(deltaTempo);
            break;
        case 6: //Pausar Tela
            gerenciadorGrafico.resetaView();
            menuPause.desenhar();
            break;
        case 7: 
            gerenciadorGrafico.resetaView();
            creditos.desenhar();
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
    menuColocacao.setJanela(&gerenciadorGrafico.getJanela());


    menuColocacao.Recupera();
    //(static_cast<Menu>(creditos)).setJanela(&gerenciadorGrafico.getJanela());
    //(static_cast<Entidade>(creditos)).setJanela(&gerenciadorGrafico.getJanela());
    creditos.setJanela(&gerenciadorGrafico.getJanela());

    //InicializaJogadores();
    //InicializaFases();
}

void Jogo::InicializaFases()
{
    if (!Multiplayer)
        Bruxo = NULL;    
    /*
    Fase_Quintal.setFazendeira(Fazendeira);
    Fase_Quintal.setBruxo(Bruxo);
    Fase_Quarto.setFazendeira(Fazendeira);
    Fase_Quarto.setBruxo(Bruxo);
    */


    InicializaQuarto();
    InicializaQuintal();
}

void Jogo::InicializaQuintal()
{
    if (!Multiplayer)
        Bruxo = NULL;
    Fase_Quintal.setFazendeira(Fazendeira);
    Fase_Quintal.setBruxo(Bruxo);
    Fase_Quintal.setJanela(&gerenciadorGrafico.getJanela());
    Fase_Quintal.setView(&gerenciadorGrafico.getView());
    Fase_Quintal.setJogo(this);
    Fase_Quintal.inicializa();
}

void Jogo::InicializaQuarto()
{
    if (!Multiplayer)
        Bruxo = NULL;
    Fase_Quarto.setFazendeira(Fazendeira);
    Fase_Quarto.setBruxo(Bruxo);
    Fase_Quarto.setJanela(&gerenciadorGrafico.getJanela());
    Fase_Quarto.setView(&gerenciadorGrafico.getView());
    Fase_Quarto.setJogo(this);
    Fase_Quarto.inicializa();
}

void Jogo::InicializaJogadores()
{
    Fazendeira = new Jogador();
    Fazendeira->inicializa();
    Fazendeira->setJanela(&gerenciadorGrafico.getJanela());
    Fazendeira->setDimensoes(sf::Vector2f(COMPRIMENTO_JOGADOR, ALTURA_JOGADOR));

    //Fazendeira->setOrigem();
    Fazendeira->setPosicao(sf::Vector2f(640.f, 320.f));
    Fazendeira->setTextura("textures/Fazendeira.png");
    Fazendeira->setTexturaProjetil("textures/Projetil_Fazendeira.png");
    Fazendeira->setTeclas(sf::Keyboard::D, sf::Keyboard::A, sf::Keyboard::W, sf::Keyboard::Space);
    Fazendeira->setVelocidade(400.f);
    Fazendeira->setAlturaPulo(250.f);

    if (Multiplayer)
    {
        Bruxo = new Jogador();
        Bruxo->inicializa();
        Bruxo->setJanela(&gerenciadorGrafico.getJanela());
        Bruxo->setDimensoes(sf::Vector2f(COMPRIMENTO_JOGADOR, ALTURA_JOGADOR));

       // Bruxo->setOrigem();
        Bruxo->setPosicao(sf::Vector2f(640.f, 320.f));
        Bruxo->setTextura("textures/Bruxo.png");
        Bruxo->setTexturaProjetil("textures/Projetil_Bruxo.png");
        Bruxo->setTeclas(sf::Keyboard::Right, sf::Keyboard::Left, sf::Keyboard::Up, sf::Keyboard::Enter);
        Bruxo->setVelocidade(400.f);
        Bruxo->setAlturaPulo(250.f);
    }
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
                    menuColocacao.LoopMenu(&evento);
                    break;
                case 6:
                    menuPause.LoopMenu(&evento);
                    break;
                case 7: //Tela salvamento
                    creditos.LoopMenu(&evento);
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
    LimparArquivos();

    if (menuPause.getEstadoAtual() == 4)
        Fase_Quintal.salvar();
    else if (menuPause.getEstadoAtual() == 5)
        Fase_Quarto.salvar();

    ofstream gravadorEstado("saves/Estado.dat", ios::app);
    if (!gravadorEstado)
        cout << "Erro." << endl;
    gravadorEstado << menuPause.getEstadoAtual() << ' ' 
         << Multiplayer << ' '
         << Fazendeira->getPontuacao() << endl;
    gravadorEstado.close();
}

void Jogo::Recuperar()
{

    ifstream recuperadorEstado("saves/Estado.dat", ios::in);


    if (!recuperadorEstado)
        cout << "Erro ao abrir arquivo." << endl;

    int estado, pontos;

    while (!recuperadorEstado.eof())
        recuperadorEstado >> estado >> Multiplayer >> pontos;

    //menuColocacao.Recupera();

    RecuperarJogadores();

    Fase_Quintal.setFazendeira(Fazendeira);
    Fase_Quintal.setBruxo(Bruxo);
    Fase_Quarto.setFazendeira(Fazendeira);
    Fase_Quarto.setBruxo(Bruxo);

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
    for (int i = 0; i < pontos / 10; i++) {
        Fazendeira->incrementaPontuacao();
    }

    recuperadorEstado.close();
}

void Jogo::LimparArquivos() 
{
    ofstream deletarChefao("saves/Chefao.dat", ios::out);
    deletarChefao.close();
    ofstream deletarEstado("saves/Estado.dat", ios::out);
    deletarEstado.close();
    ofstream deletarEstaticos("saves/Estaticos.dat", ios::out);
    deletarEstaticos.close();
    ofstream deletarJogadores("saves/Jogadores.dat", ios::out);
    deletarJogadores.close();
    ofstream deletarEspinhos("saves/Espinhos.dat", ios::out);
    deletarEspinhos.close();
    ofstream deletarPassaros("saves/Passaros.dat", ios::out);
    deletarPassaros.close();
    ofstream deletarFantasmas("saves/Fantasmas.dat", ios::out);
    deletarFantasmas.close();
    ofstream deletarTeias("saves/Teias.dat", ios::out);
    deletarTeias.close();
    ofstream deletarProjeteis("saves/Projeteis.dat", ios::out);
    deletarProjeteis.close();
    ofstream deletarPorta("saves/Porta.dat", ios::out);
    deletarPorta.close();
}

void Jogo::RecuperarJogadores()
{
    ifstream recuperadorJogadores("saves/Jogadores.dat", ios::in);

    if (!recuperadorJogadores)
        cout << "Erro Jogadores." << endl;

    int vida;
    float posx, posy, movx, movy, cooldown;

    recuperadorJogadores >> vida >> posx >> posy >> movx >> movy >> cooldown;

    Fazendeira = new Jogador();
    Fazendeira->inicializa();
    Fazendeira->setVida(vida);
    Fazendeira->setPosicao(sf::Vector2f(posx, posy));
    Fazendeira->setTextura("textures/Fazendeira.png");
    Fazendeira->setTeclas(sf::Keyboard::D, sf::Keyboard::A, sf::Keyboard::W, sf::Keyboard::Space);
    Fazendeira->setMovimentoX(movx);
    Fazendeira->setMovimentoY(movy);
    Fazendeira->setCooldownAtaque(cooldown);
    Fazendeira->setTexturaProjetil("textures/Projetil_Fazendeira.png");
    Fazendeira->setVelocidade(400.f);
    Fazendeira->setAlturaPulo(250.f);
    Fazendeira->setJanela(&gerenciadorGrafico.getJanela());
    Fazendeira->setColidePlataforma(true);
    Fazendeira->setDimensoes(sf::Vector2f(COMPRIMENTO_JOGADOR, ALTURA_JOGADOR));
    Fazendeira->setOrigem();
    //gerenciadorFisica.setFazendeira(Fazendeira);
    //listaEntidades.inclua(static_cast<Entidade*>(Fazendeira));
    //listaPersonagens.inclua(static_cast <Personagem*> (Fazendeira));
    //gerenciadorFisica.incluaPersonagem(static_cast<Personagem*>(Fazendeira));

    if (getMultiplayer())
    {
        cout << "criou bruxo" << endl;
        Bruxo = new Jogador();
        recuperadorJogadores >> vida >> posx >> posy >> movx >> movy >> cooldown;

        Bruxo->setTextura("textures/Bruxo.png");

        Bruxo->inicializa();
        Bruxo->setVida(vida);
        Bruxo->setPosicao(sf::Vector2f(posx, posy));
        Bruxo->setTeclas(sf::Keyboard::Right, sf::Keyboard::Left, sf::Keyboard::Up, sf::Keyboard::Enter);
        Bruxo->setMovimentoX(movx);
        Bruxo->setMovimentoY(movy);
        Bruxo->setCooldownAtaque(cooldown);
        Bruxo->setTexturaProjetil("textures/Projetil_Bruxo.png");
        Bruxo->setVelocidade(400.f);
        Bruxo->setAlturaPulo(250.f);
        Bruxo->setJanela(&gerenciadorGrafico.getJanela());
        Bruxo->setColidePlataforma(true);
        Bruxo->setDimensoes(sf::Vector2f(COMPRIMENTO_JOGADOR, ALTURA_JOGADOR));
        Bruxo->setOrigem();

        //listaEntidades.inclua(static_cast<Entidade*>(Bruxo));
        //listaPersonagens.inclua(static_cast <Personagem*> (Bruxo));
    }

    recuperadorJogadores.close();

    //ofstream deletar("saves/Jogadores.dat", ios::out);
    //deletar.close();
}
