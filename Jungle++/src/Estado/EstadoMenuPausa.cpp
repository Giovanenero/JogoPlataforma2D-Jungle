#include "..\..\include\Estado\EstadoMenuPausa.hpp"
//#include "..\..\include\Estado\EstadoJogar.hpp"
#include "..\..\include\Gerenciador\GerenciadorEstado.hpp"

namespace Jungle {

    Gerenciador::GerenciadorEstado* Estado::EstadoMenuPausa::pGEstado = Gerenciador::GerenciadorEstado::getGerenciadorEstado();

    namespace Estado {

        EstadoMenuPausa::EstadoMenuPausa():
            Estado(IDs::IDs::estado_menu_pausa), estadoJogar(nullptr), menuPausa()
        {
            Estado* estadoAtual = pGEstado->getEstadoAtual();
            if(estadoAtual->getID() != IDs::IDs::jogar_florestaBranca && estadoAtual->getID() != IDs::IDs::jogar_florestaVermelha){
                std::cout << "ERRO::Estado::EstadoMenuPausa::Estado atual não é uma fase!" << std::endl;
                exit(1);
            }
            estadoJogar = static_cast<EstadoJogar*>(estadoAtual);
            menuPausa.setFase(estadoJogar->getFase());
        }

        EstadoMenuPausa::~EstadoMenuPausa(){
            
        }

        void EstadoMenuPausa::mudarEstadoObservador(){
            menuPausa.mudarEstadoObservador();
        }

        void EstadoMenuPausa::executar(){
            menuPausa.executar();
        }

    }

}