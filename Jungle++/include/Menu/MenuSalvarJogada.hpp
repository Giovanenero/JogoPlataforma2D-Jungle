#pragma once

#include "MenuPausa.hpp"
#include "../Gerenciador/GerenciadorArquivo.hpp"

namespace Jungle {

    namespace Menu {

        class MenuSalvarJogada : public MenuPausa {
            private:
                Gerenciador::GerenciadorArquivo gerenciadorArquivo;
                std::list<sf::RectangleShape*> listaCards;
                std::list<sf::RectangleShape*>::iterator itCards;

                void inicializarCards();
            public:
                MenuSalvarJogada(Fase::Fase* fase = nullptr);
                ~MenuSalvarJogada();
                void criarBotoes();
                void salvarJogada();
                void selecionaEsquerda();
                void selecionaDireita();
                void executar();
        };

    }

}