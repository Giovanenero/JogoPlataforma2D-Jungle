#include "..\include\Principal.hpp"

Jungle::Principal::Principal():
    pGrafico(pGrafico->getGerenciadorGrafico()), 
    pEvento(pEvento->getGerenciadorEvento()),
    pGerenciadorEstado(pGerenciadorEstado->getGerenciadorEstado())
{
    if(pGrafico == nullptr){
        std::cout << "ERROR::Jungle::Principal nao foi possivel criar o GerenciadorGrafico" << std::endl;
        exit(1);
    }
    if(pEvento == nullptr){
        std::cout << "ERROR::Jungle::Principal nao foi possivel criar um GerenciadorEvento" << std::endl;
        exit(1);
    }
    if(pGerenciadorEstado == nullptr){
        std::cout << "ERROR::Jungle::Principal::nao foi possivel criar um GerenciadorEstado" << std::endl;
        exit(1);
    }
    inicializa();
}

Jungle::Principal::~Principal(){

}

void Jungle::Principal::inicializa(){
    pGerenciadorEstado->addEstado(IDs::IDs::jogar_florestaBranca);
}

void Jungle::Principal::executar(){
    /**
     * @ return void 
     * 
     * Loop principal do jogo em que ocorre todo os eventos e move as entidades
     */

    while(pGrafico->verificaJanelaAberta()){
        //gerencia eventos
        pEvento->executar();

        //limpa janela
        pGrafico->limpaJanela();

        //atualiza maquina de estado
        pGerenciadorEstado->executar();

        //mostra tudo na janela
        pGrafico->mostraElementos();
    }
}