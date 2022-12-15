#pragma once

#include "..\Personagem.hpp"

#define VELOCIDADE_JOGADOR 200.0f
#define TAMANHO_PULO 0.1f
#define TAMANHO_JOGADOR_X 50.0f
#define TAMANHO_JOGADOR_Y 90.0f

namespace Jungle {

    namespace Observador {
        class ObservadorJogador;
    }

    namespace Entidade {

        namespace Personagem {

            namespace Jogador {

                class Jogador : public Personagem {
                private:
                    void inicializa();
                    bool noChao;
                    Observador::ObservadorJogador* observadorJogador;
                public:
                    Jogador(const sf::Vector2f pos);
                    ~Jogador();
                    void atualizar();
                    void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
                    void pular();
                    void podePular();
                    void atualizarAnimacao();
                    void mudarEstadoObservador();
                };

            }

        }

    }

}