#pragma once

//Gerenciador
#include "Gerenciador\GerenciadorGrafico.hpp"
#include "Gerenciador\GerenciadorEvento.hpp"

//Fases
#include "Fase\FlorestaBranca.hpp"
#include "Fase\FlorestaVermelha.hpp"

#include "Gerenciador\GerenciadorEstado.hpp"

namespace Jungle {

    class Principal {
        private:
            Gerenciador::GerenciadorGrafico* pGrafico;
            Gerenciador::GerenciadorEvento* pEvento;
            Gerenciador::GerenciadorEstado* pGerenciadorEstado;

            void inicializa();
        public:
            Principal();
            ~Principal();
            void executar();
    };

}