#pragma once
#include "Inimigo.h"
class Estatico : public Inimigo
{
public: 
    bool Neutralizavel;

protected:
    Estatico();
    ~Estatico();

    void inicializa();

    void movimenta(sf::Vector2f movimento);
};

