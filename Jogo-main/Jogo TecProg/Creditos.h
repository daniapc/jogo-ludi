#pragma once
#include "Menu.h"

class Jogo;

namespace Menus
{
    class Creditos : public Menu
    {
    private:
        string MensagemFinal;
        int Limite;

    public:
        Creditos(Jogo* jg);
        ~Creditos();

        void setMensagemFinal(string mensagemfinal);

        void LoopMenu(char tecla);

    };
}

