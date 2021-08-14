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

void Jogo::Executar()
{
    Inicializa();
    LoopJogo();
}

void Jogo::Inicializa()
{

    menuPrincipal.setGerenciadorGrafico(&gerenciadorGrafico);
    menuJogadores.setGerenciadorGrafico(&gerenciadorGrafico);
    menuFases.setGerenciadorGrafico(&gerenciadorGrafico);
    menuPause.setGerenciadorGrafico(&gerenciadorGrafico);
    menuColocacao.setGerenciadorGrafico(&gerenciadorGrafico);
    creditos.setGerenciadorGrafico(&gerenciadorGrafico);
    menuColocacao.Recupera();

}

void Jogo::LoopJogo()
{
    gerenciadorGrafico.LoopJogo(this, Estado);
}

void Jogo::MenusJogo(int estado, char tecla)
{
    switch (estado)
    {
    case 0: //Menu Principal
        menuPrincipal.LoopMenu(tecla);
        break;
    case 1: //Menu Jogadores
        menuJogadores.LoopMenu(tecla);
        break;

    case 2: //Menu Fases
        menuFases.LoopMenu(tecla);
        break;

    case 3: //Menu Colocações
        menuColocacao.LoopMenu(tecla);
        break;

    case 6:
        menuPause.LoopMenu(tecla);
        break;

    case 7: //Tela creditos
        creditos.LoopMenu(tecla);
        break;
    }
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

GerenciadorGrafico& Jogo::getGerenciadorGrafico()
{
    return gerenciadorGrafico;
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

void Jogo::InicializaFases()
{
    if (!Multiplayer)
        Bruxo = NULL;    

    InicializaQuarto();
    InicializaQuintal();
}

void Jogo::InicializaQuintal()
{
    if (!Multiplayer)
        Bruxo = NULL;
    Fase_Quintal.setGerenciadorGrafico(&gerenciadorGrafico);
    Fase_Quintal.setFazendeira(Fazendeira);
    Fase_Quintal.setBruxo(Bruxo);
    //Fase_Quintal.setView(&gerenciadorGrafico.getView());
    Fase_Quintal.setJogo(this);
    Fase_Quintal.inicializa();
}

void Jogo::InicializaQuarto()
{
    cout << "Apareceu?" << endl;

    if (!Multiplayer)
        Bruxo = NULL;

    Fase_Quarto.setGerenciadorGrafico(&gerenciadorGrafico);

    Fase_Quarto.setFazendeira(Fazendeira);
    Fase_Quarto.setBruxo(Bruxo);
    //Fase_Quarto.setView(&gerenciadorGrafico.getView());
    Fase_Quarto.setJogo(this);

    Fase_Quarto.inicializa();
}

void Jogo::InicializaJogadores()
{
   // Jogador* lixo = new Jogador();
   // gerenciadorGrafico.criaCorpo(lixo, 0, 0, 0, 0, "");

    Fazendeira = new Jogador();

    Fazendeira->setGerenciadorGrafico(&gerenciadorGrafico);
    gerenciadorGrafico.criaCorpo(Fazendeira, COMPRIMENTO_JOGADOR, ALTURA_JOGADOR, 640.f, 320.f, "textures/Fazendeira.png");
    
    Fazendeira->setDimensoes( COMPRIMENTO_JOGADOR, ALTURA_JOGADOR );
    Fazendeira->setPosicao( 800.f, 220.f );
    Fazendeira->setTextura("textures/Fazendeira.png");
    Fazendeira->setTeclas('D', 'A', 'W', ' ');
    Fazendeira->setVelocidade(400.f);
    Fazendeira->setAlturaPulo(250.f);

    if (Multiplayer)
    {
        Bruxo = new Jogador();
        Bruxo->setGerenciadorGrafico(&gerenciadorGrafico);
        gerenciadorGrafico.criaCorpo(Bruxo, COMPRIMENTO_JOGADOR, ALTURA_JOGADOR, 640.f, 320.f, "textures/Bruxo.png");
        Bruxo->setDimensoes( COMPRIMENTO_JOGADOR, ALTURA_JOGADOR  );
        Bruxo->setPosicao( 640.f, 320.f );
        Bruxo->setTextura("textures/Bruxo.png");
        Bruxo->setTeclas('R', 'L','U', 'E');
        Bruxo->setVelocidade(400.f);
        Bruxo->setAlturaPulo(250.f);
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
        cout << "Erro Estado." << endl;
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

    //gerenciadorGrafico.criaCorpo(Lixo, 0, 0, 0, 0, "");
    RecuperarJogadores();

    Fase_Quintal.setFazendeira(Fazendeira);
    Fase_Quintal.setBruxo(Bruxo);
    Fase_Quarto.setFazendeira(Fazendeira);
    Fase_Quarto.setBruxo(Bruxo);
    Fase_Quintal.setGerenciadorGrafico(&getGerenciadorGrafico());
    Fase_Quarto.setGerenciadorGrafico(&getGerenciadorGrafico());
    if (estado == 4)
    {
        //Fase_Quintal.setView(&gerenciadorGrafico.getView());
        Fase_Quintal.setJogo(this);
        Fase_Quintal.recuperar();
        Estado = estado;
    }
    else if (estado == 5)
    {
        //Fase_Quarto.setView(&gerenciadorGrafico.getView());
        Fase_Quarto.setJogo(this);
        Fase_Quarto.recuperar();
        Estado = estado;
    }
    for (int i = 0; i < pontos / 10; i++) 
    {
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

void Jogo::setEstadoAtual(int estado)
{
    menuPause.setEstadoAtual(estado);

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
    Fazendeira->setGerenciadorGrafico(&getGerenciadorGrafico());
    gerenciadorGrafico.criaCorpo(Fazendeira, COMPRIMENTO_JOGADOR, ALTURA_JOGADOR, 640.f, 320.f, "textures/Fazendeira.png");

    Fazendeira->setVida(vida);
    Fazendeira->setPosicao( posx, posy );
    Fazendeira->setTextura("textures/Fazendeira.png");
    Fazendeira->setTeclas('D', 'A', 'W', ' ');
    Fazendeira->setMovimentoX(movx);
    Fazendeira->setMovimentoY(movy);
    Fazendeira->setCooldownAtaque(cooldown);
    Fazendeira->setVelocidade(400.f);
    Fazendeira->setAlturaPulo(250.f);
    Fazendeira->setColidePlataforma(true);
    Fazendeira->setDimensoes( COMPRIMENTO_JOGADOR, ALTURA_JOGADOR );


    if (getMultiplayer())
    {
        cout << "criou bruxo" << endl;
        Bruxo = new Jogador();
        recuperadorJogadores >> vida >> posx >> posy >> movx >> movy >> cooldown;

        Bruxo->setTextura("textures/Bruxo.png");
        Fazendeira->setGerenciadorGrafico(&getGerenciadorGrafico());
        gerenciadorGrafico.criaCorpo(Bruxo, COMPRIMENTO_JOGADOR, ALTURA_JOGADOR, 640.f, 320.f, "textures/Bruxo.png");
        Bruxo->setVida(vida);
        Bruxo->setPosicao( posx, posy );
        Bruxo->setTeclas('R', 'L', 'U', 'E');
        Bruxo->setMovimentoX(movx);
        Bruxo->setMovimentoY(movy);
        Bruxo->setCooldownAtaque(cooldown);
        Bruxo->setVelocidade(400.f);
        Bruxo->setAlturaPulo(250.f);
        Bruxo->setColidePlataforma(true);
        Bruxo->setDimensoes( COMPRIMENTO_JOGADOR, ALTURA_JOGADOR );

    }

    recuperadorJogadores.close();
}
