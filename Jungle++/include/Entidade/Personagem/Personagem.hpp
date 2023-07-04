#pragma once

#include "..\Entidade.hpp"
#include "..\..\Animador\Animacao.hpp"
#include "../Item/Espada.hpp"

#define GRAVIDADE 1.0f

#define BARRA_VIDA_X 60.0f
#define BARRA_VIDA_Y 6.0f

namespace Jungle {

    namespace Entidade {

        namespace Personagem {

            class Personagem : public Entidade {
            protected:
                sf::Vector2f velFinal;
                Animador::Animacao animacao;
                sf::RectangleShape barraVida;
                Item::Espada* espada;
                const float velMax;
                bool andando;
                bool paraEsquerda;
                bool atacando;
                bool levandoDano;
                bool morrendo;
                const float vidaMaxima;
                float vida;
                const float tempoAnimacaoTomarDano;
                float tempoDano;
                const float tempoAnimacaoMorrer;
                float tempoMorrer;
                float dt;
                unsigned int pontos;

                virtual void atualizarAnimacao();
                virtual void atualizarBarraVida();
                virtual void inicializarBarraVida() = 0;
                virtual void inicializarAnimacao() = 0;
            public:
                Personagem(const sf::Vector2f pos, const sf::Vector2f tam, const float vel, const IDs::IDs ID, const float tempoMorrer, const float tempoDano = 1.0f);
                virtual ~Personagem();
                void setVelFinal(sf::Vector2f velFinal);
                const sf::Vector2f getVelFinal() const;
                void andar(const bool paraEsquerda);
                void parar();
                void atacar(const bool atacando);
                void atualizarPosicao();
                void atualizarTomarDano();
                void tomarDano(const float dano);
                const bool getMorrer() const;
                virtual void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f)) = 0;
                const unsigned int getPontos() const;
                void guardarEspada();
                void setEspada(Item::Espada* espada);
                virtual void desenhar();
                virtual void atualizar() = 0;
            };

        }

    }

}