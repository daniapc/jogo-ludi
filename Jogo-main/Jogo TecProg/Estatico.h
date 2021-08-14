#pragma once
#include "Inimigo.h"

class Estatico : public Inimigo
{
private: 
    float CooldownInvencibilidade, CooldownInvencibilidadeMax;

public:
    Estatico();
    ~Estatico();

    bool podeMorrer();
    void atualiza(float deltaTempo);
    void colidir(Personagem* personagem);
    //void movimenta(sf::Vector2f movimento);
    void salvar();
};

