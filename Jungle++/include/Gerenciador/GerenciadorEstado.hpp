#pragma once

//Gerenciadores
#include "GerenciadorGrafico.hpp"
#include "GerenciadorMusica.hpp"

#include "../Estado/EstadoJogar.hpp"
#include "../Estado/EstadoMenu.hpp"
//#include "../Estado/EstadoMenuPrincipal.hpp"
//#include "../Estado/EstadoMenuFase.hpp"

//Pilha
#include <stack>

namespace Jungle {

    namespace Gerenciador {

        class GerenciadorEstado {
        private:
            std::stack<Estado::Estado*> pilhaEstados;
            static GerenciadorMusica* pMusica;

            //padrão de projeto singleton
            static GerenciadorEstado* pGerenciadorEstado;
            GerenciadorEstado();

            void desativarObservadores();
            void ativarObservadores();
        public:
            ~GerenciadorEstado();
            static GerenciadorEstado* getGerenciadorEstado();
            void executar();
            Estado::Estado* getEstado(const int qtdRemove);
            void addEstado(const IDs::IDs ID);
            void removerEstado(const int qtd);
            void removerEstado();
            Estado::Estado* getEstadoAtual();
        };

    }

}