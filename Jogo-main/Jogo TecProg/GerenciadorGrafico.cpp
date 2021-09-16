#include "GerenciadorGrafico.h"
#include "Jogo.h"

GerenciadorGrafico::GerenciadorGrafico() :
    Janela(sf::VideoMode(static_cast <unsigned int>(COMPRIMENTO_RESOLUCAO), static_cast <unsigned int>(ALTURA_RESOLUCAO)),
        "Ludi", sf::Style::Fullscreen
    ),
    View(sf::Vector2f(COMPRIMENTO_RESOLUCAO / 2, ALTURA_RESOLUCAO / 2), sf::Vector2f(COMPRIMENTO_RESOLUCAO, ALTURA_RESOLUCAO))
{
    Janela.setView(View);
}

void GerenciadorGrafico::LoopJogo(Jogo* jogo, int estado)
{
    sf::Clock Tempo;
    int Estado = estado;

    while (Janela.isOpen())
    {
        sf::Event evento;
        while (Janela.pollEvent(evento))
        {
            if (evento.type == sf::Event::TextEntered) {
                if (evento.text.unicode == 27)
                {
                    int estadoant = jogo->getEstado();
                    if (estadoant == 4 || estadoant == 5) {
                        jogo->setEstadoAtual(Estado);
                        Estado = 6;
                        jogo->setEstado(6);
                    }
                }
                jogo->MenusJogo(Estado, evento.text.unicode);
            }
            if (evento.type == sf::Event::Closed)
                Janela.close();
        }

        Janela.clear();
        float DeltaTempo = Tempo.restart().asSeconds();
        if (DeltaTempo > 1.f / 20.f)
            DeltaTempo = 1.f / 20.f;

        jogo->Atualiza(DeltaTempo);
        Estado = jogo->getEstado();

        Janela.setView(View);

        Janela.display();
    }
}

void GerenciadorGrafico::CarregarJogo()
{
        InicializaFontes();      
        sf::RectangleShape Fundo_Carregamento;
        Fundo_Carregamento.setSize(sf::Vector2f(COMPRIMENTO_RESOLUCAO, ALTURA_RESOLUCAO));
        sf::Texture Textura_Carregamento;
        if (!Textura_Carregamento.loadFromFile("textures/Menu2.png"))
            cerr << "Erro. Nao foi possivel carregar a textura de uma Entidade." << endl;
        Texturas["textures/Menu2.png"] = Textura_Carregamento;
        Fundo_Carregamento.setTexture(&Texturas["textures/Menu2.png"]);

        sf::RectangleShape Ludi;
        sf::Texture Textura_Ludi;
        if (!Textura_Ludi.loadFromFile("textures/Titulo1.png"))
            cerr << "Erro. Nao foi possivel carregar uma textura." << endl;
        Texturas["textures/Titulo1.png"] = Textura_Ludi;
        Ludi.setTexture(&Texturas["textures/Titulo1.png"]);
        Ludi.setSize(sf::Vector2f(830.f * 5 / 8, 490.f * 5/8));
        Ludi.setOrigin(sf::Vector2f(Ludi.getLocalBounds().width / 2.f, Ludi.getLocalBounds().height / 2.f));
        Ludi.setPosition(sf::Vector2f(COMPRIMENTO_RESOLUCAO / 2, ALTURA_RESOLUCAO * 7 / 16));

        sf::Texture Textura_Barra_Carregamento;
        if (!Textura_Barra_Carregamento.loadFromFile("textures/Menu1.png"))
            cerr << "Erro. Nao foi possivel carregar uma textura." << endl;
        Texturas["textures/Menu1.png"] = Textura_Barra_Carregamento;
        Barra_Carregamento.setTexture(&Texturas["textures/Menu1.png"]);
        Barra_Carregamento.setSize(sf::Vector2f(48.f, 10.f));
        Barra_Carregamento.setPosition(sf::Vector2f(160.f, ALTURA_RESOLUCAO*7/8));

        sf::Text Creditos;
        Creditos.setFillColor(sf::Color::Black);
        Creditos.setFont(Fontes["KidsPlay"]);
        Creditos.setCharacterSize(20);
        Creditos.setString("Desenvolvido por Daniel Augusto Pires de Castro e Francisco Cardoso Becheli\n                 Arte feita por Martemis (Maira Pires de Castro)");
        Creditos.setOrigin(sf::Vector2f(Creditos.getLocalBounds().width / 2.f, Creditos.getLocalBounds().height / 2.f));
        Creditos.setPosition(sf::Vector2f(COMPRIMENTO_RESOLUCAO / 2, ALTURA_RESOLUCAO * 11 / 16+ 20.f));

        sf::Text Beta;
        Beta.setFillColor(sf::Color::Black);
        Beta.setFont(Fontes["KidsPlay"]);
        Beta.setCharacterSize(18);
        Beta.setString("(beta)");
        Beta.setOrigin(sf::Vector2f(Beta.getLocalBounds().width / 2.f, Beta.getLocalBounds().height / 2.f));
        Beta.setPosition(sf::Vector2f(COMPRIMENTO_RESOLUCAO*11/16, ALTURA_RESOLUCAO * 10 / 16));

        for (int i = 0; i < 2; i++) {
            Janela.draw(Fundo_Carregamento);
            Janela.draw(Barra_Carregamento);
            Janela.draw(Ludi);
            Janela.draw(Creditos);
            Janela.draw(Beta);
            Janela.display();
        }
        InicializaTexturas();
        InicializaMusicas();
        InicializaSubTexturas();
        InicializaCores();
}

GerenciadorGrafico::~GerenciadorGrafico()
{
}

void GerenciadorGrafico::resetaView()
{
	atualizaView(COMPRIMENTO_RESOLUCAO/2, ALTURA_RESOLUCAO/2);
}

void GerenciadorGrafico::atualizaView(float x, float y)
{
	View.setCenter(sf::Vector2f(x, y));
}

void GerenciadorGrafico::criaCorpo(Entidade* pentidade, float dimx, float dimy, float posx, float posy, string text)
{
    sf::RectangleShape* Corpo = new sf::RectangleShape();

    Corpo->setSize(sf::Vector2f(dimx, dimy));
    Corpo->setPosition(sf::Vector2f(posx, posy));
    Corpo->setOrigin(dimx/2, dimy/2);
    Corpo->setTexture(&Texturas[text]);
    if (SubTexturas[text] != sf::IntRect(0,0,0,0))
        Corpo->setTextureRect(SubTexturas[text]);

    ListaCorpos.push_back(Corpo);

    pentidade->setDesalocavel(false);
    if (pentidade != NULL)
        pentidade->setId(pentidade->getIdCorpoAtual());

    pentidade->incrementaIdCorpoAtual();
}


void GerenciadorGrafico::desenhar(Texto texto, int selecionado, int indice)
{
    sf::Text taux;

    taux.setFillColor(Cores[texto.getCor()]);
    taux.setCharacterSize(texto.getDimensao());
    taux.setFont(Fontes[texto.getFonte()]);
    taux.setString(texto.getMensagem());
    taux.setOrigin(sf::Vector2f(taux.getLocalBounds().width/2.f, taux.getLocalBounds().height/2.f));
    taux.setPosition(sf::Vector2f(texto.getPosicaoX(), texto.getPosicaoY()));

    Janela.draw(taux);
    if (selecionado == indice) {
        ListaCorpos[2]->setPosition(sf::Vector2f(taux.getPosition().x + taux.getLocalBounds().width/2+50.f, taux.getPosition().y));
        this->desenhar(2, false);
    }
}

void GerenciadorGrafico::desenhar(sf::Text texto)
{
    Janela.draw(texto);
}

void GerenciadorGrafico::setDimensoes(int id, float x, float y)
{
    ListaCorpos[id]->setSize(sf::Vector2f(x, y));
    ListaCorpos[id]->setOrigin( x / 2,  y / 2);
}

float GerenciadorGrafico::getDimensoesX(int id) const
{
    if (ListaCorpos[id] != NULL)
        return ListaCorpos[id]->getSize().x;
    else if (id < 0 || id >= ListaCorpos.size())
        cout << "Erro setPosicao" << endl;
    else
        cout << "ErrogetDimensoesX" << endl;

}

float GerenciadorGrafico::getDimensoesY(int id) const
{
    if (ListaCorpos[id] != NULL)
        return ListaCorpos[id]->getSize().y;
    else if (id < 0 || id >= ListaCorpos.size())
        cout << "Erro setPosicao" << endl;
    else
        cout << "ErrogetDimensoesY" << endl;

}

void GerenciadorGrafico::setPosicao(int id, float x, float y)
{
    if (id < 0 || id >= ListaCorpos.size())
        cout << "Erro setPosicao" << endl;

    ListaCorpos[id]->setPosition(sf::Vector2f(x, y));
}

float GerenciadorGrafico::getPosicaoX(int id) const
{
    return ListaCorpos[id]->getPosition().x;
}

float GerenciadorGrafico::getPosicaoY(int id) const
{
    return ListaCorpos[id]->getPosition().y;
}

void GerenciadorGrafico::setSubTextura(int id, string subtext)
{
    ListaCorpos[id]->setTextureRect(SubTexturas[subtext]);
}



void GerenciadorGrafico::desenhar(int id, bool desalocavel)
{
    if (desalocavel == false)
        Janela.draw(*ListaCorpos[id]);
    else
        delete (ListaCorpos[id]);
}

void GerenciadorGrafico::fechar()
{
    Janela.close();
}

void GerenciadorGrafico::tocarMusica(string musica)
{
    std::map<string, sf::Music*>::iterator itr;
    for (itr = Musicas.begin(); itr != Musicas.end(); itr++)
        itr->second->stop();
        
    Musicas[musica]->play();
    Musicas[musica]->setLoop(true);
}

void GerenciadorGrafico::movimenta(int id, float x, float y)
{

     if (ListaCorpos[id] != NULL)
         ListaCorpos[id]->move(sf::Vector2f(x, y));
}

void GerenciadorGrafico::TeclaApertada(char* direita, char* esquerda, char* pulo, char* atira)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        *direita = 'D';
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        *esquerda = 'A';
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        *pulo = 'W';
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        *atira = ' ';
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if (*direita == 'D')
            *direita = '>';
        else
            *direita = 'R';
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if (*esquerda == 'A')
            *esquerda = '<';
        else
            *esquerda = 'L';
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (*pulo == 'W')
            *pulo = 'J';
        else
            *pulo = 'U';
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        if (*atira == ' ')
            *atira = 'S';
        else
            *atira = 'E';
    }
}

void GerenciadorGrafico::CarregaTextura(string textura)
{
    string taux = textura;
    for (int i = 0; i < 3; i++)
        taux.erase(taux.end() - 1);
    taux = taux + "dat";
    cout << textura << " ";
    sf::Texture Textura;
    if (!Textura.loadFromFile(taux))
        cerr << "Erro. Nao foi possivel carregar a textura de uma Entidade." << endl;
    Texturas[textura] = Textura;   
    for (int i = 0; i < 44; i++) {
        Barra_Carregamento.move(sf::Vector2f(1.f, 0.f));
        Janela.draw(Barra_Carregamento);
        Janela.display();
    }
}

void GerenciadorGrafico::InicializaTexturas()
{
    CarregaTextura("textures/Bruxo_menu.png");
    CarregaTextura("textures/Fazendeira_menu.png");
    CarregaTextura("textures/Plataforma_Quintal.png");
    CarregaTextura("textures/Plataforma_Quarto.png");
    CarregaTextura("textures/Monstro_Moita.png");
    CarregaTextura("textures/Monstro_Roupas.png");
    CarregaTextura("textures/Teia.png");
    CarregaTextura("textures/Espinhos_Galhos.png");
    CarregaTextura("textures/Espinhos_Materiais.png");
    CarregaTextura("textures/Passaro.png");
    CarregaTextura("textures/Fantasma.png");
    CarregaTextura("textures/Bicho_Papao.png");
    CarregaTextura("textures/Projeteis.png");
    CarregaTextura("textures/Inicio_Fim.png");
    CarregaTextura("textures/Quintal.png");
    CarregaTextura("textures/Quarto.png");
    CarregaTextura("textures/Fazendeira.png");
    CarregaTextura("textures/Bruxo.png");
    CarregaTextura("textures/Selecao.png");
    cout << endl;
}


void GerenciadorGrafico::InicializaFontes()
{
    sf::Font *Fonte = new sf::Font();
    if (!Fonte->loadFromFile("fonts/arial.ttf"))
        cout << "Erro ao carregar fonte." << endl;
    Fontes["Arial"] = *Fonte;
    Fonte = new sf::Font();
    if (!Fonte->loadFromFile("fonts/KidsPlay.ttf"))
        cout << "Erro ao carregar fonte." << endl;
    Fontes["KidsPlay"] = *Fonte;

}

void GerenciadorGrafico::InicializaMusicas()
{
    sf::Music *Musica = new sf::Music();
    if (!Musica->openFromFile("musics/Menu_e_Quintal.ogg"))
        cout << "Erro ao carregar musica." << endl;
    Musicas["Menu_e_Quintal"] = Musica;
    Musica = new sf::Music();
    if (!Musica->openFromFile("musics/Quarto.ogg"))
        cout << "Erro ao carregar musica." << endl;
    Musicas["Quarto"] = Musica;
    Musica = new sf::Music();
    if (!Musica->openFromFile("musics/Creditos.ogg"))
        cout << "Erro ao carregar musica." << endl;
    Musicas["Creditos"] = Musica;
}

void GerenciadorGrafico::InicializaCores()
{
    Cores["Vermelho"] = sf::Color::Red;
    Cores["Verde"] = sf::Color::Green;
    Cores["Azul"] = sf::Color::Blue;
    Cores["Transparente"] = sf::Color::Transparent;
    Cores["Preto"] = sf::Color::Black;
    Cores["Ciano"] = sf::Color::Cyan;
    Cores["Amarelo"] = sf::Color::Yellow;
    Cores["Branco"] = sf::Color::White;

}

void GerenciadorGrafico::InicializaSubTexturas()
{
    SubTexturas["Transparente"] = sf::IntRect(0, 0, 1, 1);

    SubTexturas["textures/Fazendeira.png"] = sf::IntRect(285, 0, 660, 820); SubTexturas["Fazendeira_2"] = sf::IntRect(1045, 0, 660, 820); SubTexturas["Fazendeira_3"] = sf::IntRect(1800, 0, 630, 820);
    SubTexturas["Fazendeira_4"] = sf::IntRect(2540, 0, 640, 820); SubTexturas["Fazendeira_5"] = sf::IntRect(3280, 0, 640, 820); SubTexturas["Fazendeira_6"] = sf::IntRect(4025, 0, 640, 820);
    SubTexturas["Fazendeira_7"] = sf::IntRect(0, 875, 640, 820); SubTexturas["Fazendeira_8"] = sf::IntRect(745, 875, 640, 820); SubTexturas["Fazendeira_9"] = sf::IntRect(1485, 875, 900, 820);
    SubTexturas["Fazendeira_10"] = sf::IntRect(2495, 875, 900, 820); SubTexturas["Fazendeira_11"] = sf::IntRect(3490, 820, 680, 820); SubTexturas["Fazendeira_12"] = sf::IntRect(4270, 820, 680, 820);

    SubTexturas["textures/Bruxo.png"] = sf::IntRect(145, 0, 580, 820); SubTexturas["Bruxo_2"] = sf::IntRect(820, 0, 580, 820); SubTexturas["Bruxo_3"] = sf::IntRect(1495, 0, 530, 820);
    SubTexturas["Bruxo_4"] = sf::IntRect(2130, 0, 530, 820); SubTexturas["Bruxo_5"] = sf::IntRect(2765, 0, 530, 820); SubTexturas["Bruxo_6"] = sf::IntRect(3405, 0, 530, 820);
    SubTexturas["Bruxo_7"] = sf::IntRect(0, 930, 530, 820); SubTexturas["Bruxo_8"] = sf::IntRect(630, 930, 530, 820); SubTexturas["Bruxo_9"] = sf::IntRect(1260, 930, 760, 820);
    SubTexturas["Bruxo_10"] = sf::IntRect(2100, 930, 760, 820); SubTexturas["Bruxo_11"] = sf::IntRect(2855, 950, 570, 820); SubTexturas["Bruxo_12"] = sf::IntRect(3460, 950, 570, 820);

    SubTexturas["textures/Plataforma_Quintal.png"] = sf::IntRect(0, 0, 620, 630); SubTexturas["Plataforma_Quintal_2"] = sf::IntRect(660, 0, 620, 630); SubTexturas["Plataforma_Quintal_3"] = sf::IntRect(1320, 10, 620, 630);
    SubTexturas["Plataforma_Quintal_4"] = sf::IntRect(1995, 0, 620, 630); SubTexturas["Plataforma_Quintal_5"] = sf::IntRect(2675, 0, 620, 630);

    SubTexturas["textures/Plataforma_Quarto.png"] = sf::IntRect(0, 0, 630, 650); SubTexturas["Plataforma_Quarto_2"] = sf::IntRect(725,10, 620, 630); SubTexturas["Plataforma_Quarto_3"] = sf::IntRect(1450, 10, 620, 630);
    SubTexturas["Plataforma_Quarto_4"] = sf::IntRect(2175, 10, 620, 630); SubTexturas["Plataforma_Quarto_5"] = sf::IntRect(2915, 10, 620, 630);

    SubTexturas["textures/Monstro_Moita.png"] = sf::IntRect(0, 140, 880, 480); SubTexturas["Monstro_Moita_2"] = sf::IntRect(880, 140, 880, 480); SubTexturas["Monstro_Moita_3"] = sf::IntRect(1770, 0, 1020, 620);
    SubTexturas["textures/Monstro_Roupas.png"] = sf::IntRect(0, 140, 880, 480); SubTexturas["Monstro_Roupas_2"] = sf::IntRect(880, 140, 880, 480); SubTexturas["Monstro_Roupas_3"] = sf::IntRect(1770, 0, 1020, 620);

    SubTexturas["textures/Teia.png"] = sf::IntRect(25, 15, 430, 450); SubTexturas["Teia_2"] = sf::IntRect(640, 15, 430, 450);

    SubTexturas["Espinhos_Galhos_2"] = sf::IntRect(0, 0, 760, 475); SubTexturas["textures/Espinhos_Galhos.png"] = sf::IntRect(870, 0, 760, 475);
    SubTexturas["Espinhos_Materiais_2"] = sf::IntRect(0, 0, 760, 475); SubTexturas["textures/Espinhos_Materiais.png"] = sf::IntRect(890, 0, 760, 475);

    SubTexturas["textures/Passaro.png"] = sf::IntRect(0, 0, 630, 525); SubTexturas["Passaro_2"] = sf::IntRect(750,  0, 630, 525);
    SubTexturas["Passaro_3"] = sf::IntRect(1475, 0, 630, 525); SubTexturas["Passaro_4"] = sf::IntRect(2220,  0, 630, 525);

    SubTexturas["textures/Fantasma.png"] = sf::IntRect(0, 0, 630, 500); SubTexturas["Fantasma_2"] = sf::IntRect(780, 0, 630, 500);

    SubTexturas["textures/Bicho_Papao.png"] = sf::IntRect(405, 10, 1565, 1580); SubTexturas["Bicho_Papao_2"] = sf::IntRect(2280, 0, 1565, 1580); SubTexturas["Bicho_Papao_3"] = sf::IntRect(4120, 10, 1280, 1725);
    SubTexturas["Bicho_Papao_4"] = sf::IntRect(5665, 10, 1565, 1580); SubTexturas["Bicho_Papao_5"] = sf::IntRect(7500, 0, 1565, 1580); SubTexturas["Bicho_Papao_6"] = sf::IntRect(9345, 0, 1280, 1725);;
    SubTexturas["Bicho_Papao_7"] = sf::IntRect(0, 290, 110, 130);

    SubTexturas["textures/Projeteis.png"] = sf::IntRect(0, 0, 126, 134); SubTexturas["Projeteis_2"] = sf::IntRect(170,  0, 126, 134); SubTexturas["Projeteis_3"] = sf::IntRect(340,  0, 156, 134);
    SubTexturas["Projeteis_4"] = sf::IntRect(535,  0, 155, 134); SubTexturas["Projeteis_5"] = sf::IntRect(735,  0, 140, 134); SubTexturas["Projeteis_6"] = sf::IntRect(918, 0, 140, 134);
    SubTexturas["Projeteis_7"] = sf::IntRect(1101, 0, 100, 134); SubTexturas["Projeteis_8"] = sf::IntRect(1240, 0, 140, 134); SubTexturas["Projeteis_9"] = sf::IntRect(1390, 0, 140, 134);

    SubTexturas["textures/Inicio_Fim.png"] = sf::IntRect(0, 500, 520, 580); SubTexturas["Inicio_Fim_2"] = sf::IntRect(820, 110, 835, 1360); SubTexturas["Inicio_Fim_3"] = sf::IntRect(1950, 135, 225, 1300);
    SubTexturas["Inicio_Fim_4"] = sf::IntRect(2475, 135, 225, 1300); SubTexturas["Inicio_Fim_5"] = sf::IntRect(3000, 0, 620, 1580); 

    SubTexturas["textures/Quintal.png"] = sf::IntRect(0, 0, 3829, 1089); SubTexturas["Quintal_Menu"] = sf::IntRect(0, 0, 1914, 1089);
    SubTexturas["textures/Quarto.png"] = sf::IntRect(0, 0, 3959, 1093); SubTexturas["Quarto_Menu"] = sf::IntRect(0, 0, 1979, 1093);

    SubTexturas["textures/Menu1.png"] = sf::IntRect(0, 0, 1627, 1000);
    SubTexturas["textures/Menu2.png"] = sf::IntRect(0, 0, 1627, 1000);
}







