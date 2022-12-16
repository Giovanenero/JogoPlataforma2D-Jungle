#include "..\..\include\Estado\EstadoMenuPrincipal.hpp"

namespace Jungle {

    namespace Estado {

        EstadoMenuPrincipal::EstadoMenuPrincipal():
            Estado(IDs::IDs::estado_menu_principal), menuPrincipal()
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