#include "../../include/Estado/EstadoMenu.hpp"
#include "../../include/Menu/MenuPausa.hpp"
#include "../../include/Menu/MenuCarregarJogo.hpp"
#include "../../include/Menu/MenuColocacao.hpp"
#include "../../include/Menu/MenuGameOver.hpp"
#include "../../include/Menu/MenuOpcaoPrincipal.hpp"
#include "../../include/Menu/MenuPrincipal.hpp"
#include "../../include/Menu/MenuSalvarJogada.hpp"
#include "../../include/Gerenciador/GerenciadorEstado.hpp"

namespace Jungle {

    namespace Estado {

        Gerenciador::GerenciadorEstado* EstadoMenu::pGEstado = Gerenciador::GerenciadorEstado::getGerenciadorEstado();

        EstadoMenu::EstadoMenu(const IDs::IDs ID):
            Estado(ID), menu(nullptr)
        {
            criarMenu();
        }
        
        EstadoMenu::~EstadoMenu(){
            if(menu){
                delete(menu);
                menu = nullptr;
            }
        }
        
        void EstadoMenu::mudarEstadoObservador(){
            menu->mudarEstadoObservador();
        }
        
        Fase::Fase* EstadoMenu::getFase(){
            if(
                ID == IDs::IDs::estado_menu_game_over ||
                ID == IDs::IDs::estado_menu_pausa ||
                ID == IDs::IDs::estado_menu_salvar_jogada
            ){
                Menu::MenuPausa* menuFase = dynamic_cast<Menu::MenuPausa*>(menu);
                return menuFase->getFase();
            }
            return nullptr;
        }

        Menu::Menu* EstadoMenu::getMenu(){
            return menu;
        }

        void EstadoMenu::criarMenu(){
            Estado* estadoAtual = pGEstado->getEstadoAtual();
            Fase::Fase* fase = nullptr;
            if(estadoAtual != nullptr){
                if(estadoAtual->getID() == IDs::IDs::jogar_florestaBranca || estadoAtual->getID() == IDs::IDs::jogar_florestaVermelha){
                    EstadoJogar* estadoJogar = static_cast<EstadoJogar*>(estadoAtual);
                    fase = estadoJogar->getFase();
                } else if(estadoAtual->getID() == IDs::IDs::estado_menu_pausa){
                    EstadoMenu* estadoMenu = static_cast<EstadoMenu*>(estadoAtual);
                    fase = estadoMenu->getFase();
                }
            }
            switch (ID)
            {
                case (IDs::IDs::estado_menu_principal):
                {
                    Menu::MenuPrincipal* menuPrincipal = new Menu::MenuPrincipal();
                    if(menuPrincipal == nullptr){
                        std::cout << "EstadoMenu::nao foi possivel criar menu principal" << std::endl;
                        exit(1);
                    }
                    menuPrincipal->criarBotoes();
                    menu = static_cast<Menu::Menu*>(menuPrincipal);
                }
                    break;
                case (IDs::IDs::estado_menu_pausa):
                {
                    if(fase == nullptr){
                        std::cout << "ERRO::EstadoMenuFase::nao foi possivel ter o ponteiro da fase" << std::endl;
                        exit(1);
                    }
                    Menu::MenuPausa* menuPausa = new Menu::MenuPausa(fase);
                    if(menuPausa == nullptr){
                        std::cout << "EstadoMenu::nao foi possivel criar menu pausa" << std::endl;
                        exit(1);
                    }
                    menuPausa->criarBotoes();
                    menu = static_cast<Menu::Menu*>(menuPausa);
                }
                    break;
                case (IDs::IDs::estado_menu_carregar_jogo):
                {
                    Menu::MenuCarregarJogo* menuCarregarJogo = new Menu::MenuCarregarJogo();
                    if(menuCarregarJogo == nullptr){
                        std::cout << "EstadoMenu::nao foi possivel criar menu carregar jogo" << std::endl;
                        exit(1);
                    }
                    menuCarregarJogo->criarBotoes();
                    menu = static_cast<Menu::Menu*>(menuCarregarJogo);
                }
                    break;
                case (IDs::IDs::estado_menu_colocacao):
                {
                    Menu::MenuColocacao* menuColocacao = new Menu::MenuColocacao();
                    if(menuColocacao == nullptr){
                        std::cout << "EstadoMenu::nao foi possivel criar menu colocacao" << std::endl;
                        exit(1);
                    }
                    menuColocacao->criarBotoes();
                    menu = static_cast<Menu::Menu*>(menuColocacao);
                }
                    break;
                case (IDs::IDs::estado_menu_opcaoPrincipal):
                {
                    Menu::MenuOpcaoPrincipal* menuOpcao = new Menu::MenuOpcaoPrincipal();
                    if(menuOpcao == nullptr){
                        std::cout << "EstadoMenu::nao foi possivel criar menu opcao principal" << std::endl;
                        exit(1);
                    }
                    menuOpcao->criarBotoes();
                    menu = static_cast<Menu::Menu*>(menuOpcao);
                }
                    break;
                case (IDs::IDs::estado_menu_salvar_jogada):
                {
                    if(fase == nullptr){
                        std::cout << "ERRO::EstadoMenuFase::nao foi possivel ter o ponteiro da fase" << std::endl;
                        exit(1);
                    }
                    Menu::MenuSalvarJogada* menuSalvarJogada = new Menu::MenuSalvarJogada(fase);
                    if(menuSalvarJogada == nullptr){
                        std::cout << "EstadoMenu::nao foi possivel criar menu salvar jogada" << std::endl;
                        exit(1);
                    }
                    menuSalvarJogada->criarBotoes();
                    menu = static_cast<Menu::Menu*>(menuSalvarJogada);
                }
                    break;
                case (IDs::IDs::estado_menu_game_over):
                {
                    if(fase == nullptr){
                        std::cout << "ERRO::EstadoMenuFase::nao foi possivel ter o ponteiro da fase" << std::endl;
                        exit(1);
                    }
                    Menu::MenuGameOver* menuGameOver = new Menu::MenuGameOver(fase);
                    if(menuGameOver == nullptr){
                        std::cout << "EstadoMenu::nao foi possivel criar menu salvar jogada" << std::endl;
                        exit(1);
                    }
                    menuGameOver->criarBotoes();
                    menu = static_cast<Menu::Menu*>(menuGameOver);
                }
                    break;
            }
        }

        void EstadoMenu::executar(){
            menu->executar();
        }

    }

}