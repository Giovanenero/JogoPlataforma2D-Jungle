#pragma once

//Construtor
#include "..\Construtor\ConstrutorEstado.hpp"

//Gerenciadores
#include "GerenciadorGrafico.hpp"

//Pilha
#include <stack>

namespace Jungle {

    namespace Gerenciador {

        class GerenciadorEstado {
        private:
            std::stack<Estado::Estado*> pilhaEstados;
            Construtor::ConstrutorEstado construtorEstado;

            //padrão de projeto singleton
            static GerenciadorEstado* pGerenciadorEstado;
            GerenciadorEstado();

            void desativarObservadores();
            void ativarObservadores();
        public:
            ~GerenciadorEstado();
            static GerenciadorEstado* getGerenciadorEstado();
            void executar();
            void addEstado(const IDs::IDs ID);
            void removerEstado();
            Estado::Estado* getEstadoAtual();
        };

    }

}