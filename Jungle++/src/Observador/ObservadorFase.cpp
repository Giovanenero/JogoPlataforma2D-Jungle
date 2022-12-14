#include "..\..\include\Observador\ObservadorFase.hpp"
#include "..\..\include\Gerenciador\GerenciadorEstado.hpp"

namespace Jungle {

    namespace Observador {

        ObservadorFase::ObservadorFase(Fase::Fase* fase):
            Observador(), fase(fase)
        {

        }

        ObservadorFase::~ObservadorFase(){

        }

        void ObservadorFase::teclaPressionada(const sf::Keyboard::Key tecla){
            //terminar..
        }

        void ObservadorFase::teclaSolta(const sf::Keyboard::Key tecla){
            switch (tecla)
            {
                case (sf::Keyboard::Escape):
                {
                    pGEstado->addEstado(IDs::IDs::estado_menu_pausa);
                }
                    break;
            }
        }

    }

}