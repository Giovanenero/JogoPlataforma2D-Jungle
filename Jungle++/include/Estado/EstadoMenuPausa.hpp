#pragma once

#include "..\Menu\MenuPausa.hpp"
#include "Estado.hpp"

namespace Jungle {

    namespace Gerenciador {
        class GerenciadorEstado;
    }

    namespace Estado {

        class EstadoJogar;

        class EstadoMenuPausa: public Estado {
        private:
            Menu::MenuPausa menuPausa;
            EstadoJogar* estadoJogar;
            static Gerenciador::GerenciadorEstado* pGEstado;
            
        public:
            EstadoMenuPausa();
            ~EstadoMenuPausa();
            void mudarEstadoObservador();
            void executar();
        };

    }

}