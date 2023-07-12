#include "../../include/Menu/MenuSalvarJogada.hpp"

namespace Jungle {

    namespace Menu {

        MenuSalvarJogada::MenuSalvarJogada(Fase::Fase* fase):
            MenuPausa(IDs::IDs::menu_salvar_jogada, "SALVAR JOGADA", fase)
        {
            atualizarPosicaoFundo();
            fundoEscuro.setPosition(0.0, 0.0f);
            fundoEscuro.setFillColor(sf::Color{0, 0, 0, 230});

            sf::Vector2f posFundoEscuro = sf::Vector2f(posFundo.x - tamJanela.x / 2.0f, posFundo.y - tamJanela.y / 2.0f);
            fundoEscuro.setPosition(posFundoEscuro);
            titulo.setPos(sf::Vector2f(posFundo.x - titulo.getTam().x / 2.1f, posFundo.y - tamJanela.y / 2.0f));
        }

        MenuSalvarJogada::~MenuSalvarJogada(){

        }

        void MenuSalvarJogada::inicializarCards(){

        }

        void MenuSalvarJogada::salvarJogada(){
            //terminar...
        }

        void MenuSalvarJogada::criarBotoes(){
            const float posBotaoX = tamJanela.x / 2.0f - tamBotao.x / 2.0f;
            addBotao("Salvar", sf::Vector2f(0.0f, 0.0f), IDs::IDs::botao_salvar, sf::Color{255, 0, 0});
            addBotao("Voltar", sf::Vector2f(0.0f, 0.0f), IDs::IDs::botao_voltar, sf::Color{255, 0, 0});
            posBotaoY = 0.8f;
            atualizarBotoes();

            //inicializa o iterator dos botões e não dos cards
            inicializarIterator();
        }   

        void MenuSalvarJogada::executar(){
            //desenha a fase em background
            fase->desenhar();

            //desenha o fundo escuro
            pGrafico->desenhaElemento(fundoEscuro);

            //desenha o titulo
            pGrafico->desenhaElemento(titulo.getTexto());

            //desenha os botões
            desenhar();
        }

    }

}