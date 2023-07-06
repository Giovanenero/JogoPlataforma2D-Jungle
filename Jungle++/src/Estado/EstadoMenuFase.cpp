#include "../../include/Estado/EstadoMenuFase.hpp"
//#include "../../include/Estado/EstadoJogar.hpp"
#include "../../include/Gerenciador/GerenciadorEstado.hpp"
#include "../../include/Menu/MenuGameOver.hpp"

namespace Jungle {

    Gerenciador::GerenciadorEstado* Estado::EstadoMenuFase::pGEstado = Gerenciador::GerenciadorEstado::getGerenciadorEstado();

    namespace Estado {

        EstadoMenuFase::EstadoMenuFase(const IDs::IDs ID_Estado, const IDs::IDs ID_Menu):
            Estado(ID_Estado), estadoJogar(nullptr), menuFase(nullptr)
        {
            menuFase = criarMenu(ID_Menu);
        }

        EstadoMenuFase::~EstadoMenuFase(){
            if(menuFase){
                delete(menuFase);
                menuFase = nullptr;
            }
        }

        Menu::MenuPausa* EstadoMenuFase::criarMenu(const IDs::IDs ID){
            Menu::MenuPausa* menu = nullptr;
            Estado* estadoAtual = pGEstado->getEstadoAtual();
            if(estadoAtual->getID() != IDs::IDs::jogar_florestaBranca && estadoAtual->getID() != IDs::IDs::jogar_florestaVermelha){
                std::cout << "ERRO::Estado::EstadoMenuPausa::Estado atual nao é uma fase!" << std::endl;
                exit(1);
            }
            estadoJogar = static_cast<EstadoJogar*>(estadoAtual);
            Fase::Fase* fase = estadoJogar->getFase();
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