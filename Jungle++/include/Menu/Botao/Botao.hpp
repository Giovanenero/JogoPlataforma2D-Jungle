#pragma once 

#include "..\..\Ente.hpp"

#define TEMPO_TROCAR_COR 0.01f

namespace Jungle {

    namespace Menu {

        namespace Botao {

            class Botao : public Ente {
                protected:
                    sf::RectangleShape caixa;
                    sf::Vector2f pos;
                    sf::Vector2f tam;

                    sf::Clock relogio;
                    const float tempoTrocaCor;
                    float tempo;
                public:
                    Botao(const sf::Vector2f tam, const sf::Vector2f pos, const IDs::IDs ID);
                    virtual ~Botao();
                    virtual void desenhar() = 0;
                    void atualizarPosicaoCaixa(const sf::Vector2f pos);
                    const sf::Vector2f getPos() const;
            };

        }

    }

}