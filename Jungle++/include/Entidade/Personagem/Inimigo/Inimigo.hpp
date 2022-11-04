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
                    void inicializa();
                public:
                    Inimigo(const sf::Vector2f pos, const sf::Vector2f tam, Jogador::Jogador* jogador);
                    ~Inimigo();
                    void atualizar();
                    void atualizaMovimentoAleatorio();
                    void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
                };

            }

        }

    }

}