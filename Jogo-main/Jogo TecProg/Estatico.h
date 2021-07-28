#pragma once
#include "Inimigo.h"
class Estatico :
    public Inimigo
{
public: 
    bool Neutralizavel;


protected:
    Estatico();
    ~Estatico();

    void movimenta();
};

