#pragma once

#include "..\Menu\MenuPrincipal.hpp"
#include "Estado.hpp"

namespace Jungle {

    namespace Estado {

        class EstadoMenuPrincipal: public Estado {
        private:
            Menu::MenuPrincipal menuPrincipal;
        public:
            EstadoMenuPrincipal(const IDs::IDs ID = IDs::IDs::estado_menu_principal);
            ~EstadoMenuPrincipal();
            void mudarEstadoObservador();
            void executar();
        };

    }

}