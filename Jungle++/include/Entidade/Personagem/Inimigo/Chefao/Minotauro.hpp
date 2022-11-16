#pragma once 

#include "..\..\Jogador\Jogador.hpp"
#include "Chefao.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Personagem {

            namespace Inimigo {

                namespace Chefao {

                    class Minotauro : public Chefao {
                        private:
                            void inicializa();
                        public:
                            Minotauro(const sf::Vector2f pos, const sf::Vector2f tam, Jogador::Jogador* jogador);
                            ~Minotauro();
                    };

                }

            }

        }

    }

}