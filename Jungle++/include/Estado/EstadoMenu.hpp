#pragma once

#include "Estado.hpp"
#include "../Fase/Fase.hpp"
#include "../Menu/Menu.hpp"

namespace Jungle {

    namespace Gerenciador {
        class GerenciadorEstado;
    }

    namespace Estado {

        class EstadoMenu : public Estado {
            private:
                Menu::Menu* menu;

                static Gerenciador::GerenciadorEstado* pGEstado;
                void criarMenu();
            public:
                EstadoMenu(const IDs::IDs ID);
                ~EstadoMenu();
                void mudarEstadoObservador();
                Fase::Fase* getFase();
                Menu::Menu* getMenu();
                void executar();
        };

    }

}