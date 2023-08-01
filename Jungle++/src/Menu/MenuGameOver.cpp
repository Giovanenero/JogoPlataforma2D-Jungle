#include "./../../include/Menu/MenuGameOver.hpp"

namespace Jungle {

    namespace Menu {

        MenuGameOver::MenuGameOver(Fase::Fase* fase):
            MenuPausa(IDs::IDs::menu_game_over, "FIM DE JOGO", fase), fundoCaracter(),
            texto(pGrafico->carregarFonte(CAMINHO_FONTE_MENU_GAME_OVER), "", 35),
            pontuacao(pGrafico->carregarFonte(CAMINHO_FONTE_MENU_GAME_OVER), "", 35),
            gerenciadorArquivo() //arquivo()
        {
            if(fase == nullptr){
                std::cout << "MenuGameOver::Fase eh nullptr" << std::endl;
                exit(1);
            }
            std::string pontos = std::to_string(fase->getPontuacaoJogador());
            while(pontos.size() < 5){
                std::string aux = pontos;
                pontos = '0' + aux;
            }
            pontuacao.setString("Pontuacao: " + pontos);
            sf::Texture* textura = new sf::Texture();
            if(!textura->loadFromFile("Jungle++/img/Menu/caixaTexto.png")){
                std::cout << "Jungle::Menu::MenuGameOver::nao foi possivel carregar textura" << std::endl;
                exit(1);
            }
            atualizarPosicaoFundo();
            fundoCaracter.setTexture(textura);
            fundoCaracter.setSize(sf::Vector2f(350.0f, 70.0f));
            fundoEscuro.setPosition(0.0, 0.0f);
            fundoEscuro.setFillColor(sf::Color{0, 0, 0, 230});
            sf::Vector2f posFundoEscuro = sf::Vector2f(posFundo.x - tamJanela.x / 2.0f, posFundo.y - tamJanela.y / 2.0f);
            fundoEscuro.setPosition(posFundoEscuro);
            fundoCaracter.setPosition(sf::Vector2f(posFundo.x - fundoCaracter.getSize().x / 2.0f, posFundo.y - 50.0f));
            sf::Vector2f posCaixa = fundoCaracter.getPosition();
            sf::Vector2f tamCaixa = fundoCaracter.getSize();
            sf::Vector2f tamCaixaPontuacao = fundoCaracter.getSize();
            texto.setPos(sf::Vector2f(posCaixa.x + tamCaixa.x / 2.0f - texto.getTam().x / 2.0f, posCaixa.y + tamCaixa.y / 2.0f - texto.getTam().y / 2.0f - 18.0f));
            pontuacao.setPos(sf::Vector2f(posCaixa.x + tamCaixaPontuacao.x / 2.0f - pontuacao.getTam().x / 2.0f, posCaixa.y + tamCaixaPontuacao.y / 2.0f - pontuacao.getTam().y / 2.0f + 50.0f));
            titulo.setPos(sf::Vector2f(posFundo.x - titulo.getTam().x / 2.1f, posFundo.y - tamJanela.y / 2.0f));
        }

        MenuGameOver::~MenuGameOver(){
            if(fundoCaracter.getTexture()){
                delete(fundoCaracter.getTexture());
            }
        }

        void MenuGameOver::criarBotoes(){
            const float posBotaoX = tamJanela.x / 2.0f - tamBotao.x / 2.0f;
            addBotao("Salvar Colocacao", sf::Vector2f(0.0f, 0.0f), IDs::IDs::botao_salvar_colocacao, sf::Color{255, 0, 0});
            addBotao("Sair", sf::Vector2f(0.0f, 0.0f), IDs::IDs::botao_sair, sf::Color{255, 0, 0});
            posBotaoY = 0.8f;
            atualizarBotoes();
            inicializarIterator();
        }

        void MenuGameOver::ajustarTexto(){
            sf::Vector2f posCaixa = fundoCaracter.getPosition();
            sf::Vector2f tamCaixa = fundoCaracter.getSize();
            texto.setPos(sf::Vector2f(posCaixa.x + tamCaixa.x / 2.0f - texto.getTam().x / 2.0f, posCaixa.y + tamCaixa.y / 2.0f - texto.getTam().y / 2.0f - 18.0f));
        }

        void MenuGameOver::addCaracter(char caracter){
            std::string nome = texto.getString();
            if(nome.length() <= 10){
                nome += caracter;
                texto.setString(nome);
                ajustarTexto();
            }
        }

        void MenuGameOver::removerCaracter(){
            std::string nome = texto.getString();
            if(nome != ""){
                nome = nome.substr(0, nome.length() - 1);
                texto.setString(nome);
                ajustarTexto();
            }
        }

        void MenuGameOver::salvarColocacao(){
            std::string nome = texto.getString();
            if(nome == ""){
                nome = "SemNome";
            }
            std::string pontos = pontuacao.getString().substr(11, pontuacao.getString().length());
            std::string linha = nome + " " + pontos;
            gerenciadorArquivo.gravarConteudo("Jungle++/arquivo/Colocacao/colocacao.txt", linha);
        }

        void MenuGameOver::executar(){
            //desenha a fase
            fase->desenhar();

            //desenha o fundo escuro
            pGrafico->desenhaElemento(fundoEscuro);

            //atualiza a posição e desenha o titulo
            pGrafico->desenhaElemento(titulo.getTexto());

            //desenha os botões
            desenhar();

            //desenha a caixa de texto
            pGrafico->desenhaElemento(fundoCaracter);
            pGrafico->desenhaElemento(texto.getTexto());
            pGrafico->desenhaElemento(pontuacao.getTexto());
        }

    }

}