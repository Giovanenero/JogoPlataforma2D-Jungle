#pragma once 

#include "MenuPausa.hpp"
#include "../Fase/Fase.hpp"

#define TAMANHO_BOTAO_MENU_GAME_OVER_X 350.0f
#define TAMANHO_BOTAO_MENU_GAME_OVER_Y 80.0f
#define CAMINHO_FONTE_MENU_GAME_OVER "Jungle++/fonte/menu.ttf"

namespace Jungle {

    namespace Menu {

        class MenuGameOver : public MenuPausa {
            private:
                sf::RectangleShape fundoCaracter;
                Botao::Texto texto;

                void atualizarFundo();
            public:
                MenuGameOver(Fase::Fase* fase = nullptr);
                ~MenuGameOver();
                void criarBotoes();
                void addCaracter(char caracter);
                void removerCaracter();
                void executar();
        };

    }

}