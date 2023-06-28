#include "..\..\include\Estado\EstadoMenuColocacao.hpp"

namespace Jungle {

    namespace Estado {

        EstadoMenuColocacao::EstadoMenuColocacao():
            Estado(IDs::IDs::estado_menu_colocacao)
        {

        }

        EstadoMenuColocacao::~EstadoMenuColocacao(){

        }

        void EstadoMenuColocacao::mudarEstadoObservador(){

        }

        void EstadoMenuColocacao::executar(){
            menuColocacao.executar();
        }

    }

}