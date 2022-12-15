#pragma once

#include "Estado.hpp"

//Gerenciador
#include "..\Gerenciador\GerenciadorGrafico.hpp"

//Fases
#include "..\Fase\FlorestaBranca.hpp"
#include "..\Fase\FlorestaVermelha.hpp"

//Jogador
#include "..\Entidade\Personagem\Jogador\Jogador.hpp"

//Construtor
#include "..\Construtor\ConstrutorEstado.hpp"

namespace Jungle {

    namespace Estado {

        class EstadoJogar : public Estado {
        private:
            Fase::Fase* fase;
        public:
            EstadoJogar(const IDs::IDs ID, Fase::Fase* fase);
            ~EstadoJogar();
            void executar();
            void mudarEstadoObservador();
        };

    }

}
