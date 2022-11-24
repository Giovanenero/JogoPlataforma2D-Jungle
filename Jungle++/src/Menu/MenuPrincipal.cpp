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
            addBotao("Novo Jogo", sf::Vector2f(posBotaoX, tamJanela.y / 2.0f), IDs::IDs::botao_novoJogo);
            addBotao("Carregar Jogo", sf::Vector2f(posBotaoX, tamJanela.y / 2.0f + tamBotao.y * 1.2f), IDs::IDs::botao_carregarJogo);
            addBotao("Colocacao", sf::Vector2f(posBotaoX, tamJanela.y / 2.0f + tamBotao.y * 2.4f), IDs::IDs::botao_colocacao);
            addBotao("Opcao", sf::Vector2f(posBotaoX, tamJanela.y / 2.0f + tamBotao.y * 3.6f), IDs::IDs::botao_opcao);
            addBotao("Sair", sf::Vector2f(posBotaoX, tamJanela.y / 2.0f + tamBotao.y * 4.8f), IDs::IDs::botao_sair);
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

        const IDs::IDs MenuPrincipal::getIDBotaoSelecionado(){
            std::list<Botao::Botao*>::iterator aux;
            for(aux = listaBotao.begin(); aux != listaBotao.end(); aux++){
                Botao::Botao* botao = *aux;
                if(botao->getSelecionado()){
                    return botao->getID();
                }
            }
            return IDs::IDs::vazio;
        }

        void MenuPrincipal::executar(){
            //pGrafico->desenhaElemento(nomeJogo.getTexto());
            desenhar();
        }

    }

}