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
            if(estadoJogar == nullptr){
                std::cout << "Jungle::Estado::MaquinaEstado::nao foi possivel criar um Estado Jogar" << std::endl;
                exit(1);
            }
            return static_cast<Estado::Estado*>(estadoJogar);
        }

        Estado::Estado* ConstrutorEstado::criarEstado(const IDs::IDs ID){
            if(IDs::IDs::jogar_florestaBranca == ID || IDs::IDs::jogar_florestaVermelha == ID){
                return criarEstadoJogar(ID);
            } else {
                //criar outros estados...
                //terminar...
            }
            return nullptr;
        }

    }

}