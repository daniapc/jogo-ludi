#include "Jogador.h"
#include "Fase.h"
#include "Jogo.h"

int Jogador::Pontuacao = 0;

Jogador::Jogador() :
	Personagem(),
	podePular(false),
	alturaPulo(250.f)
{
	Amigavel = true;
	Pontuacao = 0;
	Vida = 10;
	CooldownAtaqueMax = 0.5f;
	CooldownAtaque = CooldownAtaqueMax/2;
	this->setVelocidade(400.f);
	this->setColidePlataforma(true);
}

Jogador::~Jogador()
{
}

void Jogador::setPodePular(bool podepular)
{
	podePular = podepular;
}

void Jogador::setAlturaPulo(float alturapulo)
{
	alturaPulo = alturapulo;
}

void Jogador::incrementaPontuacao()
{
	Pontuacao += 10;
}

int Jogador::getPontuacao()
{
	return Pontuacao;
}



void Jogador::setTexturas(bool fazendeira)
{
	if (fazendeira) {
		Textura = "textures/Fazendeira.png";
		SubTextura[0] = "textures/Fazendeira.png";SubTextura[1] = "Fazendeira_2"; SubTextura[2] = "Fazendeira_3";
		SubTextura[3] = "Fazendeira_4";SubTextura[4] = "Fazendeira_5"; SubTextura[5] = "Fazendeira_6";
		SubTextura[6] = "Fazendeira_7";SubTextura[7] = "Fazendeira_8"; SubTextura[8] = "Fazendeira_9";
		SubTextura[9] = "Fazendeira_10";SubTextura[10] = "Fazendeira_11"; SubTextura[11] = "Fazendeira_12";
		setTexturaProjetil("Projeteis_3", "Projeteis_4");
	}
	else {
		Textura = "textures/Bruxo.png";
		SubTextura[0] = "textures/Bruxo.png";SubTextura[1] = "Bruxo_2"; SubTextura[2] = "Bruxo_3";
		SubTextura[3] = "Bruxo_4";SubTextura[4] = "Bruxo_5"; SubTextura[5] = "Bruxo_6";
		SubTextura[6] = "Bruxo_7";SubTextura[7] = "Bruxo_8"; SubTextura[8] = "Bruxo_9";
		SubTextura[9] = "Bruxo_10";SubTextura[10] = "Bruxo_11"; SubTextura[11] = "Bruxo_12";
		setTexturaProjetil("textures/Projeteis.png", "Projeteis_2");
	}
}


string Jogador::getTextura() const
{
	return Textura;
}

void Jogador::atualiza(float deltaTempo)
{
	if (Desalocavel)
	{
		Desalocavel = false;
		faseAtual->getJogo()->setEstado(7);
		pGerenciadorGrafico->tocarMusica("Creditos");
	}

	MovimentoX = 0.f;

	if (podePular)
		Velocidade = 400.f;

	char TeclaDireita, TeclaEsquerda, TeclaPulo, TeclaAtira;

	pGerenciadorGrafico->TeclaApertada(&TeclaDireita, &TeclaEsquerda, &TeclaPulo, &TeclaAtira);

	if (olharDireita)
		setSubTextura(SubTextura[0]);
	else 
		setSubTextura(SubTextura[1]);

	if (TeclaDireita == Direita || TeclaDireita == '>')
	{
		if (CooldownAnimacao <= CooldownAnimacaoMax * 1 / 3) 
			setSubTextura(SubTextura[2]);
		else if (CooldownAnimacao <= CooldownAnimacaoMax*2/3) 
			setSubTextura(SubTextura[3]);
		else 
			setSubTextura(SubTextura[4]);
		MovimentoX += Velocidade;
		olharDireita = true;
	}
	if (TeclaEsquerda == Esquerda || TeclaEsquerda == '<')
	{
		if (CooldownAnimacao <= CooldownAnimacaoMax * 1 / 3)
			setSubTextura(SubTextura[5]);
		else if (CooldownAnimacao <= CooldownAnimacaoMax * 2 / 3)
			setSubTextura(SubTextura[6]);
		else
			setSubTextura(SubTextura[7]);
		MovimentoX -= Velocidade;
		olharDireita = false;
	}

	if ((TeclaAtira == Atira || TeclaAtira == 'S') && this->podeAtacar())
	{
		
		this->atiraProjetilHorizontal(this, getPosicaoY() );
		CooldownAtaque = 0;
	}

	if (podePular && (TeclaPulo == Pulo || TeclaPulo == 'J'))
	{
		podePular = false;
		MovimentoY = -sqrt(2 * 981.f * alturaPulo);
	}
	if (!podePular) {

		if (olharDireita) 
			setSubTextura(SubTextura[10]);
		else
			setSubTextura(SubTextura[11]);
	}
	if (CooldownAtaque < CooldownAtaqueMax / 2) {
		this->setDimensoes(COMPRIMENTO_JOGADOR + ALTURA_JOGADOR/3, ALTURA_JOGADOR);
		if (olharDireita) {
			setSubTextura(SubTextura[8]);
		}
		else {
			setSubTextura(SubTextura[9]);
		}
	}
	else
		this->setDimensoes(COMPRIMENTO_JOGADOR, ALTURA_JOGADOR);


	if (CooldownAnimacao >= CooldownAnimacaoMax)
		CooldownAnimacao = 0.f;

	MovimentoY += 981.f * deltaTempo;
	CooldownAtaque += deltaTempo;
	CooldownAnimacao += deltaTempo;

	this->movimenta(MovimentoX * deltaTempo, MovimentoY * deltaTempo);
}

void Jogador::setTeclas(char direita, char esquerda, char pulo, char atira)
{
	Direita = direita;
	Esquerda = esquerda;
	Pulo = pulo;
	Atira = atira;
}

void Jogador::salvar()
{
	ofstream gravadorJogador("saves/Jogadores.dat", ios::app);

	if (!gravadorJogador)
		cout << "Erro Gravar Jogadores." << endl;

	gravadorJogador << this->getVida() << ' '
		<< this->getPosicaoX()  << ' '
		<< this->getPosicaoY()  << ' '
		<< this->getMovimentoX()  << ' '
		<< this->getMovimentoY()  << ' '
		<< this->CooldownAtaque <<  endl;

	gravadorJogador.close();
}

Jogador& Jogador::operator++()
{
	this->incrementaPontuacao();

	return *this;
}


