#pragma once

#include "GerenciadorGrafico.hpp"
#include "..\Entidade\Personagem\Jogador\Jogador.hpp"

namespace Jungle {

    namespace Gerenciador {

        class GerenciadorEstado;

        class GerenciadorEvento {
        private:
            GerenciadorGrafico* pGrafico;
            GerenciadorEstado* pGEstado;

            //padrão de projeto singleton
            static GerenciadorEvento* pEvento;
            GerenciadorEvento();
        public:
            ~GerenciadorEvento();
            static GerenciadorEvento* getGerenciadorEvento();
            void verificaTeclaPressionada(sf::Keyboard::Key tecla);
            void verificaTeclaSolta(sf::Keyboard::Key tecla);
            void executar();
        };

    }

}