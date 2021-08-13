#include "Quarto.h"
#include "Jogo.h"

Quarto::Quarto() :
	Fase()
{
}

Quarto::~Quarto()
{
	this->limparTudo();
}

void Quarto::inicializa()
{
	View->setCenter(sf::Vector2f(COMPRIMENTO_RESOLUCAO/2, ALTURA_RESOLUCAO/2));

	srand(time(NULL));

	gerenciadorFisica.setListaEntidades(&listaEntidades);
	gerenciadorFisica.setListaPersonagens(&listaPersonagens);
	//gerenciadorFisica.setFazendeira(Fazendeira);

	listaEntidades.inclua(static_cast <Entidade*> (&Cenario));

	/*
	Fazendeira = new Jogador();
	Fazendeira->inicializa();
	Fazendeira->setJanela(Janela);
	Fazendeira->setFaseAtual(this);
	Fazendeira->setDimensoes(sf::Vector2f(COMPRIMENTO_JOGADOR, ALTURA_JOGADOR));
	Fazendeira->setOrigem();
	Fazendeira->setPosicao(sf::Vector2f(640.f, 320.f));
	Fazendeira->setTextura("textures/Fazendeira.png");
	Fazendeira->setTeclas(sf::Keyboard::D, sf::Keyboard::A, sf::Keyboard::W, sf::Keyboard::Space);
	Fazendeira->setVelocidade(400.f);
	Fazendeira->setAlturaPulo(250.f);
	gerenciadorFisica.setFazendeira(Fazendeira);
	//gerenciadorFisica.incluaPersonagem(static_cast<Personagem*>(Fazendeira));

	if (jogo->getMultiplayer())
	{
		Bruxo = new Jogador();
		Bruxo->inicializa();
		Bruxo->setJanela(Janela);
		Bruxo->setFaseAtual(this);
		Bruxo->setDimensoes(sf::Vector2f(COMPRIMENTO_JOGADOR, ALTURA_JOGADOR));
		Bruxo->setOrigem();
		Bruxo->setPosicao(sf::Vector2f(640.f, 320.f));
		Bruxo->setTextura("textures/Bruxo.png");
		Bruxo->setTeclas(sf::Keyboard::Right, sf::Keyboard::Left, sf::Keyboard::Up, sf::Keyboard::Enter);
		Bruxo->setVelocidade(400.f);
		Bruxo->setAlturaPulo(250.f);

		//gerenciadorFisica.incluaPersonagem(static_cast<Personagem*>(Bruxo));
	}
	*/

	Cenario.setJanela(Janela);
	Cenario.setTextura("textures/Background_quarto.jpg");
	Cenario.setDimensoes(sf::Vector2f(COMPRIMENTO_CENARIO, ALTURA_RESOLUCAO));
	Cenario.setPosicao(sf::Vector2f(COMPRIMENTO_RESOLUCAO, ALTURA_RESOLUCAO / 2));

	criaPlataformas();

	for (int i = 0; i < rand() % 4 + 3; i++)
	{
		criaFantasma(sf::Vector2f(rand() % (static_cast<int>(COMPRIMENTO_CENARIO - 400)) + 200, 
						rand() % static_cast<int>(ALTURA_RESOLUCAO / 2) + ALTURA_FANTASMA / 2));
	}
	for (int i = 0; i < rand() % 4 + 3; i++)
	{
		criaEstatico(sf::Vector2f(rand() % (static_cast<int>(COMPRIMENTO_CENARIO - 400)) + 200,
			rand() % static_cast<int>(ALTURA_RESOLUCAO) - (ALTURA_PLATAFORMA + ALTURA_ESTATICO/2)),
			"textures/Estatico_vulneravel_quarto.png");
	}

	for (int i = 0; i < rand() % 6 + 3; i++)
	{
		criaTeia(sf::Vector2f(rand() % (static_cast<int>(COMPRIMENTO_CENARIO - 400)) + 200,
			ALTURA_RESOLUCAO - (ALTURA_PLATAFORMA + ALTURA_TEIA / 2)));
	}

	for (int i = 0; i < rand() % 6 + 3; i++)
	{
		criaEspinho(sf::Vector2f(rand() % (static_cast<int>(COMPRIMENTO_CENARIO-400)) + 200,
			ALTURA_RESOLUCAO - (ALTURA_PLATAFORMA + ALTURA_ESPINHO/2)),
			"textures/Materiais.png");
	}
	
	criaChefao(sf::Vector2f(2000.f,600.f));

	if (Fazendeira == NULL)
		cout << "Eh null" << endl;
	//Fazendeira->setFaseAtual(this);
	listaEntidades.inclua(static_cast <Entidade*> (Fazendeira));
	listaPersonagens.inclua(static_cast <Personagem*> (Fazendeira));
	if (jogo->getMultiplayer())
	{

		//Bruxo->setFaseAtual(this);
		listaEntidades.inclua(static_cast <Entidade*> (Bruxo));
		listaPersonagens.inclua(static_cast <Personagem*> (Bruxo));
	}

}

void Quarto::desenhar()
{
	listaEntidades.desenhar();
}

void Quarto::atualiza(float deltaTempo)
{
	listaPersonagens.limpar();
	listaEntidades.limpar();

	atualizaView();

	gerenciadorFisica.checaColisoes();

	listaEntidades.atualiza(deltaTempo);

	if (ChefaoMorreu)
	{
		ChefaoMorreu = false;
		Porta* cabideiro;

		cabideiro = new Porta();
		cabideiro->setTextura("textures/Cabideiro.png");
		cabideiro->setJogo(jogo);
		cabideiro->setJanela(Janela);

		
		listaEntidades.inclua(static_cast<Entidade*> (cabideiro));
	}

	desenhar();
}

void Quarto::limparTudo()
{
	listaPersonagens.limparTudo();
	listaEntidades.limparTudo();
	View = NULL;
	Fazendeira = NULL;
	Bruxo = NULL;
	jogo = NULL;
}

void Quarto::setChefaoMorreu(bool chefaomorreu)
{
	ChefaoMorreu = chefaomorreu;
}

void Quarto::recuperar()
{
	listaEntidades.inclua(static_cast<Entidade*> (&Cenario));
	criaPlataformas();
	Cenario.setJanela(Janela);
	Cenario.setTextura("textures/Background_quarto.jpg");
	Cenario.setDimensoes(sf::Vector2f(COMPRIMENTO_CENARIO, ALTURA_RESOLUCAO));

	Cenario.setPosicao(sf::Vector2f(COMPRIMENTO_RESOLUCAO, ALTURA_RESOLUCAO / 2));

	gerenciadorFisica.setListaEntidades(&listaEntidades);
	gerenciadorFisica.setListaPersonagens(&listaPersonagens);
	recuperarProjeteis();
	recuperarEstaticos();
	recuperarFantasmas();
	recuperarTeias();
	recuperarEspinhos();
	recuperarChefao();
	recuperarPorta();
	//recuperarJogadores();

	Fazendeira->setFaseAtual(this);
	listaEntidades.inclua(static_cast<Entidade*>(Fazendeira));
	listaPersonagens.inclua(static_cast <Personagem*> (Fazendeira));
	if (jogo->getMultiplayer()) {
		Bruxo->setFaseAtual(this);
		listaEntidades.inclua(static_cast<Entidade*>(Bruxo));
		listaPersonagens.inclua(static_cast <Personagem*> (Bruxo));
	}

}

void Quarto::recuperarFantasmas()
{
	ifstream recuperadorFantasmas("saves/Fantasmas.dat", ios::in);

	if (!recuperadorFantasmas)
		cout << "Erro." << endl;

	while (!recuperadorFantasmas.eof())
	{
		Fantasma* novo = NULL;
		int vida;
		float posx, posy, movx, movy, limxdir, limxesq, limcima, limbaixo, cooldown;

		recuperadorFantasmas >> vida >> posx >> posy >> movx >> movy >> limxdir >> limxesq >> limcima >> limbaixo >> cooldown;

		novo = new Fantasma();
		novo->inicializa();
		novo->setVida(vida);
		novo->setPosicao(sf::Vector2f(posx, posy));
		novo->setLimiteXDir(limxdir);
		novo->setLimiteXEsq(limxesq);
		novo->setLimiteYCima(limcima);
		novo->setLimiteYBaixo(limbaixo);
		novo->setMovimentoX(movx);
		novo->setMovimentoY(movy);
		novo->setCooldownAtaque(cooldown);
		novo->setVelocidade(200.f);
		novo->setJanela(Janela);
		novo->setTextura("textures/Fantasma_direita.png");
		novo->setColidePlataforma(false);
		novo->setDimensoes(sf::Vector2f(COMPRIMENTO_FANTASMA, ALTURA_FANTASMA));
		//novo->setOrigem();

		listaEntidades.inclua(static_cast<Entidade*>(novo));
		listaPersonagens.inclua(static_cast <Personagem*> (novo));
		//gerenciadorFisica.incluaPersonagem(static_cast<Personagem*>(novo));
		//erenciadorFisica.incluaEntidade(static_cast<Entidade*>(novo));
	}

	recuperadorFantasmas.close();

	/*
	ofstream deletar("saves/Fantasmas.dat", ios::out);
	deletar.close();
	*/

}

void Quarto::recuperarChefao()
{
	ifstream recuperadorChefao("saves/Chefao.dat", ios::in);

	if (!recuperadorChefao)
		cout << "Erro." << endl;

	while (!recuperadorChefao.eof())
	{
		Chefao* novo = NULL;
		int vida;
		float posx, posy, cooldown;

		recuperadorChefao >> vida >> posx >> posy >> cooldown;

		novo = new Chefao();
		novo->inicializa();
		novo->setVida(vida);
		novo->setPosicao(sf::Vector2f(posx, posy));
		novo->setCooldownAtaque(cooldown);
		novo->setVelocidade(50.f);
		novo->setJanela(Janela);
		novo->setTextura("textures/Chefao.png");
		novo->setTexturaProjetil("textures/Projetil_Chefao.png");
		novo->setColidePlataforma(true);
		novo->setDimensoes(sf::Vector2f(COMPRIMENTO_CHEFAO, ALTURA_CHEFAO));
		//novo->setOrigem();
		novo->setFaseAtual(this);

		listaEntidades.inclua(static_cast<Entidade*>(novo));
		listaPersonagens.inclua(static_cast <Personagem*> (novo));
		//gerenciadorFisica.incluaPersonagem(static_cast<Personagem*>(novo));
		//gerenciadorFisica.incluaEntidade(static_cast<Entidade*>(novo));
	}

	recuperadorChefao.close();

	// deletar("saves/Chefao.dat", ios::out);
	//deletar.close();
}

void Quarto::recuperarPorta()
{
	ifstream recuperadorPorta("saves/Porta.dat", ios::in);

	if (!recuperadorPorta)
		cout << "Erro." << endl;

	while (!recuperadorPorta.eof())
	{
		Porta* novo = NULL;
		float posx, posy;

		recuperadorPorta >> posx >> posy;

		novo = new Porta();

		novo->setPosicao(sf::Vector2f(posx, posy));
		novo->setDimensoes(sf::Vector2f(50.0f, 100.0f));
		novo->setTextura("textures/Cabideiro.png");
		novo->setJanela(Janela);
		novo->setJogo(jogo);

		listaEntidades.inclua(static_cast <Entidade*>(novo));
	}
	recuperadorPorta.close();
}

void Quarto::criaFantasma(sf::Vector2f posicao)
{
	Fantasma* novo = NULL;
	novo = new Fantasma();

	novo->setPosicao(posicao);
	novo->setDimensoes(sf::Vector2f(COMPRIMENTO_FANTASMA, ALTURA_FANTASMA));
	//novo->setOrigem();
	novo->setJanela(Janela);
	novo->setTextura("textures/Fantasma_direita.png");
	novo->setLimiteXEsq(posicao.x);
	novo->setLimiteXDir(posicao.x + 200.0f);

	//ListaFantasmas.push_back(novo);
	listaEntidades.inclua(static_cast <Entidade*>(novo));
	listaPersonagens.inclua(static_cast <Personagem*> (novo));
	//gerenciadorFisica.incluaEntidade(static_cast <Entidade*>(novo));
	//gerenciadorFisica.incluaPersonagem(novo);

	novo->setColidePlataforma(false);
	novo->inicializa();
	novo->setVelocidade(200.f);
	novo->setVida(2);
}

void Quarto::criaChefao(sf::Vector2f posicao)
{
	Chefao* novo = NULL;
	novo = new Chefao();

	novo->setFaseAtual(this);
	novo->setPosicao(posicao);
	novo->setDimensoes(sf::Vector2f(COMPRIMENTO_CHEFAO, ALTURA_CHEFAO));
	//novo->setOrigem();
	novo->inicializa();
	novo->setVida(3);
	novo->setVelocidade(50.f);
	novo->setJanela(Janela);
	novo->setTextura("textures/Chefao.png");
	novo->setTexturaProjetil("textures/Projetil_Chefao.png");
	novo->setColidePlataforma(true);

	listaEntidades.inclua(static_cast <Entidade*> (novo));
	listaPersonagens.inclua(static_cast <Personagem*> (novo));
	//gerenciadorFisica.incluaPersonagem(static_cast <Personagem*> (novo));
	//gerenciadorFisica.incluaEntidade(static_cast <Entidade*>(novo));
}

void Quarto::criaPlataformas()
{
	for (int i = 0; i < 10; i++) {

		criaPlataforma(sf::Vector2f(900.f + COMPRIMENTO_PLATAFORMA * i, 337.5f), "textures/Estante_meio.png");
		criaPlataforma(sf::Vector2f(1500.f + COMPRIMENTO_PLATAFORMA * i, 337.5f), "textures/Estante_meio.png");
		criaPlataforma(sf::Vector2f(500.f + COMPRIMENTO_PLATAFORMA * i, 517.5f), "textures/Estante_meio.png");
		criaPlataforma(sf::Vector2f(1800.f + COMPRIMENTO_PLATAFORMA * i, 157.5f), "textures/Estante_meio.png");
		//criaPlataforma(sf::Vector2f(1800.f + COMPRIMENTO_PLATAFORMA*i, 1.f*(ALTURA_RESOLUCAO/4.f - ALTURA_PLATAFORMA)/4.f + 0.f*ALTURA_PLATAFORMA + ALTURA_PLATAFORMA/2.f));
	}

	for (int i = 0; i < 5; i++) {
		criaPlataforma(sf::Vector2f(2000.f + COMPRIMENTO_PLATAFORMA * i, 517.5f), "textures/Estante_meio.png");
		//criaPlataforma(sf::Vector2f(2000.f + COMPRIMENTO_PLATAFORMA * i, 2.f*(ALTURA_RESOLUCAO/4.f - ALTURA_PLATAFORMA)/4.f + 1.f*ALTURA_PLATAFORMA + ALTURA_PLATAFORMA/2.f));
	}


	criaBordas();
	criaPlataforma(sf::Vector2f(-COMPRIMENTO_PLATAFORMA / 2, ALTURA_RESOLUCAO / 2), "", sf::Vector2f(COMPRIMENTO_PLATAFORMA, ALTURA_RESOLUCAO));
	criaPlataforma(sf::Vector2f(COMPRIMENTO_CENARIO + COMPRIMENTO_PLATAFORMA / 2, ALTURA_RESOLUCAO / 2), "", sf::Vector2f(COMPRIMENTO_PLATAFORMA, ALTURA_RESOLUCAO));
}

