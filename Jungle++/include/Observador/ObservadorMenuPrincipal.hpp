#pragma once

#include "Observador.hpp"
#include "..\Menu\Botao\Botao.hpp"

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
            void moveMouse(const sf::Vector2f posMouse);
            void botaoMouseSolta(const sf::Mouse::Button botaoMouse);
        };

    }

}