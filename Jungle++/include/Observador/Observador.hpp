#pragma once

#include "SFML\Graphics.hpp"

namespace Jungle {

    namespace Gerenciador {
        class GerenciadorEvento;
    }

    namespace Observador {

        class Observador {
        protected:
            static Gerenciador::GerenciadorEvento* pEvento;
        private:
            bool ativar;
        public:
            Observador();
            ~Observador();
            void mudarEstadoAtivar();
            const bool getAtivar() const;
            void removerObservador();
            virtual void teclaPressionada(const sf::Keyboard::Key tecla) = 0;
            virtual void teclaSolta(const sf::Keyboard::Key tecla) = 0;
        };

    }

}