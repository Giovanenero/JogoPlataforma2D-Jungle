#pragma once

#include "..\Personagem.hpp"
#include "..\Jogador\Jogador.hpp"

// usado p/ gerar números aleatórios
#include <time.h>

// utuliza a função fabs
#include <cmath>

#define RAIO_PERSEGUIR_X 200.0f
#define RAIO_PERSEGUIR_Y 200.0f

#define VELOCIDADE_INIMIGO 60.0f

namespace Jungle {

    namespace Entidade {

        namespace Personagem {

            namespace Inimigo {

                class Inimigo : public Personagem {
                private:
                    Jogador::Jogador* jogador;
                    short moveAleatorio;
                    float dtAux;
                    const unsigned int pontos;

                    void moveInimigo();
                    void atualizaMovimentoAleatorio();
                    virtual void inicializaAnimacao() = 0;
                    //virtual void atualizarAnimacao(){ }
                public:
                    Inimigo(const sf::Vector2f pos, const sf::Vector2f tam, Jogador::Jogador* jogador, const IDs::IDs ID, const float tempoMorrer, const unsigned int pontos);
                    ~Inimigo();
                    virtual void atualizar();
                    void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
                    unsigned int getPontos() const;
                };

            }

        }

    }

}