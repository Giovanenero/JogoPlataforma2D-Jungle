#include "../../include/Menu/MenuPerfil.hpp"

namespace Jungle {

    namespace Menu {

        MenuPerfil::MenuPerfil():
            Menu(IDs::IDs::menu_perfil, sf::Vector2f(TAMANHO_BOTAO_MENU_PERFIL_X, TAMANHO_BOTAO_MENU_PERFIL_Y), "SELECIONAR PERFIL", 100),
            fundo(IDs::IDs::fundo_florestaNegra)
        {
            criarFundo();
            criarBotoes();
        }

        MenuPerfil::~MenuPerfil(){

        }

        void MenuPerfil::criarFundo(){
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada1.png", 0.0f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada2.png", 0.05f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada3.png", 0.1f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada4.png", 0.15f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada5.png", 0.2f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada6.png", 0.4f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada7.png", 0.6f);
        }

        void MenuPerfil::criarBotoes(){
            const float posBotaoX = tamJanela.x / 2.0f - tamBotao.x / 2.0f;
            addBotao("Voltar", sf::Vector2f(posBotaoX, tamJanela.y / 2.0f + tamBotao.y * 4.8f), IDs::IDs::botao_voltar, sf::Color{0, 255, 0});
            inicializarIterator();
        }

        void MenuPerfil::mudarEstadoObservador(){
            
        }

        void MenuPerfil::executar(){
            posFundo = sf::Vector2f(posFundo.x + 0.05f, posFundo.y);
            pGrafico->atualizarCamera(sf::Vector2f(posFundo.x + tamJanela.x / 2.0f, posFundo.y + tamJanela.y / 2.0f));
            fundo.executar();
            pGrafico->resetarJanela();

            //desenha todos os botões
            desenhar();
        }

    }

}