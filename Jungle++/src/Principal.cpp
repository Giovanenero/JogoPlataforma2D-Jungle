#include "..\include\Principal.hpp"

Jungle::Principal::Principal():
    pGrafico(pGrafico->getGerenciadorGrafico()), 
    pEvento(pEvento->getGerenciadorEvento()),
    fase(nullptr)
{
    if(pGrafico == nullptr){
        std::cout << "ERROR::Jungle::Principal nao foi possivel criar o GerenciadorGrafico" << std::endl;
        exit(1);
    }

    if(pEvento == nullptr){
        std::cout << "ERROR::Jungle::Principal nao foi possivel criar um GerenciadorEvento" << std::endl;
        exit(1);
    }
    criarFase();
    executar();
}

Jungle::Principal::~Principal(){
    if(fase){
        delete(fase);
        fase = nullptr;
    }
}

void Jungle::Principal::criarFase(){
    //Fase::FlorestaBranca* aux = new Fase::FlorestaBranca();
    Fase::FlorestaVermelha* aux = new Fase::FlorestaVermelha();
    if(aux == nullptr){
        std::cout << "Jungle::Principal::nao foi possivel criar fase" << std::endl;
        exit(1);
    }
    fase = static_cast<Fase::Fase*>(aux);
    fase->criarFundo();
    fase->criarMapa();
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

        fase->executar();

        //mostra tudo na janela
        pGrafico->mostraElementos();
    }
}