#pragma once

#include "../Personagem.hpp"
#include "../../Item/Espada.hpp"

#define VELOCIDADE_JOGADOR 200.0f
#define TAMANHO_PULO 0.1f
#define TAMANHO_JOGADOR_X 50.0f
#define TAMANHO_JOGADOR_Y 90.0f
#define TAMANHO_ESPADA_X 80.0f
#define TEMPO_JOGADOR_MORRER 1.0f
#define TEMPO_JOGADOR_TOMARDANO 0.30f
#define BARRA_VIDA_JOGADOR_X 250.0f
#define BARRA_VIDA_JOGADOR_Y 40.0f
#define DANO 35.0f

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
                    sf::RectangleShape tuboBarraVida;

                    void inicializarAnimacao();
                    void inicializarBarraVida();
                    void atualizarAnimacao();
                    void atualizarBarraVida();
                public:
                    Jogador(const sf::Vector2f pos, Item::Espada* espada);
                    ~Jogador();
                    void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
                    const bool getNoChao() const;
                    void pular();
                    void podePular();
                    void mudarEstadoObservador();
                    void addPontuacao(const unsigned int pontos);
                    void setVida(const float vida);
                    void atualizar();
                    void desenhar();
                };

            }

        }

    }

}