#pragma once

#include "Menu.hpp"

#define CAMINHO_TEXTURA_MENU_PRINCIPAL "Jungle++/img/Menu/menuPrincipal.png"

namespace Jungle {

    namespace Menu {

        class MenuPrincipal: public Menu {
        private:
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