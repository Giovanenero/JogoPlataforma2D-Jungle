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
            //Fase::Fase* fase;

            //void criarFase();

            Estado::MaquinaEstado maquinaEstado;
        public:
            Principal();
            ~Principal();
            void executar();
    };

}