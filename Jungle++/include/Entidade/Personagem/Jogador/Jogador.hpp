#pragma once

#include "..\Personagem.hpp"
#include "../../Item/Espada.hpp"

#define VELOCIDADE_JOGADOR 200.0f
#define TAMANHO_PULO 0.1f
#define TAMANHO_JOGADOR_X 50.0f
#define TAMANHO_JOGADOR_Y 90.0f
#define TAMANHO_ESPADA_X 80.0f
#define TEMPO_JOGADOR_MORRER 2.0f
#define DANO 50.0f

namespace Jungle {

    namespace Observador {
        class ObservadorJogador;
    }

    namespace Entidade {

        namespace Personagem {

            namespace Jogador {

                class Jogador : public Personagem {
                private:
                    bool noChao;
                    Observador::ObservadorJogador* observadorJogador;
                    Item::Espada* espada;
                    unsigned int pontuacao;

                    void inicializaAnimacao();
                    void atualizarAnimacao();
                public:
                    Jogador(const sf::Vector2f pos, Item::Espada* espada);
                    ~Jogador();
                    void atualizar();
                    void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
                    void pular();
                    void podePular();
                    void mudarEstadoObservador();
                    void addPontuacao(unsigned int pontos);
                    unsigned int getPontos() const;
                };

            }

        }

    }

}