#pragma once 

#include "Estado.hpp"
#include "../Menu/MenuCarregarJogo.hpp"

namespace Jungle {

    namespace Estado {

        class EstadoMenuCarregarJogo: public Estado {
            private:
                Menu::MenuCarregarJogo menuCarregarJogo;
            public:
                EstadoMenuCarregarJogo();
                ~EstadoMenuCarregarJogo();
                void executar();
                void mudarEstadoObservador();

        };

    }

}