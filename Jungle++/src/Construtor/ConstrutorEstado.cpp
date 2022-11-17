#include "..\..\include\Construtor\ConstrutorEstado.hpp"

namespace Jungle {

    namespace Construtor {

        ConstrutorEstado::ConstrutorEstado(){

        }

        ConstrutorEstado::~ConstrutorEstado(){

        } 

        Fase::Fase* ConstrutorEstado::criarFase(const IDs::IDs ID){
            Fase::Fase* fase = nullptr;
            if(ID == IDs::IDs::jogar_florestaBranca){
                fase = static_cast<Fase::Fase*>(new Fase::FlorestaBranca());
            } else {
                fase = static_cast<Fase::Fase*>(new Fase::FlorestaVermelha());
            }
            if(fase == nullptr){
                std::cout << "Jungle::Estado::MaquinaEstado::nao foi possivel criar uma fase" << std::endl;
                exit(1);
            }
            fase->criarFundo();
            fase->criarMapa();
            return fase;
        }

        Estado::Estado* ConstrutorEstado::criarEstadoJogar(const IDs::IDs ID){
            Fase::Fase* fase = criarFase(ID);
            Estado::EstadoJogar* estadoJogar = new Estado::EstadoJogar(fase);
            if(estadoJogar == nullptr){
                std::cout << "Jungle::Estado::MaquinaEstado::nao foi possivel criar um Estado Jogar" << std::endl;
                exit(1);
            }
            return static_cast<Estado::Estado*>(estadoJogar);
        }

    }

}