#include "..\..\include\Lista\ListaEntidade.hpp"

Jungle::Lista::ListaEntidade::ListaEntidade():
    objListaEntidade()
{

}

Jungle::Lista::ListaEntidade::~ListaEntidade(){

}

void Jungle::Lista::ListaEntidade::addEntidade(Entidade::Entidade* entidade){
    objListaEntidade.addElemento(entidade);
}

void Jungle::Lista::ListaEntidade::removerEntidade(Entidade::Entidade* entidade){
    objListaEntidade.removerElemento(entidade);
}
    
void Jungle::Lista::ListaEntidade::removerEntidade(int pos){
    objListaEntidade.removerElemento(pos);
}

int Jungle::Lista::ListaEntidade::getTam(){
    return objListaEntidade.getTam();
}

Jungle::Entidade::Entidade* Jungle::Lista::ListaEntidade::operator[](int pos){
    return objListaEntidade.operator[](pos);
}

void Jungle::Lista::ListaEntidade::limparLista(){
    objListaEntidade.limparLista();
}

void Jungle::Lista::ListaEntidade::executar(){
    int tam = objListaEntidade.getTam();
    Entidade::Entidade* aux = nullptr;
    for(int i = 0; i < tam; i++){
        aux = objListaEntidade.operator[](i);
        aux->atualizar();
    }
}