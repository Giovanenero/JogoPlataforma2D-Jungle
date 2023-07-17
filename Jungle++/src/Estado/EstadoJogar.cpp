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

        void EstadoJogar::criarFase(const IDs::IDs ID, const char* caminhoArquivo){
            if(ID == IDs::IDs::jogar_florestaBranca){
                fase = static_cast<Fase::Fase*>(new Fase::FlorestaBranca(caminhoArquivo));
                if(fase == nullptr){
                    std::cout << "Jungle::Construtor::ConstrutorFase::nao foi possivel criar Fase Floresta Branca" << std::endl;
                    exit(1);
                }
            } else {
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