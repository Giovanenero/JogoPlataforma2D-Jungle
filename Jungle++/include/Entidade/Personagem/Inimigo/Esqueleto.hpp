#pragma once

#include "Inimigo.hpp"

#define TAMANHO_ESQUELO_X 50.0f
#define TAMANHO_ESQUELO_Y 90.0f

namespace Jungle {

    namespace Entidade {

        namespace Personagem {

            namespace Inimigo {

                class Esqueleto : public Inimigo {
                private:
                    void inicializa();
                public:
                    Esqueleto(const sf::Vector2f pos, Jogador::Jogador* jogador);
                    ~Esqueleto();
                };

            }

        }

    }
    
}