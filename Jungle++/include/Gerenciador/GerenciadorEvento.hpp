#pragma once

#include "GerenciadorGrafico.hpp"
#include "../Entidade/Personagem/Jogador/Jogador.hpp"
#include "../Lista/ListaObservador.hpp"

namespace Jungle {

    namespace Gerenciador {

        class GerenciadorEstado;

        class GerenciadorEvento {
        private:
            static GerenciadorGrafico* pGrafico;
            static GerenciadorEstado* pGEstado;
            static Lista::ListaObservador* listaObservador;

            //padrão de projeto singleton
            static GerenciadorEvento* pEvento;
            GerenciadorEvento();
        public:
            ~GerenciadorEvento();
            static GerenciadorEvento* getGerenciadorEvento();
            void addObservador(Observador::Observador* observador);
            void removerObservador(Observador::Observador* observador);
            void removerObservador(int pos);
            void executar();
        };

    }

}