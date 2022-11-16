#pragma once

#include "EstadoJogar.hpp"
#include <stack>

namespace Jungle {

    namespace Estado {

        class MaquinaEstado {
        private:
            std::stack<Estado*> pilhaEstados;

            void addEstadoJogar(const IDs::IDs ID);
        public:
            MaquinaEstado();
            ~MaquinaEstado();
            void executar();
            void addEstado(const IDs::IDs ID);
            void removerEstado();
        };

    }

}