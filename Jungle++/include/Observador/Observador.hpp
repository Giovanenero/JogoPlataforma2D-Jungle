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
            void ativarObservador();
            void desativarObservador();
            const bool getAtivar() const;
            void removerObservador();
            virtual void teclaPressionada(const sf::Keyboard::Key tecla) = 0;
            virtual void teclaSolta(const sf::Keyboard::Key tecla) = 0;
        };

    }

}