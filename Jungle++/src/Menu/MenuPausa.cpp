#include "..\..\include\Menu\MenuPausa.hpp"

namespace Jungle {

    namespace Menu {

        MenuPausa::MenuPausa(Fase::Fase* fase): 
            Menu(IDs::IDs::menu_pausa, sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y)), fase(fase)
        {

        }

        MenuPausa::~MenuPausa(){

        }

        void MenuPausa::setFase(Fase::Fase* fase){
            this->fase = fase;
        }

        void MenuPausa::executar(){
            //somente pinta as entidades
            fase->desenhar();

            //atualiza o menu pausar
        }

    }

}