#include "GerenciadorGrafico.h"
#include "Jogo.h"

//int GerenciadorGrafico::IdAtual = 0;

GerenciadorGrafico::GerenciadorGrafico() :
    Janela(sf::VideoMode(static_cast <unsigned int>(COMPRIMENTO_RESOLUCAO), static_cast <unsigned int>(ALTURA_RESOLUCAO)),
        "Jogo"/*, sf::Style::Fullscreen*/),
    View(sf::Vector2f(COMPRIMENTO_RESOLUCAO / 2, ALTURA_RESOLUCAO / 2), sf::Vector2f(COMPRIMENTO_RESOLUCAO, ALTURA_RESOLUCAO))
    //IdAtual(0)
{
    Janela.setView(View);
}

void GerenciadorGrafico::LoopJogo(Jogo* jogo, int estado)
{
    sf::Clock Tempo;
    int Estado = estado;

    while (isOpen())
    {
        sf::Event evento;
        while (getJanela().pollEvent(evento))
        {
            if (evento.type == sf::Event::TextEntered) {
                if (evento.text.unicode == 27)
                {
                    jogo->setEstadoAtual(Estado);
                    Estado = 6;
                    jogo->setEstado(6);
                }
                jogo->MenusJogo(Estado, evento.text.unicode);
            }
            if (evento.type == sf::Event::Closed)
                getJanela().close();
        }

        clear();
        float DeltaTempo = Tempo.restart().asSeconds();
        if (DeltaTempo > 1.f / 20.f)
            DeltaTempo = 1.f / 20.f;

        jogo->Atualiza(DeltaTempo);
        Estado = jogo->getEstado();

        updateView();

        display();
    }
}

GerenciadorGrafico::~GerenciadorGrafico()
{
}

sf::RenderWindow& GerenciadorGrafico::getJanela()
{
	return Janela;
}

sf::View& GerenciadorGrafico::getView()
{
	return View;
}

void GerenciadorGrafico::updateView()
{
	Janela.setView(View);
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
    //int i = 0;

    //for (i = 0; i < 50; i++) {
    //    Texturas[i]. == text;
    //}
    sf::Texture* Textura = new sf::Texture();

    sf::RectangleShape* Corpo = new sf::RectangleShape();

    Corpo->setSize(sf::Vector2f(dimx, dimy));
    Corpo->setPosition(sf::Vector2f(posx, posy));
    Corpo->setOrigin(dimx/2, dimy/2);
    


    if (text == "" || !Textura->loadFromFile(text)) {
        cerr << "Erro. Nao foi possivel carregar a textura de uma Entidade." << endl;
        Corpo->setFillColor(sf::Color::White);
    }
   // Corpo->setTextureRect(sf::IntRect(150, 300, 300, 300));
    Corpo->setTexture(Textura);
    ListaCorpos.push_back(Corpo);

    if (pentidade != NULL)
        pentidade->setId(pentidade->getIdAtual());

    pentidade->incrementaIdAtual();

    //IdAtual++;
}

void GerenciadorGrafico::setDimensoes(int id, float x, float y)
{
    if (id == NULL)
        cout << "Erro 1 get set Posicao" << endl;
    else if (id <= 0 || id >= ListaCorpos.size())
        cout << "Erro 2 get set Posicao" << endl;
    else
        ListaCorpos[id]->setSize(sf::Vector2f(x, y));
}

float GerenciadorGrafico::getDimensoesX(int id)
{
    if (ListaCorpos[id] != NULL)
        return ListaCorpos[id]->getSize().x;
    else if (id < 0 || id >= ListaCorpos.size())
        cout << "Erro setPosicao" << endl;
    else
        cout << "ErrogetDimensoesX" << endl;

}

float GerenciadorGrafico::getDimensoesY(int id)
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
    //if (ListaCorpos[id] == NULL)
   //      cout << "ErrogetsetPosicao" << endl;
    if (id == NULL)
        cout << "Erro setPosicao" << endl;
    else if (id < 0 || id >= ListaCorpos.size())
        cout << "Erro setPosicao" << endl;
    else {
        
    }
    ListaCorpos[id]->setPosition(sf::Vector2f(x, y));

}

float GerenciadorGrafico::getPosicaoX(int id)
{
    return ListaCorpos[id]->getPosition().x;
}

float GerenciadorGrafico::getPosicaoY(int id)
{
    return ListaCorpos[id]->getPosition().y;
}


void GerenciadorGrafico::desenhar(int id, bool desalocavel)
{
        //if (ListaCorpos[id] != NULL)
    if (desalocavel == false)
        Janela.draw(*ListaCorpos[id]);
    else
        delete (ListaCorpos[id]);
}

void GerenciadorGrafico::desenhar(sf::Text texto)
{
	Janela.draw(texto);
}

void GerenciadorGrafico::fechar()
{
	Janela.close();
}

void GerenciadorGrafico::movimenta(int id, float x, float y)
{

     if (ListaCorpos[id] != NULL)
         ListaCorpos[id]->move(sf::Vector2f(x, y));
}

void GerenciadorGrafico::display()
{
	Janela.display();
}

void GerenciadorGrafico::clear()
{
	Janela.clear();
}

bool GerenciadorGrafico::isOpen()
{
	return Janela.isOpen();
}

void GerenciadorGrafico::TeclaApertada(char* direita, char* esquerda, char* pulo, char* atira)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        *direita = 'D';
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        *esquerda = 'A';
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        *pulo = 'W';
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
        *atira = ' ';
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        if (*direita == 'D')
            *direita = '>';
        else
            *direita = 'R';
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        if (*esquerda == 'A')
            *esquerda = '<';
        else
            *esquerda = 'L';
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        if (*pulo == 'W')
            *pulo = 'J';
        else
            *pulo = 'U';
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
    {
        if (*atira == ' ')
            *atira = 'S';
        else
            *atira = 'E';
    }
}

