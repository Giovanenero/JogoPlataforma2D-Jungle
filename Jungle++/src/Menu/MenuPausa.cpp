#include "..\..\include\Menu\MenuPausa.hpp"
#include "..\..\include\Observador\ObservadorMenuPausa.hpp"

namespace Jungle {

    namespace Menu {

        MenuPausa::MenuPausa(Fase::Fase* fase): 
            Menu(IDs::IDs::menu_pausa, sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), "PAUSA", 100), fase(fase),
            observadorMenuPausa(new Observador::ObservadorMenuPausa(this)), fundoEscuro(tamJanela),
            fundoPainel(sf::Vector2f(tamJanela.x / 2.0f, tamJanela.y))
        {
            nomeMenu.setCorTexto(sf::Color{255,0,0});
            fundoEscuro.setFillColor(sf::Color{0, 0, 0, 125});
            fundoPainel.setFillColor(sf::Color{0, 0, 0, 200});
            criarBotoes();
        }

        MenuPausa::~MenuPausa(){
            if(observadorMenuPausa){
                delete(observadorMenuPausa);
                observadorMenuPausa = nullptr;
            }
        }

        void MenuPausa::criarBotoes(){
            const float posBotaoX = tamJanela.x / 2.0f - tamBotao.x / 2.0f;
            addBotao("Voltar", sf::Vector2f(posBotaoX, posFundo.y), IDs::IDs::botao_voltar, sf::Color{255, 0, 0});
            addBotao("Opacao", sf::Vector2f(posBotaoX, posFundo.y + tamBotao.y / 2.0f * 1.2f), IDs::IDs::botao_opcao, sf::Color{255, 0, 0});
            addBotao("Sair", sf::Vector2f(posBotaoX, posFundo.y + tamBotao.y / 2.0f * 2.4f), IDs::IDs::botao_sair, sf::Color{255, 0, 0});
            it = listaBotao.begin();
            (*it)->setSelecionado(true);
        }

        void MenuPausa::setFase(Fase::Fase* fase){
            this->fase = fase;
        }

        void MenuPausa::mudarEstadoObservador(){
            observadorMenuPausa->mudarEstadoAtivar();
        }

        void MenuPausa::atualizarFundo(){
            posFundo = pGrafico->getCamera().getCenter();
            sf::Vector2f posFundoEscuro = sf::Vector2f(posFundo.x - tamJanela.x / 2.0f, posFundo.y - tamJanela.y / 2.0f);
            fundoEscuro.setPosition(posFundoEscuro);
            fundoPainel.setPosition(sf::Vector2f(posFundoEscuro.x + tamJanela.x / 4.0f, posFundoEscuro.y));

            pGrafico->desenhaElemento(fundoEscuro);
            pGrafico->desenhaElemento(fundoPainel);
        }

        void MenuPausa::atualizarNomeMenu(){
            nomeMenu.setPos(sf::Vector2f(posFundo.x - nomeMenu.getTam().x / 2.0f, posFundo.y - tamJanela.y / 2.0f));

            pGrafico->desenhaElemento(nomeMenu.getTexto());
        }

        void MenuPausa::atualizarBotoes(){
            atualizarPosicaoBotoes(sf::Vector2f(posFundo.x - tamJanela.x / 5.0f, posFundo.y));

            desenhar();
        }

        void MenuPausa::executar(){
            //somente pinta as entidades
            fase->desenhar();

            //atualiza o menu pausar
            atualizarFundo();
            atualizarNomeMenu();
            atualizarBotoes();
        }

    }

}