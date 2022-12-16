#include "..\..\include\Estado\EstadoJogar.hpp"

namespace Jungle {

    namespace Estado {

        EstadoJogar::EstadoJogar(const IDs::IDs ID, Fase::Fase* fase):
            Estado(ID), fase(fase)
        {

        }

        EstadoJogar::~EstadoJogar(){
            if(fase){
                delete(fase);
                fase = nullptr;
            }
        }

        Fase::Fase* EstadoJogar::getFase(){
            return fase;
        }

        void EstadoJogar::mudarEstadoObservador(){
            //desativa o observador do jogador
            fase->getJogador()->mudarEstadoObservador();

            //desativa o observador da fase
            fase->mudarEstadoObservador();
        }

         void EstadoJogar::executar(){
            fase->executar();
        }

    }

}