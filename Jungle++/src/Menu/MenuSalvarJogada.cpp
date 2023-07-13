#include "../../include/Menu/MenuSalvarJogada.hpp"
#include "../../include/Lista/ListaEntidade.hpp"

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
            
            inicializarCards();
        }

        MenuSalvarJogada::~MenuSalvarJogada(){
            std::list<sf::RectangleShape*>::iterator aux = listaCards.begin();
            while(aux != listaCards.end()){
                sf::RectangleShape* corpo = *aux;
                if(corpo != nullptr){
                    delete(corpo);
                    corpo = nullptr;
                }
            }
            listaCards.clear();
        }

        void MenuSalvarJogada::inicializarCards(){
            float espaco = (tamJanela.x / 5.0f) / 5.0f;
            for(int i = 0; i < 4; i++){
                sf::RectangleShape* corpo = new sf::RectangleShape(sf::Vector2f(tamJanela.x / 5.0f, tamJanela.x / 5.0f - 20.0f));
                //corpo.setPosition(sf::Vector2f((tamJanela.x / 5.0f) * i - posFundo.x + espaco / 2.0f, 200.0f - posFundo.y));
                corpo->setPosition(sf::Vector2f(
                    posFundo.x - tamJanela.x / 2.0f + (tamJanela.x / 5.0f) * i + (espaco) * (i + 1), 
                    posFundo.y - tamJanela.y / 2.0f + 180.0f
                ));
                corpo->setOutlineThickness(10);
                corpo->setOutlineThickness(sf::Color::Transparent);
                corpo->setFillColor(sf::Color::Green);
                listaCards.push_back(corpo);
            }
            itCards = listaCards.begin();
            sf::RectangleShape* corpo = *itCards;
            corpo->setOutlineColor(sf::Color::Blue);
        }

        void MenuSalvarJogada::salvarJogada(){
            //terminar...
            Lista::ListaEntidade* pListaPersonagem = fase->getListaPersonagem();
            Lista::ListaEntidade* pListaObstaculo = fase->getListaObstaculo();

            std::vector<std::string> linhasPersonagem;
            for(int i = 0; i < pListaPersonagem->getTam(); i++){
                Entidade::Entidade* entidade = pListaPersonagem->operator[](i);
                if(entidade != nullptr){
                    std::string linha = entidade->salvar();
                    linhasPersonagem.push_back(linha);
                }
            }

            std::vector<std::string> linhasObstaculo;
            for(int i = 0; i < pListaObstaculo->getTam(); i++){
                Entidade::Entidade* entidade = pListaObstaculo->operator[](i);
                if(entidade != nullptr){
                    std::string linha = entidade->salvar();
                    linhasObstaculo.push_back(linha);
                }
            }
            gerenciadorArquivo.gravarConteudo("Jungle++/arquivo/SalvarJogada/salvar1.txt", linhasPersonagem);
            gerenciadorArquivo.gravarConteudo("Jungle++/arquivo/SalvarJogada/salvar1.txt", linhasObstaculo);
        }

        void MenuSalvarJogada::selecionaEsquerda(){
            sf::RectangleShape* corpo = *itCards;
            corpo->setOutlineColor(sf::Color::Transparent);
            if(itCards == listaCards.begin()){
                itCards = listaCards.end();
            }
            itCards--;
            corpo = *itCards;
            corpo->setOutlineColor(sf::Color::Blue);
        }

        void MenuSalvarJogada::selecionaDireita(){
            sf::RectangleShape* corpo = *itCards;
            corpo->setOutlineColor(sf::Color::Transparent);
            itCards++;
            if(itCards == listaCards.end()){
                itCards = listaCards.begin();
            }
            corpo = *itCards;
            corpo->setOutlineThickness(10);
            corpo->setOutlineColor(sf::Color::Blue);
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

            std::list<sf::RectangleShape*>::iterator aux = listaCards.begin();
            while(aux != listaCards.end()){
                sf::RectangleShape* corpo = *aux;
                pGrafico->desenhaElemento(*corpo);
                aux++;
            }
        }

    }

}