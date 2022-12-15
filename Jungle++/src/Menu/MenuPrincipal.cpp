#include "..\..\include\Menu\MenuPrincipal.hpp"

namespace Jungle {

    namespace Menu {

        MenuPrincipal::MenuPrincipal():
            Menu(IDs::IDs::menu_principal, sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), IDs::IDs::fundo_florestaNegra), sair(false),
            observadorMenuPrincipal(new Observador::ObservadorMenuPrincipal(this)),
            nomeJogo(pGrafico->carregarFonte("Jungle++/fonte/menu.ttf"), "JUNGLE++", 180)
        {
            nomeJogo.setPos(sf::Vector2f(tamJanela.x / 2.0f - nomeJogo.getTam().x / 2.0f, 25.0f));
            nomeJogo.setCorTexto(sf::Color{0,200,0});
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
            //textura = pGrafico->carregarTextura(CAMINHO_TEXTURA_MENU_PRINCIPAL);
            //fundo.setTexture(&textura);
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada1.png", 0.0f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada2.png", 0.05f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada3.png", 0.1f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada4.png", 0.15f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada5.png", 0.2f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada6.png", 0.4f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada7.png", 0.6f);
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
           return (*it)->getID();
        }

        void MenuPrincipal::mudarEstadoObservador(){
            observadorMenuPrincipal->mudarEstadoAtivar();
        }

        void MenuPrincipal::executar(){
            desenhar();
            pGrafico->desenhaElemento(nomeJogo.getTexto());
        }

    }

}