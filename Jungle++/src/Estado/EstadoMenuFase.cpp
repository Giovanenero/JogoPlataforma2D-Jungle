#include "../../include/Estado/EstadoMenuFase.hpp"
#include "../../include/Gerenciador/GerenciadorEstado.hpp"
#include "../../include/Menu/MenuGameOver.hpp"
#include "../../include/Menu/MenuSalvarJogada.hpp"

namespace Jungle {

    Gerenciador::GerenciadorEstado* Estado::EstadoMenuFase::pGEstado = Gerenciador::GerenciadorEstado::getGerenciadorEstado();

    namespace Estado {

        EstadoMenuFase::EstadoMenuFase(const IDs::IDs ID_Estado, const IDs::IDs ID_Menu):
            Estado(ID_Estado), fase(nullptr), menuFase(nullptr)
        {
            menuFase = criarMenu(ID_Menu);
        }

        EstadoMenuFase::~EstadoMenuFase(){
            if(menuFase){
                delete(menuFase);
                menuFase = nullptr;
            }
        }

        Fase::Fase* EstadoMenuFase::getFase(){
            return fase;
        }

        Menu::MenuPausa* EstadoMenuFase::criarMenu(const IDs::IDs ID){
            Menu::MenuPausa* menu = nullptr;
            Estado* estadoAtual = pGEstado->getEstadoAtual();
            if(estadoAtual->getID() == IDs::IDs::jogar_florestaBranca || estadoAtual->getID() == IDs::IDs::jogar_florestaVermelha){
                EstadoJogar* estadoJogar = static_cast<EstadoJogar*>(estadoAtual);
                fase = estadoJogar->getFase();
            } else if(estadoAtual->getID() == IDs::IDs::estado_menu_pausa){
                EstadoMenuFase* estadoMenuPausa = static_cast<EstadoMenuFase*>(estadoAtual);
                fase = estadoMenuPausa->getFase();
            }
            if(fase == nullptr){
                std::cout << "ERRO::EstadoMenuFase::nao foi possivel ter o ponteiro da fase" << std::endl;
                exit(1);
            }
            switch (ID)
            {
            case (IDs::IDs::menu_pausa):
            {
                menu= new Menu::MenuPausa(fase);
                if(menu == nullptr){
                    std::cout << "Jungle::EstadoMenuFase::nao foi possivel criar MenuPausa" << std::endl;
                    exit(1);
                }
                menu->criarBotoes();
            }
                break;
            case (IDs::IDs::menu_game_over):
            {
                Menu::MenuGameOver* menuGameOver = new Menu::MenuGameOver(fase->getPontuacaoJogador(), fase);
                if(menuGameOver == nullptr){
                    std::cout << "Jungle::EstadoMenuFase::nao foi possivel criar MenuGameOver" << std::endl;
                    exit(1);
                }
                menuGameOver->criarBotoes();
                menu = static_cast<Menu::MenuPausa*>(menuGameOver);
            }
                break;
            case (IDs::IDs::menu_salvar_jogada):
            {
                Menu::MenuSalvarJogada* menuSalvarJogada = new Menu::MenuSalvarJogada(fase);
                if(menuSalvarJogada == nullptr){
                    std::cout << "Jungle::EstadoMenuFase::nao foi possivel criar MenuSalvarJogada" << std::endl;
                    exit(1);
                }
                menuSalvarJogada->criarBotoes();
                menu = static_cast<Menu::MenuPausa*>(menuSalvarJogada);
            }
            }
            return menu;
        }

        void EstadoMenuFase::mudarEstadoObservador(){
            menuFase->mudarEstadoObservador();
        }

        Menu::MenuPausa* EstadoMenuFase::getMenuFase(){
            return menuFase;
        }

        void EstadoMenuFase::executar(){
            menuFase->executar();
        }

    }

}