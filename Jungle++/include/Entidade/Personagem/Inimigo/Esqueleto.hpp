#pragma once

#include "Inimigo.hpp"

#define TAMANHO_ESQUELO_X 50.0f
#define TAMANHO_ESQUELO_Y 90.0f
#define TEMPO_ESQUELETO_MORRER 2.0f
#define PONTOS_ESQUELETO 200

namespace Jungle {

    namespace Entidade {

        namespace Personagem {

            namespace Inimigo {

                class Esqueleto : public Inimigo {
                private:
                    void inicializaAnimacao();
                public:
                    Esqueleto(const sf::Vector2f pos, Jogador::Jogador* jogador);
                    ~Esqueleto();
                };

            }

        }

    }
    
}