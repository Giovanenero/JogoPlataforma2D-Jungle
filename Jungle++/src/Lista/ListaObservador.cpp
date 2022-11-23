#include "..\..\include\Lista\ListaObservador.hpp"

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
            objListaObservador.removerElemento(observador);
        }

        void ListaObservador::removerObservador(int pos){
            objListaObservador.removerElemento(pos);
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
                observador->teclaPressionada(tecla);
                observador = nullptr;
            }
        }

        void ListaObservador::notificarTeclaSolta(const sf::Keyboard::Key tecla){
            for(int i = 0; i < objListaObservador.getTam(); i++){
                Observador::Observador* observador = objListaObservador.operator[](i);
                observador->teclaSolta(tecla);
                observador = nullptr;
            }
        }

    }

}