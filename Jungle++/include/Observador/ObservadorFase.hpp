#pragma once

#include "Observador.hpp"
#include "../Menu/Menu.hpp"

namespace Jungle {

    namespace Fase {
        class Fase;
    }

    namespace Observador {

        class ObservadorFase: public Observador {
        private:
            Fase::Fase* fase;
        public:
            ObservadorFase();
            ~ObservadorFase();
            void setFase(Fase::Fase* fase);
            void teclaPressionada(const sf::Keyboard::Key tecla);
            void teclaSolta(const sf::Keyboard::Key tecla);
            void notificarJogadorMorreu();
        };

    }

}