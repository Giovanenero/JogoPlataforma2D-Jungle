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

        void EstadoJogar::mudarEstadoObservador(){
            fase->getJogador()->mudarEstadoObservador();
        }

         void EstadoJogar::executar(){
            fase->executar();
        }

    }

}