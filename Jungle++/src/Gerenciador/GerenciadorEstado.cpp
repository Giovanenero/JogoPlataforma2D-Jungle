#include "../../include/Gerenciador/GerenciadorEstado.hpp"
#include "../../include/Construtor/ConstrutorFase.hpp"

namespace Jungle {

    namespace Gerenciador {

        GerenciadorEstado* GerenciadorEstado::pGerenciadorEstado = nullptr;
        GerenciadorMusica* GerenciadorEstado::pMusica = GerenciadorMusica::getGerenciadorMusica();

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

            if(pMusica){
                delete(pMusica);
                pMusica = nullptr;
            }

            if(pGerenciadorEstado){
                delete(pGerenciadorEstado);
                pGerenciadorEstado = nullptr;
            }
        }

        void GerenciadorEstado::ativarObservadores(){
            //Ativa os observaores que estavam no estado atenrior
            Estado::Estado* estadoAtual = getEstadoAtual();

            //por enquanto...
            estadoAtual->mudarEstadoObservador();
        }


        void GerenciadorEstado::desativarObservadores(){
            //desativa os observaores que estavam no estado anterior
            Estado::Estado* estadoAtual = getEstadoAtual();

            //por enquanto...tem q arrumar
           estadoAtual->mudarEstadoObservador();
        }

        void GerenciadorEstado::addEstado(const IDs::IDs ID){
            Estado::Estado* estado = nullptr;
            switch (ID)
            {
                case (IDs::IDs::estado_menu_principal):
                {
                    estado = static_cast<Estado::Estado*>(new Estado::EstadoMenuPrincipal());
                }
                    break;
                case (IDs::IDs::estado_menu_pausa):
                {
                    estado = static_cast<Estado::Estado*>(new Estado::EstadoMenuFase(IDs::IDs::estado_menu_pausa, IDs::IDs::menu_pausa));
                }
                    break;
                case (IDs::IDs::jogar_florestaBranca):
                {
                    Fase::Fase* fase = nullptr;
                    Construtor::ConstrutorFase construtorFase;

                    fase = construtorFase.criarFase(ID);
                    
                    estado = static_cast<Estado::Estado*>( new Estado::EstadoJogar(ID, fase));
                }
                    break;
                case (IDs::IDs::estado_menu_colocacao):
                {
                    estado = static_cast<Estado::Estado*>(new Estado::EstadoMenuPrincipal(ID, IDs::IDs::menu_colocacao));
                }
                    break;
                case (IDs::IDs::estado_menu_opcaoPrincipal):
                {
                    estado = static_cast<Estado::Estado*>(new Estado::EstadoMenuPrincipal(ID, IDs::IDs::menu_opcao));
                }
                    break;
                case (IDs::IDs::estado_menu_game_over):
                {
                    estado = static_cast<Estado::Estado*>(new Estado::EstadoMenuFase(ID, IDs::IDs::menu_game_over));
                }
                    break;
                case (IDs::IDs::estado_menu_salvar_jogada):
                {
                    estado = static_cast<Estado::Estado*>(new Estado::EstadoMenuFase(ID, IDs::IDs::menu_salvar_jogada));
                }
            }

            if(estado == nullptr){
                std::cout << "ERROR::Jungle::Gerenciador::GerenciadorEstado::estado eh nullptr" << std::endl;
                exit(1);
            }
            if(!pilhaEstados.empty()){
                desativarObservadores();
            }
            //arrumar...
            pMusica->mudarMusica(ID);
            pilhaEstados.push(estado);
        }

        void GerenciadorEstado::removerEstado(){
            if(pilhaEstados.top() != nullptr && !pilhaEstados.empty()){
                delete(pilhaEstados.top());
                pilhaEstados.top() = nullptr;
                pilhaEstados.pop();
            }
            if(!pilhaEstados.empty()){
                pMusica->mudarMusica(pilhaEstados.top()->getID());
                ativarObservadores();
            } else {
                GerenciadorGrafico* pGrafico = pGrafico->getGerenciadorGrafico();
                pGrafico->fecharJanela();
            }
        }

        void GerenciadorEstado::removerEstado(const int qtd){
            int i = 0;
            while(!pilhaEstados.empty() && i < qtd){
                Estado::Estado* estado = pilhaEstados.top();
                if(estado != nullptr){
                    delete(estado);
                    estado = nullptr; 
                }
                pilhaEstados.pop();
                i++;
            }
            if(!pilhaEstados.empty()){
                pMusica->mudarMusica(pilhaEstados.top()->getID());
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
                Estado::Estado* estado = pilhaEstados.top();
                estado->executar();
            }
        }

    }

}