#pragma once 

#include "..\Estado\EstadoJogar.hpp"
#include "..\Fase\FlorestaBranca.hpp"
#include "..\Fase\FlorestaVermelha.hpp"

namespace Jungle {

    namespace Construtor {

        class ConstrutorEstado {
        public:
            ConstrutorEstado();
            ~ConstrutorEstado();
            Estado::Estado* addEstadoJogar(const IDs::IDs ID);
        };

    }

}