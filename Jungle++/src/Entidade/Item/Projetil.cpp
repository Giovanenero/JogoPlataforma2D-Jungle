#include "../../../include/Entidade/Item/Projetil.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Item {

            Projetil::Projetil(Personagem::Personagem* personagem):
                Arma(IDs::IDs::projetil_inimigo, personagem), animacao(&corpo)
            {
                inicializarAnimacao();
            }

            Projetil::~Projetil(){

            }

            void Projetil::inicializarAnimacao(){

            }

            void Projetil::atualizar(){

            }

        }

    }
    
}