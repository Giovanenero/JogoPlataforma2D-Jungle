#pragma once 

#include "Estado.hpp"
#include "../Menu/MenuPerfil.hpp"

namespace Jungle {

    namespace Estado {

        class EstadoMenuPerfil: public Estado {
            private:
                Menu::MenuPerfil menuPerfil;
            public:
                EstadoMenuPerfil();
                ~EstadoMenuPerfil();
                void executar();
                void mudarEstadoObservador();

        };

    }

}