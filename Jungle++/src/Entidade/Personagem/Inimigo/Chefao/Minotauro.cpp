#include "..\..\..\..\..\include\Entidade\Personagem\Inimigo\Chefao\Minotauro.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Personagem {

            namespace Inimigo {

                namespace Chefao {

                    Minotauro::Minotauro(const sf::Vector2f pos, Jogador::Jogador* jogador):
                        Chefao(pos, sf::Vector2f(TAMANHO_MINOTAURO_X, TAMANHO_MINOTAURO_Y), jogador, IDs::IDs::minotauro)
                    {
                        inicializaAnimacao();
                    }

                    Minotauro::~Minotauro(){
                        
                    }

                    void Minotauro::inicializaAnimacao(){
                        animacao.addAnimacao("Jungle++/img/Inimigo/Minotauro/Parado.png", "PARADO", 5, 0.15f, sf::Vector2f(4.0f, 2.1f));
                        animacao.addAnimacao("Jungle++/img/Inimigo/Minotauro/Anda.png", "ANDA", 5, 0.2f, sf::Vector2f(4.0f, 2.07f));
                        corpo.setOrigin(sf::Vector2f(tam.x / 3.0f, tam.y / 6.0f));
                    }

                }

            }

        }

    }

}