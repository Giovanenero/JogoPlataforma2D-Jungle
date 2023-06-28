#pragma once

#include "Estado.hpp"
#include "..\Menu\MenuColocacao.hpp"

namespace Jungle {

    namespace Estado {

        class EstadoMenuColocacao : public Estado {
            private:
                Menu::MenuColocacao menuColocacao;
            public:
                EstadoMenuColocacao();
                ~EstadoMenuColocacao();
                void mudarEstadoObservador();
                void executar();
        };

    }

}