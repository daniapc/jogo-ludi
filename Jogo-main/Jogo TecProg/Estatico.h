#pragma once
#include "Inimigo.h"

class Estatico : public Inimigo
{
private: 
    float CooldownInvencibilidade, CooldownInvencibilidadeMax;
    string SubTextura[3];

public:
    Estatico();
    ~Estatico();

    bool podeMorrer();
    void atualiza(float deltaTempo);
    void colidir(Personagem* personagem);
    void setTexturas(bool Quintal);

    void salvar();
};

