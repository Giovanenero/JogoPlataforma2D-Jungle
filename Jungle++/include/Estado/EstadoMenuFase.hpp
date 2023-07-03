#pragma once

#include "..\Menu\MenuPausa.hpp"
#include "Estado.hpp"

namespace Jungle {

    namespace Gerenciador {
        class GerenciadorEstado;
    }

    namespace Estado {

        class EstadoJogar;

        class EstadoMenuFase: public Estado {
        private:
            Menu::MenuPausa* menuFase;
            EstadoJogar* estadoJogar;
            static Gerenciador::GerenciadorEstado* pGEstado;
            
            Menu::MenuPausa* criarMenu(const IDs::IDs ID);
        public:
            EstadoMenuFase(const IDs::IDs ID_Estado, const IDs::IDs ID_Menu);
            ~EstadoMenuFase();
            void mudarEstadoObservador();
            void executar();
        };

    }

}