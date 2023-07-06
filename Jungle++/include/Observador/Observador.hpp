#pragma once

#include "SFML/Graphics.hpp"

namespace Jungle {

    namespace Gerenciador {
        class GerenciadorEvento;
        class GerenciadorEstado;
    }

    namespace Observador {

        class Observador {
            protected:
                static Gerenciador::GerenciadorEvento* pEvento;
                static Gerenciador::GerenciadorEstado* pGEstado;
                std::map<sf::Keyboard::Key, char> teclado;
                std::map<sf::Keyboard::Key, std::string> tecladoEspecial;

            private:
                bool ativar;
                void inicializarTeclado();
            public:
                Observador();
                virtual ~Observador();
                void mudarEstadoAtivar();
                const bool getAtivar() const;
                void removerObservador();
                virtual void teclaPressionada(const sf::Keyboard::Key tecla) = 0;
                virtual void teclaSolta(const sf::Keyboard::Key tecla) = 0;
                virtual void moveMouse(const sf::Vector2f posMouse);
                virtual void botaoMouseSolta(const sf::Mouse::Button botaoMouse);
        };

    }

}