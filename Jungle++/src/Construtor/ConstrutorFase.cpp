#include "..\..\include\Construtor\ConstrutorFase.hpp"

namespace Jungle {

    namespace Construtor {

        ConstrutorFase::ConstrutorFase(){

        }

        ConstrutorFase::~ConstrutorFase(){

        }

        Fase::Fase* ConstrutorFase::criarFlorestaBranca(){
            Fase::Fase* fase = static_cast<Fase::Fase*>(new Fase::FlorestaBranca());
            if(fase == nullptr){
                std::cout << "Jungle::Construtor::ConstrutorFase::nao foi possivel criar Fase Floresta Branca" << std::endl;
                exit(1);
            }
            return fase;
        }

        Fase::Fase* ConstrutorFase::criarFlorestaVermelha(){
            Fase::Fase* fase = static_cast<Fase::Fase*>(new Fase::FlorestaVermelha());
            if(fase == nullptr){
                std::cout << "Jungle::Construtor::ConstrutorFase::nao foi possivel criar Fase Floresta Vermelha" << std::endl;
                exit(1);
            }
            return fase;
        }

        Fase::Fase* ConstrutorFase::criarFase(const IDs::IDs ID){
            Fase::Fase* fase = nullptr;
            switch (ID)
            {
            case (IDs::IDs::jogar_florestaBranca):
            {
                fase = criarFlorestaBranca();
            }
                break;
            case (IDs::IDs::jogar_florestaVermelha):
            {
                fase = criarFlorestaVermelha();
            }
                break;
            default:
            {
                std::cout << "Jungle::Construtor::ConstrutorFase::ID da Fase invalido" << std::endl;
                exit(1);
            }
                break;
            }
            fase->criarFundo();
            fase->criarMapa();
            return fase;
        }

    }

}