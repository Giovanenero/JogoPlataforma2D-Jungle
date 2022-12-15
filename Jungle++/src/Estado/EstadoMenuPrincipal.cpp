#include "..\..\include\Estado\EstadoMenuPrincipal.hpp"

namespace Jungle {

    namespace Estado {

        EstadoMenuPrincipal::EstadoMenuPrincipal(const IDs::IDs ID):
            Estado(ID), menuPrincipal()
        {

        }

        EstadoMenuPrincipal::~EstadoMenuPrincipal(){

        }

        void EstadoMenuPrincipal::mudarEstadoObservador(){
            menuPrincipal.mudarEstadoObservador();
        }

        void EstadoMenuPrincipal::executar(){
            menuPrincipal.executar();
        }

    }
    
}