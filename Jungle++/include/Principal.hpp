#pragma once

//Gerenciador
#include "Gerenciador\GerenciadorGrafico.hpp"
#include "Gerenciador\GerenciadorEvento.hpp"

#include "Fase\FaseFloresta.hpp"

namespace Jungle {

    class Principal {
        private:
            Gerenciador::GerenciadorGrafico* pGrafico;
            Gerenciador::GerenciadorEvento* pEvento;
            Fase::FaseFloresta faseFloresta;
        public:
            Principal();
            ~Principal();
            void executar();
    };

}