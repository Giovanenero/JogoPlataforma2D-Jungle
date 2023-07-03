#pragma once

#include "Observador.hpp"
#include "../Menu/Menu.hpp"
#include "../Menu/Botao/Botao.hpp"
#include "../Menu/MenuGameOver.hpp"

namespace Jungle {

    namespace Observador {

        class ObservadorMenu: public Observador {
        private:
            Menu::Menu* menu;
        public:
            ObservadorMenu(Menu::Menu* menu);
            ~ObservadorMenu();
            void teclaPressionada(const sf::Keyboard::Key tecla);
            void teclaSolta(const sf::Keyboard::Key tecla);
            void moveMouse(const sf::Vector2f posMouse);
            void botaoMouseSolta(const sf::Mouse::Button botaoMouse);
        };

    }

}