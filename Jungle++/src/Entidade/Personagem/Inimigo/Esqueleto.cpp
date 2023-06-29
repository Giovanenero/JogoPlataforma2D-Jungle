#include "..\..\..\..\include\Entidade\Personagem\Inimigo\Esqueleto.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Personagem {

            namespace Inimigo {

                Esqueleto::Esqueleto(const sf::Vector2f pos, Jogador::Jogador* jogador):
                    Inimigo(
                        pos, 
                        sf::Vector2f(TAMANHO_ESQUELO_X, TAMANHO_ESQUELO_Y), 
                        jogador, 
                        IDs::IDs::esqueleto, 
                        TEMPO_ESQUELETO_MORRER, 
                        PONTOS_ESQUELETO
                    )
                {
                    inicializaAnimacao();
                }

                Esqueleto::~Esqueleto(){

                }

                void Esqueleto::inicializaAnimacao(){
                    animacao.addAnimacao("Jungle++/img/Personagem/Inimigo/Esqueleto/Parado.png", "PARADO", 11, 0.12f, sf::Vector2f(1.0f, 1.10f));
                    animacao.addAnimacao("Jungle++/img/Personagem/Inimigo/Esqueleto/Anda.png", "ANDA", 13, 0.15f, sf::Vector2f(1.0f, 1.10f));
                    animacao.addAnimacao("Jungle++/img/Personagem/Inimigo/Esqueleto/Morre.png", "MORRE", 15, 0.15f, sf::Vector2f(1.0f, 1.10f));
                    corpo.setOrigin(sf::Vector2f(tam.x / 12.0f, tam.y / 8.5f));
                }

            }

        }

    }

}