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

        void ObservadorFase::notificarJogadorMorreu(){
            pGEstado->addEstado(IDs::IDs::estado_menu_game_over);
        }

        void ObservadorFase::teclaPressionada(const sf::Keyboard::Key tecla){
            //terminar..
        }

        void ObservadorFase::teclaSolta(const sf::Keyboard::Key tecla){
            if(tecladoEspecial[tecla] == "Escape"){
                pGEstado->addEstado(IDs::IDs::estado_menu_pausa);
            } else if(teclado[tecla] == 'p'){
                pGEstado->addEstado(IDs::IDs::estado_menu_game_over);
            }
        }

    }

}