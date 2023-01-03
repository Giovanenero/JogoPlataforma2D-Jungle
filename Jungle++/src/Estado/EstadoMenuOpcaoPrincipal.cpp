#include "..\..\include\Estado\EstadoMenuOpcaoPrincipal.hpp"

namespace Jungle {

    namespace Estado {

        EstadoMenuOpcaoPrincipal::EstadoMenuOpcaoPrincipal():
            Estado(IDs::IDs::estado_menu_opcaoPrincipal), menuOpcaoPrincipal()
        {

        }

        EstadoMenuOpcaoPrincipal::~EstadoMenuOpcaoPrincipal(){

        }
        
        void EstadoMenuOpcaoPrincipal::mudarEstadoObservador(){
            //menuOpcaoPrincipal.mudarEstadoObservador();
        }

        void EstadoMenuOpcaoPrincipal::executar(){
            menuOpcaoPrincipal.executar();
        }

    }

}