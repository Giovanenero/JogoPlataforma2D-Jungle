#pragma once

#include "Lista.hpp"
#include "../Observador/Observador.hpp"
#include "SFML/Graphics.hpp"

namespace Jungle {

    namespace Lista {

        class ListaObservador {
        private:
            Lista<Observador::Observador> objListaObservador;
        public:
            ListaObservador();
            ~ListaObservador();
            void addObservador(Observador::Observador* observador);
            void removerObservador(Observador::Observador* observador);
            void removerObservador(int pos);
            int getTam();
            Observador::Observador* operator[](int pos);
            void notificarTeclaPressionada(const sf::Keyboard::Key tecla);
            void notificarTeclaSolta(const sf::Keyboard::Key tecla);
            void notificarMovimentoMouse(const sf::Event::MouseMoveEvent mouse);
            void notificarBotaoMouseSolta(const sf::Mouse::Button botaoMouse);
        };

    }

}