#include "../../include/Estado/EstadoMenuPrincipal.hpp"

namespace Jungle {

    namespace Estado {

        EstadoMenuPrincipal::EstadoMenuPrincipal():
            Estado(IDs::IDs::estado_menu_principal), menuPrincipal(new Menu::MenuPrincipal())
        {
            if(menuPrincipal == nullptr){
                std::cout << "Jungle::EstadoMenuPrincipal::não foi possível criar MenuPrincipal" << std::endl;
                exit(1);
            }
            menuPrincipal->criarBotoes();
        }

        EstadoMenuPrincipal::EstadoMenuPrincipal(const IDs::IDs ID_Estado, const IDs::IDs ID_Menu):
            Estado(ID_Estado), menuPrincipal(nullptr)
        {
            menuPrincipal = criarMenu(ID_Menu);
            if(menuPrincipal == nullptr){
                std::cout << "Jungle::EstadoMenuPrincipal::não foi possível criar MenuPrincipal" << std::endl;
                exit(1);
            }
            menuPrincipal->criarBotoes();
        }

        EstadoMenuPrincipal::~EstadoMenuPrincipal(){
            if(menuPrincipal){
                delete(menuPrincipal);
                menuPrincipal = nullptr;
            }
        }

        Menu::MenuPrincipal* EstadoMenuPrincipal::criarMenu(const IDs::IDs ID){
            switch (ID)
            {
            case (IDs::IDs::menu_colocacao):
            {
                menuPrincipal = static_cast<Menu::MenuPrincipal*>(new Menu::MenuColocacao());
            }
                break;
            case (IDs::IDs::menu_opcao):
            {
                menuPrincipal = static_cast<Menu::MenuPrincipal*>(new Menu::MenuOpcaoPrincipal());
            }
                break;
            }
            return menuPrincipal;
        }

        void EstadoMenuPrincipal::mudarEstadoObservador(){
            menuPrincipal->mudarEstadoObservador();
        }

        void EstadoMenuPrincipal::executar(){
            menuPrincipal->executar();
        }

    }
    
}