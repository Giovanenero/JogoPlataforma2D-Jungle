#pragma once

#include "MenuPausa.hpp"
#include "../Gerenciador/GerenciadorArquivo.hpp"
#include <map>

namespace Jungle {

    namespace Menu {

        class MenuSalvarJogada : public MenuPausa {
            private:
                Gerenciador::GerenciadorArquivo gerenciadorArquivo;
                std::list<Card*> listaCards;
                std::list<Card*>::iterator itCards;

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