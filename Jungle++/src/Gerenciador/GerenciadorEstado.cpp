#include "..\..\include\Gerenciador\GerenciadorEstado.hpp"

namespace Jungle {

    namespace Gerenciador {

        GerenciadorEstado* GerenciadorEstado::pGerenciadorEstado = nullptr;

        GerenciadorEstado::GerenciadorEstado():
            pilhaEstados(), construtorEstado()
        {

        }

        GerenciadorEstado* GerenciadorEstado::getGerenciadorEstado(){
            if(pGerenciadorEstado == nullptr){
                pGerenciadorEstado = new GerenciadorEstado();
            }
            return pGerenciadorEstado;
        }

        GerenciadorEstado::~GerenciadorEstado(){
            //deleta todos os estados da minha pilha
            while(!pilhaEstados.empty()){
                delete(pilhaEstados.top());
                pilhaEstados.top() = nullptr;
                pilhaEstados.pop();
            }

            if(pGerenciadorEstado){
                delete(pGerenciadorEstado);
                pGerenciadorEstado = nullptr;
            }
        }

        void GerenciadorEstado::ativarObservadores(){
            //Ativa os observaores que estavam no estado atenrior
            Estado::Estado* estadoAtual = getEstadoAtual();
            switch (estadoAtual->getID())
            {
                case (IDs::IDs::jogar_florestaBranca):
                {
                    Estado::EstadoJogar* estadoJogar = static_cast<Estado::EstadoJogar*>(estadoAtual);
                    Entidade::Personagem::Jogador::Jogador* pJogador = estadoJogar->getJogador();
                    pJogador->ativarObservador();
                }
                    break;
                case (IDs::IDs::jogar_florestaVermelha):
                {
                    Estado::EstadoJogar* estadoJogar = static_cast<Estado::EstadoJogar*>(estadoAtual);
                    Entidade::Personagem::Jogador::Jogador* pJogador = estadoJogar->getJogador();
                    pJogador->ativarObservador();
                }
                    break;
                case (IDs::IDs::estado_menu_principal):
                {

                }
                    break;
            }
        }


        void GerenciadorEstado::desativarObservadores(){
            //desativa os observaores que estavam no estado anterior
            Estado::Estado* estadoAtual = getEstadoAtual();
            switch (estadoAtual->getID())
            {
                case (IDs::IDs::jogar_florestaBranca):
                {
                    Estado::EstadoJogar* estadoJogar = static_cast<Estado::EstadoJogar*>(estadoAtual);
                    Entidade::Personagem::Jogador::Jogador* pJogador = estadoJogar->getJogador();
                    pJogador->desativarObservador();
                }
                    break;
                case (IDs::IDs::jogar_florestaVermelha):
                {
                    Estado::EstadoJogar* estadoJogar = static_cast<Estado::EstadoJogar*>(estadoAtual);
                    Entidade::Personagem::Jogador::Jogador* pJogador = estadoJogar->getJogador();
                    pJogador->desativarObservador();
                }
                case (IDs::IDs::estado_menu_principal):
                {
                    //terminar...
                }
                    break;
            }
        }

        void GerenciadorEstado::addEstado(const IDs::IDs ID){
            Estado::Estado* estado = construtorEstado.criarEstado(ID);
            if(estado ==  nullptr){
                std::cout << "ERROR::Jungle::Gerenciador::GerenciadorEstado::estado eh nullptr" << std::endl;
                exit(1);
            }
            if(!pilhaEstados.empty()){
                desativarObservadores();
            }
            pilhaEstados.push(estado);
        }

        void GerenciadorEstado::removerEstado(){
            if(pilhaEstados.top() != nullptr){
                delete(pilhaEstados.top());
                pilhaEstados.top() = nullptr;
                pilhaEstados.pop();
            }
            if(!pilhaEstados.empty()){
                ativarObservadores();
            } else {
                GerenciadorGrafico* pGrafico = pGrafico->getGerenciadorGrafico();
                pGrafico->fecharJanela();
            }
        }

        Estado::Estado* GerenciadorEstado::getEstadoAtual() {
            return pilhaEstados.top();
        }


        void GerenciadorEstado::executar(){
            //executa o estado que está no topo da minha pilha
            if(!pilhaEstados.empty()){
                pilhaEstados.top()->executar();
            }
        }

    }

}