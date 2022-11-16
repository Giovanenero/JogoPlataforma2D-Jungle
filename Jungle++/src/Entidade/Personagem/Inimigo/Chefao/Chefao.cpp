#pragma once 

#include "..\..\..\..\..\include\Entidade\Personagem\Inimigo\Chefao\Chefao.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Personagem {

            namespace Inimigo {

                namespace Chefao {

                    Chefao::Chefao(const sf::Vector2f pos, const sf::Vector2f tam, Jogador::Jogador* jogador, const IDs::IDs ID):
                        Inimigo(pos, tam, jogador, ID)
                    {

                    }

                    Chefao::~Chefao(){

                    }

                    void Chefao::atualizarAnimacao(){

                    }

                }

            }

        }

    }

}