#include "..\..\..\..\include\Entidade\Personagem\Inimigo\Esqueleto.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Personagem {

            namespace Inimigo {

                Esqueleto::Esqueleto(const sf::Vector2f pos, const sf::Vector2f tam, Jogador::Jogador* jogador):
                    Inimigo(pos, tam, jogador, IDs::IDs::esqueleto)
                {
                    inicializa();
                }

                Esqueleto::~Esqueleto(){

                }

                void Esqueleto::inicializa(){
                    animacao.addAnimacao("Jungle++/img/Inimigo/Esqueleto/Parado.png", "PARADO", 11, 0.12f, sf::Vector2f(1.0f, 1.10f));
                    animacao.addAnimacao("Jungle++/img/Inimigo/Esqueleto/Anda.png", "ANDA", 13, 0.15f, sf::Vector2f(1.0f, 1.10f));
                    corpo.setOrigin(sf::Vector2f(tam.x / 12.0f, tam.y / 8.5f));
                }

            }

        }

    }

}