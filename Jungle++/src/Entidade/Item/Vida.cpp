#include "../../../include/Entidade/Item/Vida.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Item {

            Vida::Vida(const sf::Vector2f pos):
                Entidade(sf::Vector2f(TAMANHO_VIDA, TAMANHO_VIDA), IDs::IDs::vida, pos)
            {

            }

            Vida::~Vida(){

            }

            void Vida::atualizar(){

            }

        }

    }

}