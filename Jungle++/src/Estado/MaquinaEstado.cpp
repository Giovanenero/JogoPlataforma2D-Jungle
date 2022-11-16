#include "..\..\include\Estado\MaquinaEstado.hpp"

namespace Jungle {

    namespace Estado {

        MaquinaEstado::MaquinaEstado():
            pilhaEstados()
        {

        }

        MaquinaEstado::~MaquinaEstado(){
            //deleta todos os estados da minha pilha
            while(!pilhaEstados.empty()){
                delete(pilhaEstados.top());
                pilhaEstados.top() = nullptr;
                pilhaEstados.pop();
            }
        }

        void MaquinaEstado::addEstadoJogar(const IDs::IDs ID){
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
            EstadoJogar* estadoJogar = new EstadoJogar(fase);
            if(estadoJogar == nullptr){
                std::cout << "Jungle::Estado::MaquinaEstado::nao foi possivel criar um Estado Jogar" << std::endl;
                exit(1);
            }
            pilhaEstados.push(static_cast<Estado*>(estadoJogar));
        }

        void MaquinaEstado::addEstado(const IDs::IDs ID){
            if(ID == IDs::IDs::jogar_florestaBranca || ID == IDs::IDs::jogar_florestaVermleha){
                addEstadoJogar(ID);
            }
        }

        void MaquinaEstado::removerEstado(){
            delete(pilhaEstados.top());
            pilhaEstados.top() = nullptr;
            pilhaEstados.pop();

            if(pilhaEstados.empty()){
               Gerenciador::GerenciadorGrafico::getGerenciadorGrafico()->fecharJanela(); 
            }
        }


        void MaquinaEstado::executar(){
            //executa o estado que está no topo da minha pilha
            if(!pilhaEstados.empty()){
                pilhaEstados.top()->executar();
            }
        }

    }

}