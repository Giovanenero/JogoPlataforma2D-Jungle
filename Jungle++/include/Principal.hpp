#pragma once

//Gerenciador
#include "Gerenciador/GerenciadorGrafico.hpp"
#include "Gerenciador/GerenciadorEvento.hpp"

//Fases
#include "Fase/FlorestaBranca.hpp"
#include "Fase/FlorestaVermelha.hpp"

#include "Gerenciador/GerenciadorEstado.hpp"

#include <SFML/Audio.hpp>

namespace Jungle {

    class Principal {
        private:
            static Gerenciador::GerenciadorGrafico* pGrafico;
            static Gerenciador::GerenciadorEvento* pEvento;
            static Gerenciador::GerenciadorEstado* pGerenciadorEstado;

            void inicializa();
        public:
            Principal();
            ~Principal();
            void executar();
    };

}