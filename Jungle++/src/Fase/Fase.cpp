#include "..\..\include\Fase\Fase.hpp"
#include "..\..\include\Observador\ObservadorFase.hpp"

namespace Jungle {

    namespace Fase {

        Fase::Fase(const IDs::IDs ID_Fase, const IDs::IDs ID_Fundo):
            Ente(ID_Fase), fundo(ID_Fundo), listaPersonagens(), listaObstaculos(),
            pColisao(new Gerenciador::GerenciadorColisao(&listaPersonagens, &listaObstaculos)),
            construtorEntidade(), observadorFase(new Observador::ObservadorFase(this))
        {
            if(pColisao == nullptr){
                std::cout << "Jungle::Fase::nao foi possivel criar um Gerenciador de Colisao" << std::endl;
                exit(1);
            }
        }

        Fase::~Fase(){
            if(pColisao){
                delete(pColisao);
                pColisao = nullptr;
            }
            std::cout << "a" << std::endl;
            listaObstaculos.limparLista();
            std::cout << "aa" << std::endl;
            listaPersonagens.limparLista();
            std::cout << "aaa" << std::endl;
            if(observadorFase){
                delete(observadorFase);
                observadorFase = nullptr;
            }
        }

        void Fase::criarEntidade(char letra, const sf::Vector2i pos){
            sf::Vector2f posAux = sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f);
            switch (letra)
            {
                case ('e'):
                {
                    listaPersonagens.addEntidade(construtorEntidade.criarEsqueleto(posAux));
                }
                break;
                case('c'):
                {
                    listaObstaculos.addEntidade(construtorEntidade.criarCaixa(posAux));
                }
                break;
                case('#'):
                {
                    listaObstaculos.addEntidade(construtorEntidade.criarPlataforma(posAux));
                }
                break;
                case('j'):{
                    //listaPersonagens.addEntidade(construtorEntidade.criarJogador(posAux));
                }
                break;
                case('m'):{
                    listaPersonagens.addEntidade(construtorEntidade.criarMinotauro(posAux));
                }
                break;
            }
        }

        Entidade::Personagem::Jogador::Jogador* Fase::getJogador(){
            for(int i = 0; i < listaPersonagens.getTam(); i++){
                Entidade::Entidade* ent = listaPersonagens.operator[](i);
                if(ent->getID() == IDs::IDs::jogador){
                    return static_cast<Entidade::Personagem::Jogador::Jogador*>(ent);
                }
            }
            return nullptr;
        }

        void Fase::mudarEstadoObservador(){
            observadorFase->mudarEstadoAtivar();
        }

        void Fase::desenhar(){
            fundo.executar();
            listaPersonagens.desenharEntidades();
            listaObstaculos.desenharEntidades();
        }

        void Fase::executar(){
            //atualiza fundo
            fundo.executar();

            //atualiza e desenha entidades
            listaPersonagens.executar();
            listaObstaculos.executar();

            //verifica colisão
            pColisao->executar();
        }

    }

}