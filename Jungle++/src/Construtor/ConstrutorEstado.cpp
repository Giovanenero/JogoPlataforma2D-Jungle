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

        Estado::Estado* ConstrutorEstado::criarMenuPrinciapal(const IDs::IDs ID){
            Estado::Estado* estado = static_cast<Estado::Estado*>(new Estado::EstadoMenuPrincipal(ID));
            return estado;
        }

        Estado::Estado* ConstrutorEstado::criarEstado(const IDs::IDs ID){
            if(IDs::IDs::jogar_florestaBranca == ID || IDs::IDs::jogar_florestaVermelha == ID){
                return criarEstadoJogar(ID);
            } else if(ID == IDs::IDs::estado_menu_principal){
                return criarMenuPrinciapal(ID);
            }
            return nullptr;
        }
    }

}