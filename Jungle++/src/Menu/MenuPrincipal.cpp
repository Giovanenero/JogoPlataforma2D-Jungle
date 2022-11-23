#include "..\..\include\Menu\MenuPrincipal.hpp"

namespace Jungle {

    namespace Menu {

        MenuPrincipal::MenuPrincipal():
            Menu(IDs::IDs::menu_principal, sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y)), sair(false)
        {
            criarFundo();
            criarBotoes();
        }

        MenuPrincipal::~MenuPrincipal(){

        }

        void MenuPrincipal::criarFundo(){
            textura = pGrafico->carregarTextura(CAMINHO_TEXTURA_MENU_PRINCIPAL);
            fundo.setTexture(&textura);
        }

        void MenuPrincipal::criarBotoes(){
            const float posBotaoX = tamJanela.x / 2.0f - tamBotao.x / 2.0f;
            addBotao("Novo Jogo", sf::Vector2f(posBotaoX, tamJanela.y / 2.5f));
            addBotao("Carregar Jogo", sf::Vector2f(posBotaoX, tamJanela.y / 2.5f + tamBotao.y * 1.2f));
            addBotao("Colocacao", sf::Vector2f(posBotaoX, tamJanela.y / 2.5f + tamBotao.y * 2.4f));
            addBotao("Opcao", sf::Vector2f(posBotaoX, tamJanela.y / 2.5f + tamBotao.y * 3.6f));
            addBotao("Sair", sf::Vector2f(posBotaoX, tamJanela.y / 2.5f + tamBotao.y * 4.8f));

            it = listaBotao.begin();
            (*it)->setSelecionado(true);
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