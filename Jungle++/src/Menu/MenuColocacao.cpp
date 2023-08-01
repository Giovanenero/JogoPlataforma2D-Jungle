#include "./../../include/Menu/MenuColocacao.hpp"

namespace Jungle {

    namespace Menu {

        MenuColocacao::MenuColocacao():
            MenuPrincipal(IDs::IDs::menu_colocacao, "COLOCACAO", 100),
            vectorTexto(), gerenciadorArquivo() //arquivo()
        {
            criarColocacao();
        }

        MenuColocacao::~MenuColocacao(){
            for(int i = 0; i < vectorTexto.size(); i++){
                Botao::Texto* texto = vectorTexto[i];
                if(texto){
                    delete(texto);
                    texto = nullptr;
                }
            }
        }

        void MenuColocacao::criarTexto(std::string linha) {
            std::string espaco = " ";
            size_t pos = 0;
            std::vector<std::string> palavras;
            while((pos = linha.find(espaco)) != std::string::npos){
                palavras.push_back(linha.substr(0, pos));
                linha.erase(0, pos + espaco.length());
            }
            std::string pontos = "....................";
            std::string novaLinha = palavras[0] + pontos;

            while(novaLinha.length() < 13){
                novaLinha += ".";
            }
            novaLinha += palavras[1];

            Botao::Texto* texto = new Botao::Texto(pGrafico->carregarFonte(CAMINHO_FONTE_COLOCACAO), novaLinha);
            texto->setTamanhoBorda(4.0f);
            const int qtdVector = vectorTexto.size();
            const float tam = texto->getTam().x;
            texto->setPos(sf::Vector2f(tamJanela.x / 2.0f - tam / 2.0f, 150.0f + 50.0f * qtdVector));
            vectorTexto.push_back(texto);
        }

        void MenuColocacao::criarColocacao(){
            std::vector<std::string> linhas = gerenciadorArquivo.lerArquivo(CAMINHO_ARQUIVO_COLOCACAO);
            for(int i = 0; i < linhas.size() && i < 7; i++){
                criarTexto(linhas.at(i));
            }
        }

        void MenuColocacao::criarBotoes(){
            addBotao("Voltar", sf::Vector2f(tamJanela.x / 2.0f - tamBotao.x / 2.0f, tamJanela.y - tamJanela.y / 12.0f), IDs::IDs::botao_voltar, sf::Color{0, 255, 0});
            inicializarIterator();
        }

        void MenuColocacao::desenharColocacao(){
            for(int i = 0; i < vectorTexto.size(); i++){
                Botao::Texto* texto = vectorTexto[i];
                pGrafico->desenhaElemento(texto->getTexto());
            }
        }

        void MenuColocacao::executar(){
            //conteúdo efeito parallax
            posFundo = sf::Vector2f(posFundo.x + pGrafico->getTempo() * 80.0f, posFundo.y);
            pGrafico->atualizarCamera(sf::Vector2f(posFundo.x + tamJanela.x / 2.0f, posFundo.y + tamJanela.y / 2.0f));
            fundo.executar();
            pGrafico->resetarJanela();

            //desenha os botões
            desenhar();

            //desenha o título
            pGrafico->desenhaElemento(titulo.getTexto());

            //desenha a colocacao
            desenharColocacao();
        }

    }

}