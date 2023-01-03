#pragma once

#include "Estado.hpp"
#include "..\Menu\MenuOpcaoPrincipal.hpp"

namespace Jungle {

    namespace Estado {

        class EstadoMenuOpcaoPrincipal: public Estado {
        private:
            Menu::MenuOpcaoPrincipal menuOpcaoPrincipal;
        public:
            EstadoMenuOpcaoPrincipal();
            ~EstadoMenuOpcaoPrincipal();
            void mudarEstadoObservador();
            void executar();
        };

    }

}