#pragma once

//Gerenciador
#include "Gerenciador\GerenciadorGrafico.hpp"
#include "Gerenciador\GerenciadorEvento.hpp"

//Fases
#include "Fase\FlorestaBranca.hpp"
#include "Fase\FlorestaVermelha.hpp"

namespace Jungle {

    class Principal {
        private:
            Gerenciador::GerenciadorGrafico* pGrafico;
            Gerenciador::GerenciadorEvento* pEvento;
            Fase::Fase* fase;
        public:
            Principal();
            ~Principal();
            void criarFase();
            void executar();
    };

}