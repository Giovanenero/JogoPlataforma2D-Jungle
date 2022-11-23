#include "..\..\include\Gerenciador\GerenciadorEvento.hpp"
#include "..\..\include\Gerenciador\GerenciadorEstado.hpp"

namespace Jungle {

    namespace Gerenciador {

        GerenciadorEvento* GerenciadorEvento::pEvento = nullptr;
        GerenciadorGrafico* GerenciadorEvento::pGrafico = GerenciadorGrafico::getGerenciadorGrafico();
        GerenciadorEstado* GerenciadorEvento::pGEstado = GerenciadorEstado::getGerenciadorEstado();
        Lista::ListaObservador* GerenciadorEvento::listaObservador = nullptr;

        GerenciadorEvento::GerenciadorEvento()
        {
            listaObservador = new Lista::ListaObservador();
            if(listaObservador == nullptr){
                std::cout << "ERROR::Jungle::Gerenciador::GerenciadorEvento::nao foi possivel criar uma Lista de Observadores" << std::endl;
                exit(1);
            }
        }

        GerenciadorEvento::~GerenciadorEvento(){
            
        }

        GerenciadorEvento* GerenciadorEvento::getGerenciadorEvento(){
            if(pEvento == nullptr){
                pEvento = new GerenciadorEvento();
            }
            return pEvento;
        }

        void GerenciadorEvento::addObservador(Observador::Observador* observador){
            listaObservador->addObservador(observador);
        }

        void GerenciadorEvento::removerObservador(Observador::Observador* observador){
            listaObservador->removerObservador(observador);
        }

        void GerenciadorEvento::removerObservador(int pos){
            listaObservador->removerObservador(pos);
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
                pGEstado->removerEstado();
            }
        }

        void GerenciadorEvento::executar(){
            sf::Event evento;
            while(pGrafico->getWindow()->pollEvent(evento)){
                if(evento.type == sf::Event::KeyPressed){
                    //verificaTeclaPressionada(evento.key.code);
                    listaObservador->notificarTeclaPressionada(evento.key.code);
                } else if(evento.type == sf::Event::KeyReleased){
                    //verificaTeclaSolta(evento.key.code);
                    listaObservador->notificarTeclaSolta(evento.key.code);
                } else if(evento.type == sf::Event::Closed){
                    pGrafico->fecharJanela();
                }
            }
        }

    }

}