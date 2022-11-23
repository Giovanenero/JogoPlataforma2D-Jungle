#include "..\..\include\Observador\ObservadorJogador.hpp"

namespace Jungle {

    namespace Observador {

        ObservadorJogador::ObservadorJogador(Entidade::Personagem::Jogador::Jogador* pJogador):
            pJogador(pJogador)
        {

        }

        ObservadorJogador::~ObservadorJogador(){
            removerObservador();
        }

        void ObservadorJogador::teclaPressionada(const sf::Keyboard::Key tecla){
            switch (tecla)
            {
                case (sf::Keyboard::A):
                {
                    pJogador->andar(true);
                }
                    break;
                case (sf::Keyboard::D):
                {
                    pJogador->andar(false);
                }
                    break;
                case(sf::Keyboard::W):
                {
                    pJogador->pular();
                }
                    break;
                case(sf::Keyboard::S):
                {
                    pJogador->atacar(true);
                }
                    break;;
            }
        }

        void ObservadorJogador::teclaSolta(const sf::Keyboard::Key tecla){
            switch (tecla)
            {
                case (sf::Keyboard::A):
                {
                    pJogador->parar();
                }
                    break;
                case(sf::Keyboard::D):
                {
                    pJogador->parar();
                }
                    break;
            }
        }

    }

}