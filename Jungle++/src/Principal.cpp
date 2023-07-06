#include "../include/Principal.hpp"

namespace Jungle {

    Gerenciador::GerenciadorGrafico* Principal::pGrafico = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
    Gerenciador::GerenciadorEstado* Principal::pGerenciadorEstado = Gerenciador::GerenciadorEstado::getGerenciadorEstado();
    Gerenciador::GerenciadorEvento* Principal::pEvento = Gerenciador::GerenciadorEvento::getGerenciadorEvento();

    Principal::Principal(){
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

    Principal::~Principal(){

    }

    void Principal::inicializa(){
        pGerenciadorEstado->addEstado(IDs::IDs::estado_menu_principal);
        //pGerenciadorEstado->addEstado(IDs::IDs::estado_menu_colocacao);
    }

    void Principal::executar(){

        while(pGrafico->verificaJanelaAberta()){
            //gerencia eventos
            pEvento->executar();

            //limpa janela
            pGrafico->limpaJanela();

            //atualiza maquina de estado
            pGerenciadorEstado->executar();

            //mostra tudo na janela
            pGrafico->mostraElementos();

            //reseta o relogio
            pGrafico->resetarRelogio();
        }
    }

}