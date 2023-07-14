#pragma once

#include "MenuPausa.hpp"
#include "../Gerenciador/GerenciadorArquivo.hpp"

namespace Jungle {

    namespace Menu {

        class MenuSalvarJogada : public MenuPausa {
            private:
                class Card {
                    private:
                        sf::Texture* textura;
                        sf::RectangleShape* corpo;
                        const std::string caminhoArquivo;
                        const std::string caminhoImage;
                        bool selecionado;
                    public:
                        Card(const sf::Vector2f pos, const std::string caminhoArquivo, const std::string caminhoImage);
                        ~Card();
                        void setCorpo(sf::RectangleShape* corpo);
                        const std::string getCaminhoArquivo() const;
                        const std::string getCaminhoImage() const;
                        void setSelecionado(const bool selecionado);
                        const bool getSelecionado() const;
                        void desenhar();
                };
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