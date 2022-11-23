#pragma once

#include "Menu.hpp"

#define CAMINHO_TEXTURA_MENU_PRINCIPAL "Jungle++/img/Menu/menuPrincipal.png"
#define TAMANHO_BOTAO_X 350.0f
#define TAMANHO_BOTAO_Y 50.0f

namespace Jungle {

    namespace Menu {

        class MenuPrincipal: public Menu {
        protected:
            bool sair;

            void criarFundo();
            void criarBotoes();
        public:
            MenuPrincipal();
            ~MenuPrincipal();
            void setSair(const bool sair = true);
            const bool getSair() const;
            void executar();
        };

    } 

}