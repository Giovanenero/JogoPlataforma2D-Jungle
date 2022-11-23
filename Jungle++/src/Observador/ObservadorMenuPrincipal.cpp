#include "..\..\include\Observador\ObservadorMenuPrincipal.hpp"
#include "..\..\include\Menu\MenuPrincipal.hpp"

namespace Jungle {

    namespace Observador {

        ObservadorMenuPrincipal::ObservadorMenuPrincipal(Menu::MenuPrincipal* menuPrincipal):
            Observador(), menuPrincipal(menuPrincipal)
        {

        }

        ObservadorMenuPrincipal::~ObservadorMenuPrincipal(){
            removerObservador();
        }
        
        void ObservadorMenuPrincipal::teclaPressionada(const sf::Keyboard::Key tecla){
            switch (tecla)
            {
                case (sf::Keyboard::Enter):
                {
                    //terminar...
                }
                    break;
            }
        }
        
        void ObservadorMenuPrincipal::teclaSolta(const sf::Keyboard::Key tecla){
            switch (tecla)
            {
                case (sf::Keyboard::Up):
                {
                    menuPrincipal->selecionaCima();
                }
                    break;
                case (sf::Keyboard::Down):
                {
                    menuPrincipal->selecionaBaixo();
                }
                    break;
            }
        }
    }

}