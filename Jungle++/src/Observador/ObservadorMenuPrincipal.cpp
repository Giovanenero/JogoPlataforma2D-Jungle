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
                        case (IDs::IDs::botao_opcao):
                        {
                            pGEstado->addEstado(IDs::IDs::estado_menu_opcaoPrincipal);
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

        void ObservadorMenuPrincipal::moveMouse(const sf::Vector2f posMouse){
            menuPrincipal->eventoMouse(posMouse);
        }

        void ObservadorMenuPrincipal::botaoMouseSolta(const sf::Mouse::Button botaoMouse){
            if(menuPrincipal->getMouseSelecionado()){
                switch (botaoMouse)
                {
                    case (sf::Mouse::Left):
                    {
                        switch (menuPrincipal->getIDBotaoSelecionado())
                        {
                            case (IDs::IDs::botao_novoJogo):
                            {
                                pGEstado->addEstado(IDs::IDs::estado_menu_perfil);
                                //pGEstado->addEstado(IDs::IDs::jogar_florestaBranca);
                            }
                                break;
                            case (IDs::IDs::botao_sair):
                            {  
                                pGEstado->removerEstado();
                            }
                                break;
                            case (IDs::IDs::botao_opcao):
                            {
                                pGEstado->addEstado(IDs::IDs::estado_menu_opcaoPrincipal);
                            }
                                break;
                        }
                            break;
                    }
                }
            }
        }

    }

}