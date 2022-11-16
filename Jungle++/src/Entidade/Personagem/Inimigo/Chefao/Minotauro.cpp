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
                        animacao.addAnimacao("Jungle++/img/Inimigo/Minotauro/Parado.png", "PARADO", 5, 0.15f, sf::Vector2f(4.0f, 2.0f));
                        animacao.addAnimacao("Jungle++/img/Inimigo/Minotauro/Anda.png", "ANDA", 5, 0.2f, sf::Vector2f(4.0f, 2.05f));
                        corpo.setOrigin(sf::Vector2f(tam.x / 3.0f, tam.y / 6.0f));
                    }

                }

            }

        }

    }

}