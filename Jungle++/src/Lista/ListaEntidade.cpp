#include "..\..\include\Lista\ListaEntidade.hpp"

namespace Jungle {

    namespace Lista {

        ListaEntidade::ListaEntidade():
            objListaEntidade()
        {

        }

        ListaEntidade::~ListaEntidade(){

        }

        void ListaEntidade::addEntidade(Entidade::Entidade* entidade){
            objListaEntidade.addElemento(entidade);
        }

        void ListaEntidade::removerEntidade(Entidade::Entidade* entidade){
            objListaEntidade.removerElemento(entidade);
        }
            
        void ListaEntidade::removerEntidade(int pos){
            objListaEntidade.removerElemento(pos);
        }

        int ListaEntidade::getTam(){
            return objListaEntidade.getTam();
        }

        Entidade::Entidade* ListaEntidade::operator[](int pos){
            return objListaEntidade.operator[](pos);
        }

        void ListaEntidade::limparLista(){
            objListaEntidade.limparLista();
        }

        void ListaEntidade::executar(){
            //atualiza e desenha as entidades
            int tam = objListaEntidade.getTam();
            Entidade::Entidade* aux = nullptr;
            for(int i = 0; i < tam; i++){
                aux = objListaEntidade.operator[](i);
                aux->atualizar();
            }
        }

        void ListaEntidade::desenharEntidades(){
            //apenas desenha as Entidades
            int tam = objListaEntidade.getTam();
            Entidade::Entidade* aux = nullptr;
            for(int i = 0; i < tam; i++){
                aux = objListaEntidade.operator[](i);
                aux->desenhar();
            }
        }

    }

}