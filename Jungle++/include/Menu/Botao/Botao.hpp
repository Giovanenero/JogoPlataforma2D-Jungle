#pragma once 

#include "..\..\Ente.hpp"
#include "Texto.hpp"

#define CAMINHO_FONTE "Jungle++/fonte/menu.ttf"

namespace Jungle {

    namespace Menu {

        namespace Botao {

            class Botao : public Ente {
            private:
                sf::RectangleShape caixa;
                Texto caixaTexto;
                sf::Vector2f pos;
                sf::Vector2f tam;
                bool selecionado;

                sf::Clock relogio;
                const float tempoTrocaCor;
                float tempo;
            public:
                Botao(const std::string texto, const sf::Vector2f tam,const sf::Vector2f pos, const IDs::IDs ID);
                ~Botao();
                void desenhar();
                void atualizarTexto();
                void setSelecionado(const bool selecionado = true);
                const bool getSelecionado() const;
            };

        }

    }

}