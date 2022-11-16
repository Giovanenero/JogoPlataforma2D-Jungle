#pragma once

//Gerenciador
#include "Gerenciador\GerenciadorGrafico.hpp"
#include "Gerenciador\GerenciadorEvento.hpp"

//Fases
#include "Fase\FlorestaBranca.hpp"
#include "Fase\FlorestaVermelha.hpp"

#include "Estado\MaquinaEstado.hpp"

namespace Jungle {

    class Principal {
        private:
            Gerenciador::GerenciadorGrafico* pGrafico;
            Gerenciador::GerenciadorEvento* pEvento;
            Estado::MaquinaEstado maquinaEstado;

            void inicializa();
        public:
            Principal();
            ~Principal();
            void executar();
    };

}