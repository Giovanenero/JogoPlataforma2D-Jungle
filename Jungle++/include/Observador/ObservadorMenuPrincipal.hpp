#pragma once

#include "Observador.hpp"

namespace Jungle {

    namespace Menu {
        class MenuPrincipal;
    }

    namespace Observador {

        class ObservadorMenuPrincipal: public Observador {
        private:
            Menu::MenuPrincipal* menuPrincipal;
        public:
            ObservadorMenuPrincipal(Menu::MenuPrincipal* menuPrincipal);
            ~ObservadorMenuPrincipal();
            void teclaPressionada(const sf::Keyboard::Key tecla);
            void teclaSolta(const sf::Keyboard::Key tecla);
        };

    }

}