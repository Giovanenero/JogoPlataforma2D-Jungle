#pragma once 

#include "..\Inimigo.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Personagem {

            namespace Inimigo {

                namespace Chefao {

                    class Chefao : public Inimigo {
                    protected:
                        int mudarAtaque;

                    public:
                        Chefao(const sf::Vector2f pos, const sf::Vector2f tam, Jogador::Jogador* jogador, const IDs::IDs ID);
                        ~Chefao();
                    };

                }

            }

        }

    }

}