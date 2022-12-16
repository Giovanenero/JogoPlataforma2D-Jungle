#include "..\..\include\Observador\ObservadorMenuPrincipal.hpp"
#include "..\..\include\Gerenciador\GerenciadorEstado.hpp"
#include "..\..\include\Menu\MenuPrincipal.hpp"

namespace Jungle {

    namespace Observador {

        ObservadorMenuPrincipal::ObservadorMenuPrincipal(Menu::MenuPrincipal* menuPrincipal):
            Observador(), menuPrincipal(menuPrincipal)
        {

        }

        ObservadorMenuPrincipal::~ObservadorMenuPrincipal(){
            
        }
        
        void ObservadorMenuPrincipal::teclaPressionada(const sf::Keyboard::Key tecla){
            switch (tecla)
            {
                case (sf::Keyboard::Enter):
                {
                    switch (menuPrincipal->getIDBotaoSelecionado())
                    {
                    case (IDs::IDs::botao_novoJogo):
                    {
                        pGEstado->addEstado(IDs::IDs::jogar_florestaBranca);
                    }
                        break;
                    case (IDs::IDs::botao_sair):
                    {  
                        pGEstado->removerEstado();
                    }
                        break;
                    }
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