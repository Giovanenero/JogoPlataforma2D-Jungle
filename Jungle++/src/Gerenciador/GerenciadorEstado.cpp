#include "..\..\include\Gerenciador\GerenciadorEstado.hpp"

namespace Jungle {

    namespace Gerenciador {

        GerenciadorEstado* GerenciadorEstado::pGerenciadorEstado = nullptr;

        GerenciadorEstado::GerenciadorEstado():
            pilhaEstados()
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

        void GerenciadorEstado::addEstadoJogar(const IDs::IDs ID){
            Fase::Fase* fase = nullptr;
            if(ID == IDs::IDs::jogar_florestaBranca){
                fase = static_cast<Fase::Fase*>(new Fase::FlorestaBranca());
            } else {
                fase = static_cast<Fase::Fase*>(new Fase::FlorestaVermelha());
            }
            if(fase == nullptr){
                std::cout << "Jungle::Estado::MaquinaEstado::nao foi possivel criar uma fase" << std::endl;
                exit(1);
            }
            fase->criarFundo();
            fase->criarMapa();
            Estado::EstadoJogar* estadoJogar = new Estado::EstadoJogar(fase);
            if(estadoJogar == nullptr){
                std::cout << "Jungle::Estado::MaquinaEstado::nao foi possivel criar um Estado Jogar" << std::endl;
                exit(1);
            }
            pilhaEstados.push(static_cast<Estado::Estado*>(estadoJogar));
        }

        void GerenciadorEstado::addEstado(const IDs::IDs ID){
            if(ID == IDs::IDs::jogar_florestaBranca || ID == IDs::IDs::jogar_florestaVermleha){
                addEstadoJogar(ID);
            }
        }

        void GerenciadorEstado::removerEstado(){
            delete(pilhaEstados.top());
            pilhaEstados.top() = nullptr;
            pilhaEstados.pop();

            if(pilhaEstados.empty()){
               Gerenciador::GerenciadorGrafico::getGerenciadorGrafico()->fecharJanela(); 
            }
        }


        void GerenciadorEstado::executar(){
            //executa o estado que está no topo da minha pilha
            if(!pilhaEstados.empty()){
                pilhaEstados.top()->executar();
            }
        }

    }

}