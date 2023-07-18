#pragma once

#include "MenuPrincipal.hpp"
#include "../Gerenciador/GerenciadorArquivo.hpp"

namespace Jungle {

    namespace Menu {

        class MenuCarregarJogo : public MenuPrincipal{
            private:
                Gerenciador::GerenciadorArquivo gerenciadorArquivo;
                std::list<Card*> listaCards;
                std::list<Card*>::iterator itCards;

                void inicializarCards();
            public:
                MenuCarregarJogo();
                ~MenuCarregarJogo();
                void selecionaEsquerda();
                void selecionaDireita();
                const std::string getCaminhoArquivoSelecionado() const;
                virtual void criarBotoes();
                void executar();
        };

    }

}