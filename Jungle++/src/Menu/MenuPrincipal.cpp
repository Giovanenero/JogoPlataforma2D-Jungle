#include "..\..\include\Menu\MenuPrincipal.hpp"

namespace Jungle {

    namespace Menu {

        MenuPrincipal::MenuPrincipal():
            Menu(IDs::IDs::menu_principal, sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y)), sair(false),
            observadorMenuPrincipal(new Observador::ObservadorMenuPrincipal(this))
        {
            if(observadorMenuPrincipal == nullptr){
                std::cout << "ERROR::Jungle::Menu::MenuPrincipal::nao foi possivel criar um Observador Menu Principal" << std::endl;
                exit(1);
            }
            criarFundo();
            criarBotoes();
            it = listaBotao.begin();
            (*it)->setSelecionado(true);
        }

        MenuPrincipal::~MenuPrincipal(){
            if(observadorMenuPrincipal){
                delete(observadorMenuPrincipal);
                observadorMenuPrincipal = nullptr;
            }
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
        }

        void MenuPrincipal::setSair(const bool sair){
            this->sair = sair;
        }

        const bool MenuPrincipal::getSair() const{
            return sair;
        }

        void MenuPrincipal::selecionaCima(){
            Botao::Botao* botao = *it;
            botao->setSelecionado(false);
            if(it == listaBotao.begin()){
                std::cout << "a ";
                it = listaBotao.end();
            }
            it--;
            botao = *it;
            botao->setSelecionado(true);
        }

        void MenuPrincipal::selecionaBaixo(){
            Botao::Botao* botao = *it;
            botao->setSelecionado(false);
            it++;
            if(it == listaBotao.end()){
                it = listaBotao.begin();
            }
            botao = *it;
            botao->setSelecionado(true);
        }

        void MenuPrincipal::executar(){
            //pGrafico->desenhaElemento(nomeJogo.getTexto());
            desenhar();
        }

    }

}