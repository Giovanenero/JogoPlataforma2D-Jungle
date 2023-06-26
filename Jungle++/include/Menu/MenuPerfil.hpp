#pragma once

#include "Menu.hpp"
#include "../Parallax/Fundo.hpp"

#define TAMANHO_BOTAO_MENU_PERFIL_X 100.0f
#define TAMANHO_BOTAO_MENU_PERFIL_Y 50.0f

namespace Jungle {

    namespace Menu {

        class MenuPerfil: public Menu {
            private:
                Parallax::Fundo fundo;

                void criarFundo();
                void criarBotoes();
            public:
                MenuPerfil();
                ~MenuPerfil();
                void mudarEstadoObservador();
                void executar();
        };

    }

}