#include "../../include/Menu/MenuCarregarJogo.hpp"

namespace Jungle {

    namespace Menu {

        MenuCarregarJogo::MenuCarregarJogo():
            MenuPrincipal(IDs::IDs::menu_carregar_jogo, "CARREGAR JOGO", 100), gerenciadorArquivo()
        {
            //atualizarPosicaoFundo();
            inicializarCards();
        }

        MenuCarregarJogo::~MenuCarregarJogo(){

        }

        void MenuCarregarJogo::inicializarCards(){
            float espaco = (tamJanela.x / 5.0f) / 5.0f;
            for(int i = 0; i < 4; i++){
                sf::Vector2f pos(sf::Vector2f(
                    (tamJanela.x / 5.0f) * i + (espaco) * (i + 1), 
                    180.0f
                ));
                std::string caminhoArquivo = "Jungle++/arquivo/SalvarJogada/salvar" + std::to_string(i + 1) + ".txt";
                std::string caminhoImagem = "Jungle++/img/Captura/salvar" + std::to_string(i + 1) + ".png";
                Card* card = new Card(pos, caminhoArquivo, caminhoImagem);
                card->setColor(sf::Color(0,180,0));
                listaCards.push_back(card);
            }
            itCards = listaCards.begin();
            (*itCards)->setSelecionado(true);
        }

        void MenuCarregarJogo::selecionaEsquerda(){
            (*itCards)->setSelecionado(false);
            if(itCards == listaCards.begin()){
                itCards = listaCards.end();
            }
            itCards--;
            (*itCards)->setSelecionado(true);
        }
        
        void MenuCarregarJogo::selecionaDireita(){
            (*itCards)->setSelecionado(false);
            itCards++;
            if(itCards == listaCards.end()){
                itCards = listaCards.begin();
            }
            (*itCards)->setSelecionado(true);
        }

        void MenuCarregarJogo::criarBotoes(){
            const float posBotaoX = tamJanela.x / 2.0f - tamBotao.x / 2.0f;
            addBotao("Carregar", sf::Vector2f(posBotaoX, tamJanela.y / 2.0f + tamBotao.y * 3.6f), IDs::IDs::botao_carregar, sf::Color{0, 255, 0});
            addBotao("Voltar", sf::Vector2f(posBotaoX, tamJanela.y / 2.0f + tamBotao.y * 4.8f), IDs::IDs::botao_voltar, sf::Color{0, 255, 0});
            inicializarIterator();
        }

        void MenuCarregarJogo::executar(){
            //conteúdo do efeito Parallax
            posFundo = sf::Vector2f(posFundo.x + 0.05f, posFundo.y);
            pGrafico->atualizarCamera(sf::Vector2f(posFundo.x + tamJanela.x / 2.0f, posFundo.y + tamJanela.y / 2.0f));
            fundo.executar();
            pGrafico->resetarJanela();

            desenhar();
            pGrafico->desenhaElemento(titulo.getTexto());

            std::list<Card*>::iterator aux = listaCards.begin();
            while(aux != listaCards.end()){
                Card* card = *aux;
                card->desenhar();
                aux++;
            }
        }

    }

}