#pragma once 

#include "Observador.hpp"
#include "..\Menu\MenuOpcao.hpp"

namespace Jungle {

    namespace Observador {

        class ObservadorMenuOpcao: public Observador {
        private:
            Menu::MenuOpcao* menuOpcao;
        public:
            ObservadorMenuOpcao(Menu::MenuOpcao* menuOpcao);
            ~ObservadorMenuOpcao();
            void teclaPressionada(const sf::Keyboard::Key tecla);
            void teclaSolta(const sf::Keyboard::Key tecla);
            void moveMouse(const sf::Vector2f posMouse);
            void botaoMouseSolta(const sf::Mouse::Button botaoMouse);
        };

    }

}