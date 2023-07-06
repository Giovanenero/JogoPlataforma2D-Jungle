#pragma once 

#include "../../Jogador/Jogador.hpp"
#include "Chefao.hpp"

#define TAMANHO_MINOTAURO_X 60.0f
#define TAMANHO_MINOTAURO_Y 110.0f

namespace Jungle {

    namespace Entidade {

        namespace Personagem {

            namespace Inimigo {

                namespace Chefao {

                    class Minotauro : public Chefao {
                        private:
                            void inicializarAnimacao();
                        public:
                            Minotauro(const sf::Vector2f pos, Jogador::Jogador* jogador);
                            ~Minotauro();
                    };

                }

            }

        }

    }

}