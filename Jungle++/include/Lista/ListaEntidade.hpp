#pragma once

#include "Lista.hpp"
#include "../Entidade/Entidade.hpp"

namespace Jungle {

    namespace Lista {

        class ListaEntidade {
        private:
            Lista<Entidade::Entidade> objListaEntidade;
        public:
            ListaEntidade();
            ~ListaEntidade();
            void addEntidade(Entidade::Entidade* entidade);
            void addEntidade(Entidade::Entidade* entidade, int pos);
            void removerEntidade(Entidade::Entidade* entidade, const bool deletar = true);
            void removerEntidade(int pos, const bool deletar = true);
            int getTam();
            Entidade::Entidade* operator[](int pos);
            void limparLista();
            void executar();
            void desenharEntidades();
        };

    }

}