#include "..\..\include\Menu\MenuPrincipal.hpp"

namespace Jungle {

    namespace Menu {

        MenuPrincipal::MenuPrincipal():
            Menu(IDs::IDs::menu_principal), sair(false)
        {
            criarFundo();
            //criarBotoes();
        }

        MenuPrincipal::~MenuPrincipal(){

        }

        void MenuPrincipal::criarFundo(){
            textura = pGrafico->carregarTextura(CAMINHO_TEXTURA_MENU_PRINCIPAL);
            fundo.setTexture(&textura);
        }

        void MenuPrincipal::criarBotoes(){
            addBotao("Novo Jogo");
            addBotao("Carregar Jogo");
            addBotao("Colocacao");
            addBotao("Opcao");
            addBotao("Sair");
        }

        void MenuPrincipal::setSair(const bool sair){
            this->sair = sair;
        }

        const bool MenuPrincipal::getSair() const{
            return sair;
        }

        void MenuPrincipal::executar(){
            //atualizar();
            desenhar();
        }

    }

}