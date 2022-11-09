#pragma once

#include "..\Personagem.hpp"

#define VELOCIDADE_JOGADOR 200.0f
#define TAMANHO_PULO 0.04f

namespace Jungle {

    namespace Entidade {

        namespace Personagem {

            namespace Jogador {

                class Jogador : public Personagem {
                private:
                    Animador::Animacao animacao;
                    void inicializa();
                    bool noChao;
                public:
                    Jogador(const sf::Vector2f pos, const sf::Vector2f tam);
                    ~Jogador();
                    void atualizar();
                    void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
                    void pular();
                    void podePular();
                    virtual void atualizarAnimacao();
                };

            }

        }

    }

}