#pragma once

#include "SFML\Graphics.hpp"

namespace Jungle {

    namespace Gerenciador {
        class GerenciadorEvento;
    }

    namespace Observador {

        class Observador {
        private:
            static Gerenciador::GerenciadorEvento* pEvento;
        public:
            Observador();
            ~Observador();
            virtual void teclaPressionada(const sf::Keyboard::Key tecla) = 0;
            virtual void teclaSolta(const sf::Keyboard::Key tecla) = 0;
        };

    }

}