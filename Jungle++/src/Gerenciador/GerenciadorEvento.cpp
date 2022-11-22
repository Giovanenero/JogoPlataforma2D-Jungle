#include "..\..\include\Gerenciador\GerenciadorEvento.hpp"
#include "..\..\include\Gerenciador\GerenciadorEstado.hpp"

namespace Jungle {

    namespace Gerenciador {

        GerenciadorEvento* GerenciadorEvento::pEvento = nullptr;
        GerenciadorGrafico* GerenciadorEvento::pGrafico = GerenciadorGrafico::getGerenciadorGrafico();
        GerenciadorEstado* GerenciadorEvento::pGEstado = GerenciadorEstado::getGerenciadorEstado();

        GerenciadorEvento::GerenciadorEvento(){

        }

        GerenciadorEvento::~GerenciadorEvento(){
            
        }

        GerenciadorEvento* GerenciadorEvento::getGerenciadorEvento(){
            if(pEvento == nullptr){
                pEvento = new GerenciadorEvento();
            }
            return pEvento;
        }

        void GerenciadorEvento::verificaTeclaPressionada(sf::Keyboard::Key tecla){
            if(pGEstado->getEstadoAtual()->getID() == IDs::IDs::jogar_florestaBranca || pGEstado->getEstadoAtual()->getID() == IDs::IDs::jogar_florestaVermelha){
                Estado::EstadoJogar* estadoJogar = dynamic_cast<Estado::EstadoJogar*>(pGEstado->getEstadoAtual());
                Entidade::Personagem::Jogador::Jogador* pJogador = estadoJogar->getJogador();
                if(pJogador == nullptr){
                    std::cout << "ERROR::Jungle::Gerenciador::GerenciadorEvento::pJogador eh nullptr" << std::endl;
                    exit(1);
                }
                if(tecla == sf::Keyboard::A){
                    pJogador->andar(true);
                } else if(tecla == sf::Keyboard::D){
                    pJogador->andar(false);
                } else if(tecla == sf::Keyboard::W){
                    pJogador->pular();
                } else if(tecla == sf::Keyboard::S){
                    pJogador->atacar(true);
                }
            }
        }

        void GerenciadorEvento::verificaTeclaSolta(sf::Keyboard::Key tecla){
            if(pGEstado->getEstadoAtual()->getID() == IDs::IDs::jogar_florestaBranca || pGEstado->getEstadoAtual()->getID() == IDs::IDs::jogar_florestaVermelha){
                Estado::EstadoJogar* estadoJogar = dynamic_cast<Estado::EstadoJogar*>(pGEstado->getEstadoAtual());
                Entidade::Personagem::Jogador::Jogador* pJogador = estadoJogar->getJogador();
                if(pJogador == nullptr){
                    std::cout << "ERROR::Jungle::Gerenciador::GerenciadorEvento::pJogador eh nullptr" << std::endl;
                    exit(1);
                }
                if(tecla == sf::Keyboard::A || tecla == sf::Keyboard::D){
                    pJogador->parar();
                }
            } 
            if(tecla == sf::Keyboard::Escape){
                //pGEstado->removerEstado();
                pGrafico->fecharJanela();
            } else if(tecla == sf::Keyboard::B){
                //pGEstado->addEstado(IDs::IDs::jogar_florestaBranca);
            } else if(tecla == sf::Keyboard::V){
                //pGEstado->addEstado(IDs::IDs::jogar_florestaVermelha);
            }
        }

        void GerenciadorEvento::executar(){
            sf::Event evento;
            while(pGrafico->getWindow()->pollEvent(evento)){
                if(evento.type == sf::Event::KeyPressed){
                    verificaTeclaPressionada(evento.key.code);
                } else if(evento.type == sf::Event::KeyReleased){
                    verificaTeclaSolta(evento.key.code);
                } else if(evento.type == sf::Event::Closed){
                    pGrafico->fecharJanela();
                }
            }
        }

    }

}