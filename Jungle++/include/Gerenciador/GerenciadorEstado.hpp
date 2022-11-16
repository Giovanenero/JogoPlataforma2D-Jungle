#pragma once

#include "..\Estado\EstadoJogar.hpp"
#include <stack>

namespace Jungle {

    namespace Gerenciador {

        class GerenciadorEstado {
        private:
            std::stack<Estado::Estado*> pilhaEstados;

            void addEstadoJogar(const IDs::IDs ID);

            //padrão de projeto singleton
            static GerenciadorEstado* pGerenciadorEstado;
            GerenciadorEstado();
        public:
            ~GerenciadorEstado();
            static GerenciadorEstado* getGerenciadorEstado();
            void executar();
            void addEstado(const IDs::IDs ID);
            void removerEstado();
        };

    }

}