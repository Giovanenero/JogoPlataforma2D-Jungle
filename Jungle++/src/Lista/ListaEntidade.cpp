#include "../../include/Lista/ListaEntidade.hpp"

namespace Jungle {

    namespace Lista {

        ListaEntidade::ListaEntidade():
            objListaEntidade()
        {

        }

        ListaEntidade::~ListaEntidade(){
            limparLista();
        }

        void ListaEntidade::addEntidade(Entidade::Entidade* entidade){
            objListaEntidade.addElemento(entidade);
        }

        void ListaEntidade::addEntidade(Entidade::Entidade* entidade, int pos){
            objListaEntidade.addElemento(entidade, pos);
        }

        void ListaEntidade::removerEntidade(Entidade::Entidade* entidade, const bool deletar){
            objListaEntidade.removerElemento(entidade, deletar);
        }
            
        void ListaEntidade::removerEntidade(int pos, const bool deletar){
            objListaEntidade.removerElemento(pos, deletar);
        }

        const int ListaEntidade::getTam(){
            return objListaEntidade.getTam();
        }

        Entidade::Entidade* ListaEntidade::operator[](int pos){
            return objListaEntidade.operator[](pos);
        }

        std::vector<Entidade::Entidade*> ListaEntidade::getEntidades(const IDs::IDs ID){
            std::vector<Entidade::Entidade*> entidades;
            for(int i = 0; i < objListaEntidade.getTam(); i++){
                Entidade::Entidade* entidade = objListaEntidade[i];
                if(entidade->getID() == ID){
                    entidades.push_back(entidade);
                }
            }
            return entidades;
        }

        void ListaEntidade::limparLista(){
            objListaEntidade.limparLista();
        }

        void ListaEntidade::executar(){
            //atualiza e desenha as entidades
            int tam = objListaEntidade.getTam();
            Entidade::Entidade* aux = nullptr;
            for(int i = tam - 1; i >= 0; i--){
                aux = objListaEntidade.operator[](i);
                if(aux->getRemover()){
                    objListaEntidade.removerElemento(aux, true);
                    aux = nullptr;
                } else {
                    aux->atualizar();
                }
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