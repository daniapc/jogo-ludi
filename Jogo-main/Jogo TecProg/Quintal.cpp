#include "Quintal.h"
#include "Jogo.h"

Quintal::Quintal() :
	Fase(),
	porta()
{
}

Quintal::~Quintal()
{
	this->limparTudo();
}

void Quintal::inicializa()
{
	View->setCenter(sf::Vector2f(COMPRIMENTO_RESOLUCAO/2, ALTURA_RESOLUCAO/2));

	srand(time(NULL));

	gerenciadorFisica.setListaEntidades(&listaEntidades);
	gerenciadorFisica.setListaPersonagens(&listaPersonagens);
	//gerenciadorFisica.setFazendeira(Fazendeira);


	//Fazendeira->setFaseAtual(this);
	listaEntidades.inclua(static_cast <Entidade*> (&Cenario));
	Cenario.setJanela(Janela);
	Cenario.setTextura("textures/Background.png");
	Cenario.setDimensoes(sf::Vector2f(COMPRIMENTO_CENARIO, ALTURA_RESOLUCAO));

	Cenario.setPosicao(sf::Vector2f(COMPRIMENTO_RESOLUCAO, ALTURA_RESOLUCAO/2));

	criaPlataformas();

	for (int i = 0; i < rand() % 6 + 3; i++)
	{
		criaEspinho(sf::Vector2f(rand() % (static_cast<int>(COMPRIMENTO_CENARIO-400)) + 200,
			ALTURA_RESOLUCAO - (ALTURA_PLATAFORMA + ALTURA_ESPINHO/2)),
			"textures/Espinhos.png");
	}

	for (int i = 0; i < rand() % 6 + 3; i++)
	{
		criaTeia(sf::Vector2f(rand() % (static_cast<int>(COMPRIMENTO_CENARIO - 400)) + 200,
			ALTURA_RESOLUCAO - (ALTURA_PLATAFORMA + ALTURA_TEIA / 2)));
	}

	for (int i = 0; i < rand() % 4 + 3; i++)
	{
		criaPassaro(sf::Vector2f(rand() % (static_cast<int>(COMPRIMENTO_CENARIO - 400)) + 200,
			rand() % static_cast<int>(ALTURA_RESOLUCAO / 2) + ALTURA_FANTASMA / 2));
	}

	for (int i = 0; i < rand() % 4 + 3; i++)
	{
		criaEstatico(sf::Vector2f(rand() % (static_cast<int>(COMPRIMENTO_CENARIO - 400)) + 200,
			rand() % static_cast<int>(ALTURA_RESOLUCAO) - (ALTURA_PLATAFORMA + ALTURA_ESTATICO/2)),
			"textures/Estatico_vulneravel.png");
	}

	porta.setJanela(Janela);
	porta.setJogo(jogo);
	porta.setTextura("textures/Porta.png");
	listaEntidades.inclua(static_cast<Entidade*> (&porta));

	//gerenciadorFisica.incluaEntidade(static_cast<Entidade*> (&porta));

	listaEntidades.inclua(static_cast <Entidade*> (Fazendeira));
	listaPersonagens.inclua(static_cast <Personagem*> (Fazendeira));
	if (jogo->getMultiplayer())
	{

		//Bruxo->setFaseAtual(this);
		listaEntidades.inclua(static_cast <Entidade*> (Bruxo));
		listaPersonagens.inclua(static_cast <Personagem*> (Bruxo));
	}
}

void Quintal::desenhar()
{
	listaEntidades.desenhar();
}

void Quintal::atualiza(float deltaTempo)
{

	if (getFazendeira()->getDesalocavel())
		cout << "Fazendeira desalocavel true" << endl;

	listaPersonagens.limpar();
	listaEntidades.limpar();

	if (getFazendeira() == NULL)
		cout << "Fazendeira nula" << endl;

	atualizaView();

	gerenciadorFisica.checaColisoes();

	listaEntidades.atualiza(deltaTempo);

	desenhar();
}

void Quintal::limparTudo()
{
	listaPersonagens.limparTudo();
	listaEntidades.limparTudo();
	View = NULL;
	Fazendeira = NULL;
	Bruxo = NULL;
	jogo = NULL;
}

void Quintal::criaPassaro(sf::Vector2f posicao)
{
	Passaro* novo = NULL;
	novo = new Passaro();

	novo->setFaseAtual(this);
	novo->setPosicao(posicao);
	novo->setDimensoes(sf::Vector2f(COMPRIMENTO_ESPINHO, ALTURA_ESPINHO));
	//novo->setOrigem();
	novo->inicializa();
	novo->setVida(3);
	novo->setVelocidade(200.f);
	novo->setJanela(Janela);
	novo->setTextura("textures/Passaro_direita.png");
	novo->setTexturaProjetil("textures/Projetil_Passaro.png");
	novo->setColidePlataforma(true);
	novo->setLimiteXEsq(posicao.x);
	novo->setLimiteXDir(posicao.x + 300.0f);

	//ListaPassaros.push_back(novo);
	listaEntidades.inclua(static_cast <Entidade*> (novo));
	listaPersonagens.inclua(static_cast <Personagem*> (novo));
	//gerenciadorFisica.incluaPersonagem(novo);
	//gerenciadorFisica.incluaEntidade(static_cast <Entidade*>(novo));
}


void Quintal::criaPlataformas(){

	//Plataforma principal de baixo.
	criaBordas();

	//Plataformas específicas
	for (int i = 0; i < 10; i++){

		criaPlataforma(sf::Vector2f(900.f + COMPRIMENTO_PLATAFORMA * i, 337.5f));
		criaPlataforma(sf::Vector2f(1500.f + COMPRIMENTO_PLATAFORMA*i, 337.5f));
		criaPlataforma(sf::Vector2f(500.f + COMPRIMENTO_PLATAFORMA*i, 517.5f));
		criaPlataforma(sf::Vector2f(1800.f + COMPRIMENTO_PLATAFORMA*i, 157.5f));
		//criaPlataforma(sf::Vector2f(1800.f + COMPRIMENTO_PLATAFORMA*i, 1.f*(ALTURA_RESOLUCAO/4.f - ALTURA_PLATAFORMA)/4.f + 0.f*ALTURA_PLATAFORMA + ALTURA_PLATAFORMA/2.f));

	}
	for (int i = 0; i < 5; i++){
		criaPlataforma(sf::Vector2f(2000.f + COMPRIMENTO_PLATAFORMA*i, 517.5f));
		//criaPlataforma(sf::Vector2f(2000.f + COMPRIMENTO_PLATAFORMA * i, 2.f*(ALTURA_RESOLUCAO/4.f - ALTURA_PLATAFORMA)/4.f + 1.f*ALTURA_PLATAFORMA + ALTURA_PLATAFORMA/2.f));
	}

	criaPlataforma(sf::Vector2f(-COMPRIMENTO_PLATAFORMA/2, ALTURA_RESOLUCAO/2), "", sf::Vector2f(COMPRIMENTO_PLATAFORMA,ALTURA_RESOLUCAO));
	criaPlataforma(sf::Vector2f(COMPRIMENTO_CENARIO+COMPRIMENTO_PLATAFORMA / 2, ALTURA_RESOLUCAO / 2), "", sf::Vector2f(COMPRIMENTO_PLATAFORMA, ALTURA_RESOLUCAO));
}

void Quintal::recuperar()
{	
	listaEntidades.inclua(static_cast<Entidade*> (&Cenario));
	criaPlataformas();
	Cenario.setJanela(Janela);
	Cenario.setTextura("textures/Background.png");
	Cenario.setDimensoes(sf::Vector2f(COMPRIMENTO_CENARIO, ALTURA_RESOLUCAO));
	Cenario.setPosicao(sf::Vector2f(COMPRIMENTO_RESOLUCAO, ALTURA_RESOLUCAO / 2));
	porta.setJanela(Janela);
	porta.setJogo(jogo);
	listaEntidades.inclua(static_cast<Entidade*> (&porta));

	gerenciadorFisica.setListaEntidades(&listaEntidades);
	gerenciadorFisica.setListaPersonagens(&listaPersonagens);

	
	jogo->InicializaQuarto();

	recuperarProjeteis();
	recuperarEspinhos();
	recuperarEstaticos();
	recuperarPassaros();
	recuperarTeias();
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

void Quintal::recuperarPassaros()
{
	ifstream recuperadorPassaros("saves/Passaros.dat", ios::in);

	if (!recuperadorPassaros)
		cout << "Erro." << endl;

	while (!recuperadorPassaros.eof())
	{
		Passaro* novo = NULL;
		int vida;
		float posx, posy, movx, movy, limxdir, limxesq, cooldown;

		recuperadorPassaros >> vida >> posx >> posy >> movx >> movy >> limxdir >> limxesq >> cooldown;

		novo = new Passaro();
		novo->inicializa();
		novo->setVida(vida);
		novo->setPosicao(sf::Vector2f(posx, posy));
		novo->setLimiteXDir(limxdir);
		novo->setLimiteXEsq(limxesq);
		novo->setMovimentoX(movx);
		novo->setMovimentoY(movy);
		novo->setCooldownAtaque(cooldown);
		novo->setVelocidade(200.f);
		novo->setJanela(Janela);
		novo->setTextura("textures/Passaro_direita.png");
		novo->setTexturaProjetil("textures/Projetil_Passaro.png");
		novo->setColidePlataforma(true);
		novo->setDimensoes(sf::Vector2f(COMPRIMENTO_ESPINHO, ALTURA_ESPINHO));
		//novo->setOrigem();
		novo->setFaseAtual(this);

		listaEntidades.inclua(static_cast<Entidade*>(novo));
		listaPersonagens.inclua(static_cast <Personagem*> (novo));
		//gerenciadorFisica.incluaPersonagem(static_cast<Personagem*>(novo));
		//gerenciadorFisica.incluaEntidade(static_cast<Entidade*>(novo));
	}

	recuperadorPassaros.close();
	//ofstream deletar("saves/Passaros.dat", ios::out);
	//deletar.close();
}


