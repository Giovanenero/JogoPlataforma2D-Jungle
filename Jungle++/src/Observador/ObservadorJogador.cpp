#include "../../include/Observador/ObservadorJogador.hpp"

namespace Jungle {

    namespace Observador {

        ObservadorJogador::ObservadorJogador(Entidade::Personagem::Jogador::Jogador* pJogador):
            Observador(), pJogador(pJogador)
        {

        }

        ObservadorJogador::~ObservadorJogador(){
            
        }


        void ObservadorJogador::teclaPressionada(const sf::Keyboard::Key tecla){
            if(teclado[tecla] == 'a'){
                pJogador->andar(true);
            } else if(teclado[tecla] == 'd'){
                pJogador->andar(false);
            } else if(teclado[tecla] == 'w'){
                pJogador->pular();
            } else if(teclado[tecla] == 's'){
                if(pJogador->getNoChao()){
                        pJogador->atacar(true);
                    }
            }
        }

        void ObservadorJogador::teclaSolta(const sf::Keyboard::Key tecla){
            if(teclado[tecla] == 'a' || teclado[tecla] == 'd'){
                pJogador->parar();
            } else if(teclado[tecla] == 'w' || teclado[tecla] == 's'){
                pJogador->atacar(false);
            }
        }

    }

}