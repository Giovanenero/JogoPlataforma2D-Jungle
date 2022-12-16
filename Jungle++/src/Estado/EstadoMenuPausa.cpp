#include "..\..\include\Estado\EstadoMenuPausa.hpp"
//#include "..\..\include\Estado\EstadoJogar.hpp"
#include "..\..\include\Gerenciador\GerenciadorEstado.hpp"

namespace Jungle {

    Gerenciador::GerenciadorEstado* Estado::EstadoMenuPausa::pGEstado = Gerenciador::GerenciadorEstado::getGerenciadorEstado();

    namespace Estado {

        EstadoMenuPausa::EstadoMenuPausa():
            Estado(IDs::IDs::estado_menu_pausa), estadoJogar(nullptr), menuPausa()
        {
            Estado* estado = pGEstado->getEstadoAtual();
            if(estado->getID() != IDs::IDs::jogar_florestaBranca || estado->getID() != IDs::IDs::jogar_florestaVermelha){
                std::cout << "ERRO::Estado::EstadoMenuPausa::Estado atual não é uma fase!" << std::endl;
                exit(1);
            }
            estadoJogar = static_cast<EstadoJogar*>(estado);
            menuPausa.setFase(estadoJogar->getFase());
        }

        EstadoMenuPausa::~EstadoMenuPausa(){

        }

        void EstadoMenuPausa::mudarEstadoObservador(){
            //terminar...
        }

        void EstadoMenuPausa::executar(){
            menuPausa.executar();
        }

    }

}