#include "..\..\include\Observador\ObservadorMenuOpcao.hpp"
#include "..\..\include\Gerenciador\GerenciadorEstado.hpp"

namespace Jungle {

    namespace Observador {

        ObservadorMenuOpcao::ObservadorMenuOpcao(Menu::MenuOpcao* menuOpcao):
            Observador(), menuOpcao(menuOpcao)
        {

        }

        ObservadorMenuOpcao::~ObservadorMenuOpcao(){

        }

        void ObservadorMenuOpcao::teclaPressionada(const sf::Keyboard::Key tecla){
            switch (tecla)
            {
                case (sf::Keyboard::Left):
                {
                    menuOpcao->alterarVolume(false);
                }
                    break;
                case (sf::Keyboard::Right):
                {   
                    menuOpcao->alterarVolume(true);
                }
                    break;
                case (sf::Keyboard::Enter):
                {
                    if(menuOpcao->getIDBotaoSelecionado() == IDs::IDs::botao_voltar){
                        pGEstado->removerEstado();
                    }
                }
            }
        }

        void ObservadorMenuOpcao::teclaSolta(const sf::Keyboard::Key tecla){
            switch (tecla)
            {
                case (sf::Keyboard::Up):
                {
                    menuOpcao->selecionaCima();
                }
                    break;
                case (sf::Keyboard::Down):
                {
                    menuOpcao->selecionaBaixo();
                }
                    break;
            }
        }

        void ObservadorMenuOpcao::moveMouse(const sf::Vector2f posMouse){
            menuOpcao->eventoMouse(posMouse);
        }  

        void ObservadorMenuOpcao::botaoMouseSolta(const sf::Mouse::Button botaoMouse){
            if(menuOpcao->getMouseSelecionado()){
                switch (botaoMouse)
                {
                    case (sf::Mouse::Left):
                    {
                        switch (menuOpcao->getIDBotaoSelecionado())
                        {
                            case (IDs::IDs::botao_voltar):
                            {
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