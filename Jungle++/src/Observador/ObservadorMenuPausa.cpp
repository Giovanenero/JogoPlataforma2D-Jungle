#include "..\..\include\Observador\ObservadorMenuPausa.hpp"
#include "..\..\include\Gerenciador\GerenciadorEstado.hpp"

namespace Jungle {

    namespace Observador {

        ObservadorMenuPausa::ObservadorMenuPausa(Menu::MenuPausa* menuPausa):
            Observador(), menuPausa(menuPausa)
        {

        }

        ObservadorMenuPausa::~ObservadorMenuPausa(){

        }

        void ObservadorMenuPausa::teclaPressionada(const sf::Keyboard::Key tecla){
            switch (tecla)
            {
                case (sf::Keyboard::Enter):
                {
                    switch (menuPausa->getIDBotaoSelecionado())
                    {
                        case (IDs::IDs::botao_voltar):
                        {
                            pGEstado->removerEstado();
                        }
                            break;
                        case (IDs::IDs::botao_sair):
                        {   
                            pGEstado->removerEstado();
                            pGEstado->removerEstado();
                        }
                            break;
                    }
                }
                    break;
            }
        }
        
        void ObservadorMenuPausa::teclaSolta(const sf::Keyboard::Key tecla){
            switch (tecla)
            {
                case (sf::Keyboard::Up):
                {
                    menuPausa->selecionaCima();
                }
                    break;
                case (sf::Keyboard::Down):
                {
                    menuPausa->selecionaBaixo();
                }
                    break;
            }
        }

        void ObservadorMenuPausa::moveMouse(const sf::Vector2f posMouse){
            menuPausa->eventoMouse(posMouse);
        }

        void ObservadorMenuPausa::botaoMouseSolta(const sf::Mouse::Button botaoMouse){
            if(menuPausa->getMouseSelecionado()){
                switch (botaoMouse)
                {
                    case (sf::Mouse::Left):
                    {
                        switch (menuPausa->getIDBotaoSelecionado())
                        {
                            case (IDs::IDs::botao_voltar):
                            {
                                pGEstado->removerEstado();
                            }
                                break;
                            case (IDs::IDs::botao_sair):
                            {   
                                pGEstado->removerEstado();
                                pGEstado->removerEstado();
                            }
                                break;
                        }
                    }
                        break;
                }
            }
        }

    }

}