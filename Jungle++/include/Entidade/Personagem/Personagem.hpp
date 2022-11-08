#pragma once

#include "..\Entidade.hpp"
#include "..\..\Animador\Animacao.hpp"

#define GRAVIDADE 0.7f

namespace Jungle {

    namespace Entidade {

        namespace Personagem {

            class Personagem : public Entidade {
            protected:
                sf::Vector2f velFinal;
                const float velMax;
                bool podeAndar;
                bool paraEsquerda;
                bool podeAtacar;
                sf::Clock relogio;
                float dt;
            public:
                Personagem(const sf::Vector2f pos, const sf::Vector2f tam, const float vel, const IDs::IDs ID);
                ~Personagem();
                void setVelFinal(sf::Vector2f velFinal);
                const sf::Vector2f getVelFinal();
                void andar(const bool paraEsquerda);
                void parar();
                void atacar(const bool podeAtacar);
                void atualizarPosicao();
                virtual void atualizar() = 0;
                virtual void atualizarAnimacao();
                virtual void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f)) = 0;
            };

        }

    }

}