#pragma once

#include "..\Menu\MenuPrincipal.hpp"
#include "Estado.hpp"

namespace Jungle {

    namespace Estado {

        class EstadoMenuPrincipal: public Estado {
        private:
            Menu::MenuPrincipal menuPrincipal;
        public:
            EstadoMenuPrincipal();
            ~EstadoMenuPrincipal();
            void mudarEstadoObservador();
            void executar();
        };

    }

}