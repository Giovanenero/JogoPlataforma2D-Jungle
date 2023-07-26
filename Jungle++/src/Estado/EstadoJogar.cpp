#include "../../include/Estado/EstadoJogar.hpp"

namespace Jungle {

    namespace Estado {

        EstadoJogar::EstadoJogar(const IDs::IDs ID):
            Estado(ID), mapFase()
        {

        }

        EstadoJogar::~EstadoJogar(){
           std::map<IDs::IDs, Fase::Fase*>::iterator it = mapFase.begin();
            while(it != mapFase.end()){
                if(it->second != nullptr){
                    delete(it->second);
                    it->second = nullptr;
                }
                it++;
            }
            mapFase.clear();
        }

        void EstadoJogar::criarFase(const std::string arquivoEntidades, std::vector<std::string> vectorInfoFase){
            if(ID == IDs::IDs::jogar_florestaBranca){
                //terminar...
            }
            /*
            if(ID == IDs::IDs::jogar_florestaBranca){
                fase = static_cast<Fase::Fase*>(new Fase::FlorestaBranca(arquivoEntidades, vectorInfoFase));
                if(fase == nullptr){
                    std::cout << "Jungle::Construtor::ConstrutorFase::nao foi possivel criar Fase Floresta Branca" << std::endl;
                    exit(1);
                }
            } else if(ID == IDs::IDs::jogar_florestaVermelha){
                //terminar... outra fase
            }
            */

        }

        void EstadoJogar::criarFase(){
            Fase::Fase* fase1 = static_cast<Fase::Fase*>(new Fase::FlorestaBranca(1));
            Fase::Fase* fase2 = static_cast<Fase::Fase*>(new Fase::FlorestaBranca(2));
            this->ID_FaseAtual = IDs::IDs::floresta_branca_parte_1;
            mapFase.insert(std::pair<IDs::IDs, Fase::Fase*>(ID_FaseAtual, fase1));
            mapFase.insert(std::pair<IDs::IDs, Fase::Fase*>(IDs::IDs::floresta_branca_parte_2, fase2));
            fase1->mudarFase();
        }

        Fase::Fase* EstadoJogar::getFase(){
            return mapFase[ID_FaseAtual];
        }

        void EstadoJogar::mudarFase(const IDs::IDs ID_Fase){
            std::map<IDs::IDs, Fase::Fase*>::iterator it = mapFase.begin();
            while(it != mapFase.end()){
                if(it->second != nullptr){
                    if(it->first == ID_Fase){
                        this->ID_FaseAtual = ID_Fase;
                        mapFase[ID_FaseAtual]->mudarFase();
                        break;
                    }
                }
                it++;
            }
        }

        void EstadoJogar::mudarEstadoObservador(){
            //desativa o observador do jogador
            Fase::Fase* fase = mapFase[ID_FaseAtual];
            Entidade::Personagem::Jogador::Jogador* jogador = fase->getJogador();
            if(jogador){
                fase->getJogador()->mudarEstadoObservador();
            }

            //desativa o observador da fase
            fase->mudarEstadoObservador();
        }

         void EstadoJogar::executar(){
            mapFase[ID_FaseAtual]->executar();
        }

    }

}