#include "./../../include/Menu/MenuColocacao.hpp"

namespace Jungle {

    namespace Menu {

        MenuColocacao::MenuColocacao():
            MenuPrincipal(IDs::IDs::menu_colocacao, "COLOCACAO", 100),
            arquivo(), vectorTexto()
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
            std::string pontos = ".....";
            std::string novaLinha = palavras[0] + pontos;

            while(novaLinha.length() < 30){
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
            arquivo.open(CAMINHO_ARQUIVO_COLOCACAO);
            if(!arquivo.is_open()){
                std::cerr << "ERRO: leitura de arquivo " << CAMINHO_ARQUIVO_COLOCACAO << std::endl;
                exit(1);
            }
            std::string linha;
            const std::string espaco = " ";
            const int qtd = 7;
            int i = 0;
            while(std::getline(arquivo, linha) && i < qtd){
                try {
                    criarTexto(linha);
                    //vectorTexto.push_back(texto);
                } catch(const char* e) {
                    std::cerr << "MenuColocacao: "<<  e << std::endl;
                }
                i++;
            }
        }

        void MenuColocacao::criarBotoes(){
            const float posBotaoX = tamJanela.x / 2.0f - tamBotao.x / 2.0f;
            addBotao("Voltar", sf::Vector2f(posBotaoX, tamJanela.y - tamJanela.y / 12.0f), IDs::IDs::botao_voltar, sf::Color{0, 255, 0});
            inicializarIterator();
        }

        /*
        void MenuColocacao::criarFundo(){
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada1.png", 0.0f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada2.png", 0.05f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada3.png", 0.1f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada4.png", 0.15f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada5.png", 0.2f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada6.png", 0.4f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada7.png", 0.6f);
        }
        */

        void MenuColocacao::desenharColocacao(){
            for(int i = 0; i < vectorTexto.size(); i++){
                Botao::Texto* texto = vectorTexto[i];
                pGrafico->desenhaElemento(texto->getTexto());
            }
        }

        void MenuColocacao::executar(){
            //conteúdo efeito parallax
            posFundo = sf::Vector2f(posFundo.x + 0.05f, posFundo.y);
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