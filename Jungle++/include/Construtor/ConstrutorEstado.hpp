#pragma once 

#include "..\Estado\EstadoJogar.hpp"
#include "..\Fase\FlorestaBranca.hpp"
#include "..\Fase\FlorestaVermelha.hpp"

namespace Jungle {

    namespace Construtor {

        class ConstrutorEstado {
        private:
            Fase::Fase* criarFase(const IDs::IDs ID);
        public:
            ConstrutorEstado();
            ~ConstrutorEstado();
            Estado::Estado* criarEstadoJogar(const IDs::IDs ID);
        };

    }

}