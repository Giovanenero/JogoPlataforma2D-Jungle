#include "..\..\include\Menu\MenuOpcaoPrincipal.hpp"
#include "..\..\include\Observador\ObservadorMenuOpcao.hpp"

namespace Jungle {

    namespace Menu {

        MenuOpcaoPrincipal::MenuOpcaoPrincipal():
            MenuOpcao(), fundo(IDs::IDs::fundo_florestaNegra), observadorMenuOpcao(new Observador::ObservadorMenuOpcao(this))
        {
            titulo.setCorTexto(sf::Color{0,255,0});
            titulo.setPos(sf::Vector2f(tamJanela.x / 2.0f - titulo.getTam().x / 2.0f, 25.0f));
            criarFundo();
            criarBotoes();
        }

        MenuOpcaoPrincipal::~MenuOpcaoPrincipal(){
            if(observadorMenuOpcao){
                delete(observadorMenuOpcao);
                observadorMenuOpcao = nullptr;
            }
        }

        void MenuOpcaoPrincipal::criarBotoes(){
            addBotao("Volume Menu", sf::Vector2f(25.0f, 250.0f), IDs::IDs::botao_volume_menu, sf::Color{0,255,0}, 20.0f);
            addBotao("Volume Jogo", sf::Vector2f(25.0f, 300.0f), IDs::IDs::botao_volume_jogo, sf::Color{0,255,0}, 20.0f);
            addBotao("Volume Geral", sf::Vector2f(25.0f, 350.0f), IDs::IDs::botao_volume_geral, sf::Color{0,255,0}, 20.0f);

            Menu::addBotao("Voltar", sf::Vector2f(tamJanela.x / 2.0f - tamBotao.x / 2.0f, 450.0f), IDs::IDs::botao_voltar, sf::Color{0,255,0});
            inicializarIterator();
        }

        void MenuOpcaoPrincipal::criarFundo(){
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada1.png", 0.0f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada2.png", 0.05f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada3.png", 0.1f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada4.png", 0.15f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada5.png", 0.2f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada6.png", 0.4f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada7.png", 0.6f);
        }

        void MenuOpcaoPrincipal::executar(){
            //conteúdo do efeito Parallax
            posFundo = sf::Vector2f(posFundo.x + 0.05f, posFundo.y);
            pGrafico->atualizarCamera(sf::Vector2f(posFundo.x + tamJanela.x / 2.0f, posFundo.y + tamJanela.y / 2.0f));
            fundo.executar();
            pGrafico->resetarJanela();

            desenhar();
            pGrafico->desenhaElemento(titulo.getTexto());
        }

    }

}