#pragma once
#include "Inimigo.h"

class Estatico : public Inimigo
{
private: 

public:
    Estatico();
    ~Estatico();

    void atualiza(float deltaTempo);
    void colidir(Personagem* personagem);
    void inicializa();
    void movimenta(sf::Vector2f movimento);
    void salvar();
};

