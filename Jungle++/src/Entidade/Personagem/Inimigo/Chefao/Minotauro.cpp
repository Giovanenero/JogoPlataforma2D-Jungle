#include "..\..\..\..\..\include\Entidade\Personagem\Inimigo\Chefao\Minotauro.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Personagem {

            namespace Inimigo {

                namespace Chefao {

                    Minotauro::Minotauro(const sf::Vector2f pos, const sf::Vector2f tam, Jogador::Jogador* jogador):
                        Chefao(pos, tam, jogador, IDs::IDs::minotauro)
                    {
                        inicializa();
                    }

                    Minotauro::~Minotauro(){

                    }

                    void Minotauro::inicializa(){
                        //inicializa texturas..
                    }

                }

            }

        }

    }

}