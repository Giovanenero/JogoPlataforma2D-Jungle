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
            const int getTam();
            Entidade::Entidade* operator[](int pos);
            std::vector<Entidade::Entidade*> getEntidades(const IDs::IDs ID);
            void limparLista();
            void executar();
            void desenharEntidades();
        };

    }

}