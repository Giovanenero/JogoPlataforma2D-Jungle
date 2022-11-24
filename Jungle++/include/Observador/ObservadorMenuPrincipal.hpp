#pragma once

#include "Observador.hpp"
#include "..\Menu\Botao\Botao.hpp"

namespace Jungle {

    namespace Menu {
        class MenuPrincipal;
    }

    namespace Gerenciador {
        class GerenciadorEstado;
    }

    namespace Observador {

        class ObservadorMenuPrincipal: public Observador {
        private:
            Menu::MenuPrincipal* menuPrincipal;
            static Gerenciador::GerenciadorEstado* pGEstado;
        public:
            ObservadorMenuPrincipal(Menu::MenuPrincipal* menuPrincipal);
            ~ObservadorMenuPrincipal();
            void teclaPressionada(const sf::Keyboard::Key tecla);
            void teclaSolta(const sf::Keyboard::Key tecla);
        };

    }

}