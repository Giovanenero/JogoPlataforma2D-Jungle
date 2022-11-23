#pragma once

#include "Lista.hpp"
#include "..\Observador\Observador.hpp"

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
            void executar();
        };

    }

}