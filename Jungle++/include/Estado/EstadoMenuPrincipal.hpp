#pragma once

#include "../Menu/MenuPrincipal.hpp"
#include "../Menu/MenuColocacao.hpp"
#include "../Menu/MenuOpcaoPrincipal.hpp"
#include "../Menu/MenuCarregarJogo.hpp"
#include "Estado.hpp"

namespace Jungle {

    namespace Estado {

        class EstadoMenuPrincipal: public Estado {
        private:
            Menu::MenuPrincipal* menuPrincipal;

            Menu::MenuPrincipal* criarMenu(const IDs::IDs ID);
        public:
            EstadoMenuPrincipal();
            EstadoMenuPrincipal(const IDs::IDs ID_Estado, const IDs::IDs ID_Menu);
            ~EstadoMenuPrincipal();
            void mudarEstadoObservador();
            void executar();
        };

    }

}