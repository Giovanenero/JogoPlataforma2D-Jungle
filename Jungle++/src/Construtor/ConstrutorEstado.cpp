#include "..\..\include\Construtor\ConstrutorEstado.hpp"

namespace Jungle {

    namespace Construtor {

        ConstrutorEstado::ConstrutorEstado(){

        }

        ConstrutorEstado::~ConstrutorEstado(){

        } 

        Estado::Estado* ConstrutorEstado::criarEstadoJogar(const IDs::IDs ID){
            Fase::Fase* fase = nullptr;
            Construtor::ConstrutorFase construtorFase;

            fase = construtorFase.criarFase(ID);
            
            Estado::EstadoJogar* estadoJogar = new Estado::EstadoJogar(ID, fase);
            return static_cast<Estado::Estado*>(estadoJogar);
        }

        Estado::Estado* ConstrutorEstado::criarMenuPrinciapal(){
            Estado::Estado* estado = static_cast<Estado::Estado*>(new Estado::EstadoMenuPrincipal());
            return estado;
        }

        Estado::Estado* ConstrutorEstado::criarMenuPausar(){
            Estado::Estado* estado = static_cast<Estado::Estado*>(new Estado::EstadoMenuPausa());
            return estado;
        }

        Estado::Estado* ConstrutorEstado::criarMenuOpcaoPrincipal(){
            Estado::Estado* estado = static_cast<Estado::Estado*>(new Estado::EstadoMenuOpcaoPrincipal());
            return estado;
        }

        Estado::Estado* ConstrutorEstado::criarEstadoMenuPerfil(){
            Estado::Estado* estado = static_cast<Estado::Estado*>(new Estado::EstadoMenuPerfil());
            return estado;
        }

        Estado::Estado* ConstrutorEstado::criarEstado(const IDs::IDs ID){
            Estado::Estado* estado = nullptr;
            switch (ID)
            {
                case (IDs::IDs::jogar_florestaBranca):
                {
                    estado = criarEstadoJogar(ID);
                }
                    break;
                case (IDs::IDs::jogar_florestaVermelha):
                {
                    estado = criarEstadoJogar(ID);
                }
                    break;
                case (IDs::IDs::estado_menu_principal):
                {
                    estado = criarMenuPrinciapal();
                }
                    break;
                case (IDs::IDs::estado_menu_pausa):
                {
                    estado = criarMenuPausar();
                }
                    break;
                case (IDs::IDs::estado_menu_opcaoPrincipal):
                {
                    estado = criarMenuOpcaoPrincipal();
                }
                    break;
                case(IDs::IDs::estado_menu_perfil):
                {
                    estado = criarEstadoMenuPerfil();
                }
                    break;
            }
            return estado;
        }
    }

}