#pragma once

#include "GerenciadorGrafico.hpp"
#include "..\Entidade\Personagem\Jogador\Jogador.hpp"

namespace Jungle {

    namespace Gerenciador {

        class GerenciadorEvento {
        private:
            GerenciadorGrafico* pGrafico;
            Entidade::Personagem::Jogador::Jogador* pJogador;

            //padrão de projeto singleton
            static GerenciadorEvento* pEvento;
            GerenciadorEvento();
        public:
            ~GerenciadorEvento();
            static GerenciadorEvento* getGerenciadorEvento();
            void setJogador(Entidade::Personagem::Jogador::Jogador* pJogador);
            Entidade::Personagem::Jogador::Jogador* getJogador();
            void verificaTeclaPressionada(sf::Keyboard::Key tecla);
            void verificaTeclaSolta(sf::Keyboard::Key tecla);
            void executar();
        };

    }

}