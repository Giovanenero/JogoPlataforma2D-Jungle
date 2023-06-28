#include "../../include/Estado/EstadoMenuCarregarJogo.hpp"

namespace Jungle {

    namespace Estado {

        EstadoMenuCarregarJogo::EstadoMenuCarregarJogo():
            Estado(IDs::IDs::estado_menu_carregar_jogo), menuCarregarJogo()
        {

        }

        EstadoMenuCarregarJogo::~EstadoMenuCarregarJogo(){

        }

        void EstadoMenuCarregarJogo::mudarEstadoObservador(){
            menuCarregarJogo.mudarEstadoObservador();
        }

        void EstadoMenuCarregarJogo::executar(){
            menuCarregarJogo.executar();
        }

    }

}