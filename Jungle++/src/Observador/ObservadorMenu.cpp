#include "..\..\include\Observador\ObservadorMenu.hpp"
#include "..\..\include\Gerenciador\GerenciadorEstado.hpp"

namespace Jungle {

    namespace Observador {

        ObservadorMenu::ObservadorMenu(Menu::Menu* menu):
            Observador(), menu(menu)
        {

        }

        ObservadorMenu::~ObservadorMenu(){
            
        }
        
        void ObservadorMenu::teclaPressionada(const sf::Keyboard::Key tecla){
            if(tecladoEspecial[tecla] == "Enter"){
                switch (menu->getIDBotaoSelecionado())
                {
                    case (IDs::IDs::botao_sair):
                    {  
                        pGEstado->removerEstado(2);
                    }
                        break;
                    case (IDs::IDs::botao_voltar):
                    {
                        pGEstado->removerEstado();
                    }
                        break;
                    case (IDs::IDs::botao_novoJogo):
                    {
                        pGEstado->addEstado(IDs::IDs::jogar_florestaBranca);
                    }
                        break;
                    case (IDs::IDs::botao_opcao):
                    {
                        Estado::Estado* estado = pGEstado->getEstadoAtual();
                        if(estado->getID() == IDs::IDs::estado_menu_principal){
                            pGEstado->addEstado(IDs::IDs::estado_menu_opcaoPrincipal);
                        } else {
                            //só pode ser o menu_pausar
                        }
                    }
                        break;
                    case (IDs::IDs::botao_salvar_colocacao):
                    {
                        Estado::Estado* estado = pGEstado->getEstadoAtual();
                        if(estado->getID() == IDs::IDs::estado_menu_game_over){
                            Estado::EstadoMenuFase* estadoMenuFase = dynamic_cast<Estado::EstadoMenuFase*>(estado);
                            Menu::MenuPausa* menuFase = estadoMenuFase->getMenuFase();
                            Menu::MenuGameOver* menuGameOver = dynamic_cast<Menu::MenuGameOver*>(menuFase);
                            menuGameOver->salvarColocacao();
                        }
                        pGEstado->removerEstado(2);
                    }
                        break;
                    case (IDs::IDs::botao_colocacao):
                    {
                        //adiciona 2 vezes por conta do botao_voltar;
                        pGEstado->addEstado(IDs::IDs::estado_menu_colocacao);
                        pGEstado->addEstado(IDs::IDs::estado_menu_colocacao);
                    }
                        break;
                }
            } else if(menu->getID() == IDs::IDs::menu_opcao){
                if(tecladoEspecial[tecla] == "Left"){
                    Menu::MenuOpcaoPrincipal* menuOpcao = dynamic_cast<Menu::MenuOpcaoPrincipal*>(menu);
                    menuOpcao->alterarVolume(false);
                } else if(tecladoEspecial[tecla] == "Right"){
                    Menu::MenuOpcaoPrincipal* menuOpcao = dynamic_cast<Menu::MenuOpcaoPrincipal*>(menu);
                    menuOpcao->alterarVolume(true);
                }
            }
        }
        
        void ObservadorMenu::teclaSolta(const sf::Keyboard::Key tecla){
            if(tecladoEspecial[tecla] == "Up"){
                menu->selecionaCima();
            } else if(tecladoEspecial[tecla] == "Down"){
                menu->selecionaBaixo();
            } else if(menu->getID() == IDs::IDs::menu_game_over){
                if(tecladoEspecial[tecla] == "BackSpace"){
                    Menu::MenuGameOver* menuGameOver = dynamic_cast<Menu::MenuGameOver*>(menu);
                    menuGameOver->removerCaracter();
                } else {
                    for(int i = 97; i < 123; i++){
                        if(teclado[tecla] == i){
                            Menu::MenuGameOver* menuGameOver = dynamic_cast<Menu::MenuGameOver*>(menu);
                            menuGameOver->addCaracter(teclado[tecla]);
                            break;
                        }
                    }
                    for(int i = 48; i < 58; i++){
                        if(teclado[tecla] == i){
                            Menu::MenuGameOver* menuGameOver = dynamic_cast<Menu::MenuGameOver*>(menu);
                            menuGameOver->addCaracter(teclado[tecla]);
                            break;
                        }
                    }
                }
            }
        }

        void ObservadorMenu::moveMouse(const sf::Vector2f posMouse){
            menu->eventoMouse(posMouse);
        }

        void ObservadorMenu::botaoMouseSolta(const sf::Mouse::Button botaoMouse){
            if(menu->getMouseSelecionado()){
                switch (botaoMouse)
                {
                    case (sf::Mouse::Left):
                    {
                        switch (menu->getIDBotaoSelecionado())
                        {
                            case (IDs::IDs::botao_novoJogo):
                            {
                                //pGEstado->addEstado(IDs::IDs::estado_menu_carregar_jogo);
                                pGEstado->addEstado(IDs::IDs::jogar_florestaBranca);
                            }
                                break;
                            case (IDs::IDs::botao_sair):
                            {
                                pGEstado->removerEstado(2);
                            }
                                break;
                            case (IDs::IDs::botao_opcao):
                            {
                                pGEstado->addEstado(IDs::IDs::estado_menu_opcaoPrincipal);
                            }
                                break;
                            case (IDs::IDs::botao_colocacao):
                            {
                                pGEstado->addEstado(IDs::IDs::estado_menu_colocacao);
                            }
                                break;
                            case (IDs::IDs::botao_voltar):
                            {
                                pGEstado->removerEstado();
                            }
                                break;
                            case (IDs::IDs::botao_salvar_colocacao):
                            {
                                Estado::Estado* estado = pGEstado->getEstadoAtual();
                                if(estado->getID() == IDs::IDs::estado_menu_game_over){
                                    Estado::EstadoMenuFase* estadoMenuFase = dynamic_cast<Estado::EstadoMenuFase*>(estado);
                                    Menu::MenuPausa* menuFase = estadoMenuFase->getMenuFase();
                                    Menu::MenuGameOver* menuGameOver = dynamic_cast<Menu::MenuGameOver*>(menuFase);
                                    menuGameOver->salvarColocacao();
                                }
                                pGEstado->removerEstado(2);
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