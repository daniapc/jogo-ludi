#include "Jogo.h"

Jogo::Jogo() :
    gerenciadorGrafico(),
    menuPrincipal(this),
    menuJogadores(this),
    menuFases(this),
    menuPause(this),
    menuColocacao(this),
    creditos(this),
    Estado(0),
    Jogador1(NULL),
    Jogador2(NULL),
    Multiplayer(false),
    Jogador1Fazendeira(true)
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
    
    gerenciadorGrafico.CarregarJogo();
    menuPrincipal.InicializaPlanoFundo();
    menuColocacao.Recupera();
    gerenciadorGrafico.tocarMusica("Menu_e_Quintal");
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

    case 6: //Menu Pause
        menuPause.LoopMenu(tecla);
        break;

    case 7: //Tela creditos
        creditos.LoopMenu(tecla);
        break;
    }
}

void Jogo::Atualiza(float deltaTempo)
{
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

void Jogo::mensagemCreditos(string mensagem){
    creditos.setMensagemFinal(mensagem);
}

void Jogo::setEstado(const int estado)
{
    Estado = estado;
}

int Jogo::getEstado()
{
    return Estado;
}

Jogador* Jogo::getJogador2()
{
    return Jogador2;
}

Jogador* Jogo::getJogador1()
{
    return Jogador1;
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

bool Jogo::getMultiplayer() const
{
    return Multiplayer;
}

GerenciadorGrafico& Jogo::getGerenciadorGrafico()
{
    return gerenciadorGrafico;
}

Menus::MenuColocacao& Jogo::getMenuColocacao()
{
    return menuColocacao;
}

void Jogo::InicializaFases()
{
    if (!Multiplayer)
        Jogador2 = NULL;    

    InicializaQuintal();
    InicializaQuarto();
}

void Jogo::InicializaQuintal()
{
    if (!Multiplayer)
        Jogador2 = NULL;
    Fase_Quintal.setGerenciadorGrafico(&gerenciadorGrafico);
    Fase_Quintal.setJogador1(Jogador1);
    Fase_Quintal.setJogador2(Jogador2);
    Fase_Quintal.setJogo(this);
    Fase_Quintal.inicializa();
}

void Jogo::InicializaQuarto()
{

    if (!Multiplayer)
        Jogador2 = NULL;

    Fase_Quarto.setGerenciadorGrafico(&gerenciadorGrafico);
    Fase_Quarto.setJogador1(Jogador1);
    Fase_Quarto.setJogador2(Jogador2);
    Fase_Quarto.setJogo(this);
    Fase_Quarto.inicializa();
}

void Jogo::InicializaJogadores()
{
    Jogador1 = new Jogador();
    Jogador1->setGerenciadorGrafico(&gerenciadorGrafico);
    Jogador1->setTexturas(Jogador1Fazendeira);
    gerenciadorGrafico.criaCorpo(Jogador1, COMPRIMENTO_JOGADOR, ALTURA_JOGADOR, 100.f, ALTURA_RESOLUCAO - ALTURA_PLATAFORMA - ALTURA_JOGADOR / 2,
        Jogador1->getTextura());
    Jogador1->setTeclas('D', 'A', 'W', ' ');

    if (Multiplayer)
    {
        Jogador2 = new Jogador();
        Jogador2->setGerenciadorGrafico(&gerenciadorGrafico);
        Jogador2->setTexturas(!Jogador1Fazendeira);
        gerenciadorGrafico.criaCorpo(Jogador2, COMPRIMENTO_JOGADOR, ALTURA_JOGADOR, 50.f, ALTURA_RESOLUCAO - ALTURA_PLATAFORMA - ALTURA_JOGADOR / 2,
            Jogador2->getTextura());
        Jogador2->setTeclas('R', 'L','U', 'E');
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
         << Jogador1->getPontuacao() << ' ' 
         << Jogador1Fazendeira << endl;
    gravadorEstado.close();
}

void Jogo::Recuperar()
{
    ifstream recuperadorEstado("saves/Estado.dat", ios::in);

    if (!recuperadorEstado)
        cout << "Erro ao abrir arquivo." << endl;

    int estado, pontos;

    while (!recuperadorEstado.eof())
        recuperadorEstado >> estado >> Multiplayer >> pontos >> Jogador1Fazendeira;

    RecuperarJogadores();

    Fase_Quintal.setJogador1(Jogador1);
    Fase_Quintal.setJogador2(Jogador2);
    Fase_Quarto.setJogador1(Jogador1);
    Fase_Quarto.setJogador2(Jogador2);
    Fase_Quintal.setGerenciadorGrafico(&getGerenciadorGrafico());
    Fase_Quarto.setGerenciadorGrafico(&getGerenciadorGrafico());
    if (estado == 4)
    {
        Fase_Quintal.setJogo(this);
        Fase_Quintal.recuperar();
        Estado = estado;
    }
    else if (estado == 5)
    {
        Fase_Quarto.setJogo(this);
        Fase_Quarto.recuperar();
        gerenciadorGrafico.tocarMusica("Quarto");
        Estado = estado;
    }
    for (int i = 0; i < pontos / 10; i++) 
    {
        Jogador1->incrementaPontuacao();
    }

    recuperadorEstado.close();
}

void Jogo::setJogador1Fazendeira(bool fazendeira)
{
    Jogador1Fazendeira = fazendeira;
}

bool Jogo::getJogador1Fazendeira() const
{
    return Jogador1Fazendeira;
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
    //ofstream deletarPorta("saves/Porta.dat", ios::out);
    //deletarPorta.close();
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
    bool jogador1fazendeira;

    recuperadorJogadores >> vida >> posx >> posy >> movx >> movy >> cooldown;

    Jogador1 = new Jogador();
    Jogador1->setGerenciadorGrafico(&getGerenciadorGrafico());
    Jogador1->setTexturas(Jogador1Fazendeira);
    gerenciadorGrafico.criaCorpo(Jogador1, COMPRIMENTO_JOGADOR, ALTURA_JOGADOR, 640.f, 320.f, 
        Jogador1->getTextura());
    Jogador1->setTeclas('D', 'A', 'W', ' ');
    Jogador1->setVida(vida);
    Jogador1->setPosicao( posx, posy );
    Jogador1->setMovimentoX(movx);
    Jogador1->setMovimentoY(movy);
    Jogador1->setCooldownAtaque(cooldown);

    if (getMultiplayer())
    {
        cout << "criou Jogador2" << endl;
        Jogador2 = new Jogador();
        recuperadorJogadores >> vida >> posx >> posy >> movx >> movy >> cooldown;

        Jogador2->setGerenciadorGrafico(&getGerenciadorGrafico());
        Jogador2->setTexturas(!Jogador1Fazendeira);
        gerenciadorGrafico.criaCorpo(Jogador2, COMPRIMENTO_JOGADOR, ALTURA_JOGADOR, 640.f, 320.f, 
            Jogador2->getTextura());
        Jogador2->setTeclas('R', 'L', 'U', 'E');
        Jogador2->setVida(vida);
        Jogador2->setPosicao( posx, posy );
        Jogador2->setMovimentoX(movx);
        Jogador2->setMovimentoY(movy);
        Jogador2->setCooldownAtaque(cooldown);
    }

    recuperadorJogadores.close();
}
