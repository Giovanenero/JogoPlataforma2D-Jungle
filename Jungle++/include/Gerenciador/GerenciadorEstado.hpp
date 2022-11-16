#pragma once

#include "..\Construtor\ConstrutorEstado.hpp"
#include <stack>

namespace Jungle {

    namespace Gerenciador {

        class GerenciadorEstado {
        private:
            std::stack<Estado::Estado*> pilhaEstados;
            Construtor::ConstrutorEstado construtor;

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