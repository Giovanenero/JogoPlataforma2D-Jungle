#include "../../include/Lista/ListaObservador.hpp"

namespace Jungle {

    namespace Lista {

        ListaObservador::ListaObservador():
            objListaObservador()
        {

        }

        ListaObservador::~ListaObservador(){
            objListaObservador.limparLista();
        }

        void ListaObservador::addObservador(Observador::Observador* observador){
            objListaObservador.addElemento(observador);
        }

        void ListaObservador::removerObservador(Observador::Observador* observador){
            objListaObservador.removerElemento(observador, true);
        }

        void ListaObservador::removerObservador(int pos){
            objListaObservador.removerElemento(pos, true);
        }

        int ListaObservador::getTam(){
            return objListaObservador.getTam();
        }

        Observador::Observador* ListaObservador::operator[](int pos){
            return objListaObservador.operator[](pos);
        }

        void ListaObservador::notificarTeclaPressionada(const sf::Keyboard::Key tecla){
            for(int i = 0; i < objListaObservador.getTam(); i++){
                Observador::Observador* observador = objListaObservador.operator[](i);
                if(observador->getAtivar()){
                    observador->teclaPressionada(tecla);
                }
                observador = nullptr;
            }
        }

        void ListaObservador::notificarTeclaSolta(const sf::Keyboard::Key tecla){
            for(int i = 0; i < objListaObservador.getTam(); i++){
                Observador::Observador* observador = objListaObservador.operator[](i);
                if(observador->getAtivar()){
                    observador->teclaSolta(tecla);
                }
                observador = nullptr;
            }
        }

        void ListaObservador::notificarMovimentoMouse(const sf::Event::MouseMoveEvent mouse){
            sf::Vector2f posMouse = sf::Vector2f((float)mouse.x, (float)mouse.y);
            for(int i = 0; i < objListaObservador.getTam(); i++){
                Observador::Observador* observador = objListaObservador.operator[](i);
                if(observador->getAtivar()){
                    observador->moveMouse(posMouse);
                }
                observador = nullptr;
            }
        }

        void ListaObservador::notificarBotaoMouseSolta(const sf::Mouse::Button botaoMouse){
            for(int i = 0; i < objListaObservador.getTam(); i++){
                Observador::Observador* observador = objListaObservador.operator[](i);
                if(observador->getAtivar()){
                    observador->botaoMouseSolta(botaoMouse);
                }
                observador = nullptr;
            }
        }

    }

}