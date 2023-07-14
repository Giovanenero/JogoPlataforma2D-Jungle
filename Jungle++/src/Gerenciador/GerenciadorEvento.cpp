#include "../../include/Gerenciador/GerenciadorEvento.hpp"
#include "../../include/Gerenciador/GerenciadorEstado.hpp"

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
            if(listaObservador){
                delete(listaObservador);
                listaObservador = nullptr;
            }
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

        void GerenciadorEvento::executar(){
            sf::Event evento;
            while(pGrafico->getWindow()->pollEvent(evento)){
                if(evento.type == sf::Event::KeyPressed){
                    listaObservador->notificarTeclaPressionada(evento.key.code);
                } else if(evento.type == sf::Event::KeyReleased){
                    listaObservador->notificarTeclaSolta(evento.key.code);
                } else if(evento.type == sf::Event::Closed){
                    pGrafico->fecharJanela();
                } else if(evento.type == sf::Event::MouseMoved){
                    listaObservador->notificarMovimentoMouse(evento.mouseMove);
                } else if(evento.type == sf::Event::MouseButtonReleased){
                    listaObservador->notificarBotaoMouseSolta(evento.mouseButton.button);
                }
            }
        }

    }

}