#pragma once

#include "Estado.hpp"

//Gerenciador
#include "..\Gerenciador\GerenciadorGrafico.hpp"

//Fases
#include "..\Fase\FlorestaBranca.hpp"
#include "..\Fase\FlorestaVermelha.hpp"

namespace Jungle {

    namespace Estado {

        class EstadoJogar : public Estado {
        private:
            Fase::Fase* fase;
        public:
            EstadoJogar(Fase::Fase* fase);
            ~EstadoJogar();
            void executar();
        };

    }

}
