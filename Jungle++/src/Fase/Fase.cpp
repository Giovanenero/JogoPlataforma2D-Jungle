#include "../../include/Fase/Fase.hpp"
#include "../../include/Observador/ObservadorFase.hpp"

namespace Jungle {

    namespace Fase {

        Fase::Fase(const IDs::IDs ID_Fase, const IDs::IDs ID_Fundo):
            Ente(ID_Fase), fundo(ID_Fundo), listaPersonagens(new Lista::ListaEntidade()), listaObstaculos(new Lista::ListaEntidade()),
            pColisao(new Gerenciador::GerenciadorColisao(listaPersonagens, listaObstaculos)),
            construtorEntidade(), observadorFase(new Observador::ObservadorFase(this)),
            pontuacaoJogador(0)
        {
            if(listaPersonagens == nullptr || listaObstaculos == nullptr){
                std::cout << "Jungle::Fase::nao foi possivel criar lista de entidades na fase" << std::endl;
                exit(1);
            }

            if(pColisao == nullptr){
                std::cout << "Jungle::Fase::nao foi possivel criar um Gerenciador de Colisao" << std::endl;
                exit(1);
            }
        }

        Fase::~Fase(){
            if(pColisao != nullptr){
                delete(pColisao);
                pColisao = nullptr;
            }
            if(observadorFase != nullptr){
                delete(observadorFase);
                observadorFase = nullptr;
            }

            if(listaPersonagens != nullptr){
                delete(listaPersonagens);
                listaPersonagens = nullptr;
            }

            if(listaObstaculos != nullptr){
                delete(listaObstaculos);
                listaObstaculos = nullptr;
            }
        }

        void Fase::criarEntidade(char letra, const sf::Vector2i pos){
            sf::Vector2f posAux = sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f);
            switch (letra)
            {
                case ('e'):
                {
                    listaPersonagens->addEntidade(construtorEntidade.criarEsqueleto(posAux));
                }
                break;
                case('c'):
                {
                    listaObstaculos->addEntidade(construtorEntidade.criarCaixa(posAux));
                }
                break;
                case('#'):
                {
                    listaObstaculos->addEntidade(construtorEntidade.criarPlataforma(posAux));
                }
                break;
                case('j'):{
                    //listaPersonagens->addEntidade(construtorEntidade.criarJogador(posAux));
                }
                break;
                case('m'):{
                    listaPersonagens->addEntidade(construtorEntidade.criarMinotauro(posAux));
                }
                break;
            }
        }

        Entidade::Personagem::Jogador::Jogador* Fase::getJogador(){
            for(int i = 0; i < listaPersonagens->getTam(); i++){
                Entidade::Entidade* ent = listaPersonagens->operator[](i);
                if(ent->getID() == IDs::IDs::jogador){
                    return dynamic_cast<Entidade::Personagem::Jogador::Jogador*>(ent);
                }
            }
            return nullptr;
        }

        void Fase::mudarEstadoObservador(){
            observadorFase->mudarEstadoAtivar();
        }

        void Fase::desenhar(){
            fundo.executar();
            listaPersonagens->desenharEntidades();
            listaObstaculos->desenharEntidades();
        }

         const unsigned int Fase::getPontuacaoJogador() const {
            return pontuacaoJogador;
         }

         Lista::ListaEntidade* Fase::getListaPersonagem(){
            return listaPersonagens;
         }

        Lista::ListaEntidade* Fase::getListaObstaculo(){
            return listaObstaculos;
        }

        void Fase::executar(){
            Entidade::Personagem::Jogador::Jogador* jogador = getJogador();
            if(jogador){
                //atualiza fundo
                fundo.executar();

                //atualiza a pontuação do jogador
                pontuacaoJogador = jogador->getPontos();

                //atualiza e desenha entidades
                listaPersonagens->executar();
                listaObstaculos->executar();

                //verifica colisão
                pColisao->executar();
            } else {
                observadorFase->notificarJogadorMorreu();
            }
        }

    }

}