#pragma once

#include "Lista.hpp"
#include "..\Entidade\Entidade.hpp"

namespace Jungle {

    namespace Lista {

        class ListaEntidade {
        private:
            Lista<Entidade::Entidade> objListaEntidade;
        public:
            ListaEntidade();
            ~ListaEntidade();
            void addEntidade(Entidade::Entidade* entidade);
            void removerEntidade(Entidade::Entidade* entidade);
            void removerEntidade(int pos);
            int getTam();
            Entidade::Entidade* operator[](int pos);
            void executar(sf::RenderWindow* window);
        };

    }

}