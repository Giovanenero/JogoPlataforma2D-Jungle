#include "../../include/Estado/EstadoJogar.hpp"

namespace Jungle {

    namespace Estado {

        EstadoJogar::EstadoJogar(const IDs::IDs ID):
            Estado(ID), fase(nullptr)
        {

        }

        EstadoJogar::~EstadoJogar(){
            if(fase != nullptr){
                delete(fase);
                fase = nullptr;
            }
        }

        void EstadoJogar::criarFase(const std::string arquivoEntidades, std::vector<std::string> vectorInfoFase){
            if(ID == IDs::IDs::jogar_florestaBranca){
                fase = static_cast<Fase::Fase*>(new Fase::FlorestaBranca(arquivoEntidades, vectorInfoFase));
                if(fase == nullptr){
                    std::cout << "Jungle::Construtor::ConstrutorFase::nao foi possivel criar Fase Floresta Branca" << std::endl;
                    exit(1);
                }
            } else if(ID == IDs::IDs::jogar_florestaVermelha){
                //terminar... outra fase
            }

        }

        Fase::Fase* EstadoJogar::getFase(){
            return fase;
        }

        void EstadoJogar::mudarEstadoObservador(){
            //desativa o observador do jogador
            Entidade::Personagem::Jogador::Jogador* jogador = fase->getJogador();
            if(jogador){
                fase->getJogador()->mudarEstadoObservador();
            }

            //desativa o observador da fase
            fase->mudarEstadoObservador();
        }

         void EstadoJogar::executar(){
            fase->executar();
        }

    }

}