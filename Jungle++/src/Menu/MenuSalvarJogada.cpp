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
            std::list<Card*>::iterator aux = listaCards.begin();
            while(aux != listaCards.end()){
                Card* card = *aux;
                if(card != nullptr){
                    delete(card);
                    card = nullptr;
                }
            }
            listaCards.clear();
        }

        void MenuSalvarJogada::inicializarCards(){
            float espaco = (tamJanela.x / 5.0f) / 5.0f;
            for(int i = 0; i < 4; i++){
                sf::Vector2f pos(sf::Vector2f(
                    posFundo.x - tamJanela.x / 2.0f + (tamJanela.x / 5.0f) * i + (espaco) * (i + 1), 
                    posFundo.y - tamJanela.y / 2.0f + 180.0f
                ));
                std::string caminhoArquivo = "Jungle++/arquivo/SalvarJogada/salvar" + std::to_string(i + 1) + ".txt";
                std::string caminhoImagem = "Jungle++/img/Captura/salvar" + std::to_string(i + 1) + ".png";
                Card* card = new Card(pos, caminhoArquivo, caminhoImagem);
                card->setColor(sf::Color(180,0,0));
                listaCards.push_back(card);
            }
            itCards = listaCards.begin();
            (*itCards)->setSelecionado(true);
        }

        void MenuSalvarJogada::salvarJogada(){
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
            
            const std::string caminhoArquivo = (*itCards)->getCaminhoArquivo();
            const std::string caminhoImagem = (*itCards)->getCaminhoImage();

            gerenciadorArquivo.removeArquivo(caminhoArquivo.c_str());
            gerenciadorArquivo.gravarConteudo(caminhoArquivo.c_str(), linhasPersonagem);
            gerenciadorArquivo.gravarConteudo(caminhoArquivo.c_str(), linhasObstaculo);

            fase->desenhar();

            //salva a imagem no card
            sf::RenderWindow* window = pGrafico->getWindow();
            sf::Texture textura;
            textura.create(window->getSize().x , window->getSize().y);
            textura.update(*(static_cast<sf::Window*>(window)));
            sf::Image imagem = textura.copyToImage();
            imagem.saveToFile(caminhoImagem);
        }

        void MenuSalvarJogada::selecionaEsquerda(){
            (*itCards)->setSelecionado(false);
            if(itCards == listaCards.begin()){
                itCards = listaCards.end();
            }
            itCards--;
            (*itCards)->setSelecionado(true);
        }

        void MenuSalvarJogada::selecionaDireita(){
            (*itCards)->setSelecionado(false);
            itCards++;
            if(itCards == listaCards.end()){
                itCards = listaCards.begin();
            }
            (*itCards)->setSelecionado(true);
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

            std::list<Card*>::iterator aux = listaCards.begin();
            while(aux != listaCards.end()){
                Card* card = *aux;
                card->desenhar();
                aux++;
            }
        }

    }

}