#pragma once

#include "..\Entidade.hpp"
#include "..\..\Animador\Animacao.hpp"

#define GRAVIDADE 1.0f

namespace Jungle {

    namespace Entidade {

        namespace Personagem {

            class Personagem : public Entidade {
            protected:
                sf::Vector2f velFinal;
                Animador::Animacao animacao;
                const float velMax;
                bool podeAndar;
                bool paraEsquerda;
                bool atacando;
                sf::Clock relogio;
                float dt;

                virtual void atualizarAnimacao();
            public:
                Personagem(const sf::Vector2f pos, const sf::Vector2f tam, const float vel, const IDs::IDs ID);
                virtual ~Personagem();
                void setVelFinal(sf::Vector2f velFinal);
                const sf::Vector2f getVelFinal() const;
                void andar(const bool paraEsquerda);
                void parar();
                void atacar(const bool atacando);
                void atualizarPosicao();
                virtual void atualizar() = 0;
                virtual void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f)) = 0;
            };

        }

    }

}