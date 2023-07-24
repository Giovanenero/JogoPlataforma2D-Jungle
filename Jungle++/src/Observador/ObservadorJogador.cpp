#include "../../include/Observador/ObservadorJogador.hpp"
#include "../../include/Estado/EstadoJogar.hpp"

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
            } else if(teclado[tecla] == 'x'){
                if(pJogador->getNoChao()){
                    pJogador->atacar(true);
                }
            }
        }

        void ObservadorJogador::teclaSolta(const sf::Keyboard::Key tecla){
            if(teclado[tecla] == 'a' || teclado[tecla] == 'd'){
                pJogador->parar();
            } else if(teclado[tecla] == 'w' || teclado[tecla] == 'x'){
                pJogador->atacar(false);
            }
        }

        void ObservadorJogador::atualizarPontuacao(const unsigned int pontos){
            Estado::Estado* estado = pGEstado->getEstadoAtual();
            if(estado->getID() == IDs::IDs::jogar_florestaBranca || estado->getID() == IDs::IDs::jogar_florestaVermelha){
                Estado::EstadoJogar* estadoJogar = dynamic_cast<Estado::EstadoJogar*>(estado);
                Fase::Fase* fase = estadoJogar->getFase();
                if(fase == nullptr){
                    std::cout << "ObservadorJogador::Fase eh nullptr" << std::endl;
                    exit(1);
                }
                fase->setPontuacao(pontos);

            }
        }

    }

}