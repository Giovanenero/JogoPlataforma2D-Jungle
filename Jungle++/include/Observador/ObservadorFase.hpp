#pragma once

#include "Observador.hpp"
#include "..\Fase\Fase.hpp"
#include "../Menu/Menu.hpp"

namespace Jungle {

    namespace Observador {

        class ObservadorFase: public Observador {
        private:
            Fase::Fase* fase;
        public:
            ObservadorFase(Fase::Fase* fase);
            ~ObservadorFase();
            void teclaPressionada(const sf::Keyboard::Key tecla);
            void teclaSolta(const sf::Keyboard::Key tecla);
        };

    }

}