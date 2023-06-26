#include "../../include/Estado/EstadoMenuPerfil.hpp"

namespace Jungle {

    namespace Estado {

        EstadoMenuPerfil::EstadoMenuPerfil():
            Estado(IDs::IDs::estado_menu_perfil), menuPerfil()
        {

        }

        EstadoMenuPerfil::~EstadoMenuPerfil(){

        }

        void EstadoMenuPerfil::mudarEstadoObservador(){
            menuPerfil.mudarEstadoObservador();
        }

        void EstadoMenuPerfil::executar(){
            menuPerfil.executar();
        }

    }

}