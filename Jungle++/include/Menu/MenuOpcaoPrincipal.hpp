#pragma once 

#include "MenuOpcao.hpp"


namespace Jungle {

    namespace Observador {
        class ObservadorMenuOpcao;
    }

    namespace Menu {

        class MenuOpcaoPrincipal: public MenuOpcao {
        private:
            Parallax::Fundo fundo;
            Observador::ObservadorMenuOpcao* observadorMenuOpcao;

            void criarFundo();
            void criarBotoes();
        public:
            MenuOpcaoPrincipal();
            ~MenuOpcaoPrincipal();
            void executar();
        };

    }

}