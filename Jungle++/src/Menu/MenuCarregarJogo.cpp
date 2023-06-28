#include "./../../include/Menu/MenuCarregarJogo.hpp"

namespace Jungle {

    namespace Menu {

        MenuCarregarJogo::MenuCarregarJogo():
            Menu(IDs::IDs::menu_carregar_jogo, sf::Vector2f(TAMANHO_BOTAO_MENU_PERFIL_X, TAMANHO_BOTAO_MENU_PERFIL_Y), "SELECIONAR PERFIL", 80),
            fundo(IDs::IDs::fundo_florestaNegra), arquivo(), listaCards(), setas(),
            painelPerfil(sf::Vector2f(tamJanela.x - tamJanela.x / 4, tamJanela.y  - tamJanela.y / 2))
        {
            titulo.setPos(sf::Vector2f(tamJanela.x / 2.0f - titulo.getTam().x / 2.0f, 25.0f));
            titulo.setCorTexto(sf::Color{0,200,0});
            painelPerfil.setFillColor(sf::Color(0, 0, 0));
            painelPerfil.setOutlineThickness(5);
            painelPerfil.setOutlineColor(sf::Color(100, 100, 100));
            painelPerfil.setPosition(
                tamJanela.x / 2 - painelPerfil.getSize().x / 2 ,
                tamJanela.y / 2 - painelPerfil.getSize().y / 2
            );
            criarFundo();
            criarBotoes();
            inicializarSetas();
            inicializarCards();
        }

        MenuCarregarJogo::~MenuCarregarJogo(){
            for(int i = 0; i < setas.size(); i++){
                Botao::Botao* botao = setas[i];
                if(botao){
                    delete(botao);
                    botao = nullptr;
                }
            }
        }

        void MenuCarregarJogo::criarFundo(){
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada1.png", 0.0f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada2.png", 0.05f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada3.png", 0.1f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada4.png", 0.15f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada5.png", 0.2f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada6.png", 0.4f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada7.png", 0.6f);
        }

        void MenuCarregarJogo::criarBotoes(){
            const float posBotaoX = tamJanela.x / 2.0f - tamBotao.x / 2.0f;
            addBotao("Novo Jogo", sf::Vector2f(posBotaoX, tamJanela.y / 2.0f + tamBotao.y * 3.2f), IDs::IDs::botao_voltar, sf::Color{0, 255, 0});
            addBotao("Voltar", sf::Vector2f(posBotaoX, tamJanela.y / 2.0f + tamBotao.y * 4.4f), IDs::IDs::botao_voltar, sf::Color{0, 255, 0});
            inicializarIterator();
        }

        void MenuCarregarJogo::inicializarSetas(){
            sf::Vector2f pos(tamJanela.x / 2 + tamJanela.x / 3 - TAMANHO_SETA / 2 - 20, tamJanela.y / 2 - TAMANHO_SETA / 2);
            const sf::Vector2f tam(TAMANHO_SETA, TAMANHO_SETA);
            Botao::Botao* botao1 = new Botao::Botao(tam, pos, IDs::IDs::botao_direita, TEMPO_TROCA_ANIMACAO_BOTAO, sf::Vector2f(tam.x + 15.0f, tam.y + 15.0f));
            pos = sf::Vector2f(tamJanela.x / 2 - tamJanela.x / 3 - TAMANHO_SETA / 2, pos.y);
            Botao::Botao* botao2 = new Botao::Botao(tam, pos, IDs::IDs::botao_esquerda, TEMPO_TROCA_ANIMACAO_BOTAO, sf::Vector2f(tam.x + 15.0f, tam.y + 15.0f));
            sf::Texture* texturaDireita = new sf::Texture();
            sf::Texture* texturaEsquerda = new sf::Texture();
            texturaDireita->loadFromFile("Jungle++/img/Menu/setaDireita.png");
            texturaEsquerda->loadFromFile("Jungle++/img/Menu/setaEsquerda.png");
            botao1->setTextura(texturaDireita);
            botao2->setTextura(texturaEsquerda);
            setas.push_back(botao1);
            setas.push_back(botao2);
        }

        void MenuCarregarJogo::inicializarCards(){
            arquivo.open(CAMINHO_ARQUIVO_CARREGAR_JOGO);
            if(!arquivo.is_open()){
                std::cerr << "ERRO: leitura de arquivo " << CAMINHO_ARQUIVO_CARREGAR_JOGO << std::endl;
                exit(1);
            }
            std::string linha;
            std::string espaco = " ";
            while(std::getline(arquivo, linha)){
                std::vector<std::string> palavras;
                size_t pos = 0;
                try {
                    while((pos = linha.find(espaco)) != std::string::npos){
                        palavras.push_back(linha.substr(0, pos));
                        linha.erase(0, pos + espaco.length());
                    }
                    if(palavras.size() != QUANTIDADE_PARAMETRO_CARD){
                        throw("ERRO: Perfil corrompido");
                    }
                } catch(const char* e) {
                    std::cerr << e << std::endl;
                    //listaCards.push_back(new Card("Corrompido"));
                }
            }
            //inicializa o iterador da lista de cards
            listaCards.push_front(new Card
                (
                    "teste", 
                    sf::Vector2f(painelPerfil.getSize()), 
                    sf::Vector2f(painelPerfil.getPosition()),
                    "Jungle++/img/Captura/print.png"
                )
            );

            listaCards.push_front(new Card
                (
                    "teste", 
                    sf::Vector2f(painelPerfil.getSize()), 
                    sf::Vector2f(painelPerfil.getPosition())
                )
            );
            iteratorCard = listaCards.begin();
            arquivo.close();
        }

        void MenuCarregarJogo::mudarEstadoObservador(){
            
        }

        void MenuCarregarJogo::selecionaEsquerda(){
            Card* card = *iteratorCard;
            //card->setSelecionado(false);
            iteratorCard++;
            if(iteratorCard == listaCards.end()){
                iteratorCard = listaCards.begin();
            }
            card = *iteratorCard;
            //botao->setSelecionado(true);
        }

        void MenuCarregarJogo::selecionaDireita(){
            Card* card = *iteratorCard;
            //card->setSelecionado(false);
            if(iteratorCard == listaCards.begin()){
                iteratorCard = listaCards.end();
            }
            iteratorCard--;
            card = *iteratorCard;
        }

        void MenuCarregarJogo::executarCards(){
            std::list<Card*>::iterator aux;
            for(aux = listaCards.begin(); aux != listaCards.end(); aux++){
                Card* card = *aux;
                card->executar();
            }
        }

        void MenuCarregarJogo::executarSetas(){
            const float tempo = pGrafico->getTempo();
            Botao::Botao* botao = nullptr;
            //seta da direita
            if(iteratorCard != listaCards.begin()){
                botao = setas[1];
                botao->atualizarAnimacao();
                botao->desenhar();
            }
            //seta da esquerda
            if(iteratorCard != listaCards.end() && listaCards.size() != 1){
                botao = setas[0];
                botao->atualizarAnimacao();
                botao->desenhar();
            }
        }

        void MenuCarregarJogo::executar(){
            //atualiza o fundo - efeito parallax
            posFundo = sf::Vector2f(posFundo.x + 0.05f, posFundo.y);
            pGrafico->atualizarCamera(sf::Vector2f(posFundo.x + tamJanela.x / 2.0f, posFundo.y + tamJanela.y / 2.0f));
            fundo.executar();
            pGrafico->resetarJanela();
            
            //desenha título, painel, botões e cards, além de atualizar a animação das setas
            pGrafico->desenhaElemento(titulo.getTexto());
            pGrafico->desenhaElemento(painelPerfil);
            desenhar();
            executarCards();
            executarSetas();
        }

    }

}

namespace Jungle {

    namespace Menu {

        MenuCarregarJogo::Card::Card(const char* tipo, const sf::Vector2f tam, const sf::Vector2f pos, const char* caminhoTextura):
            corpo(tam)
        {
            corpo.setPosition(pos);
            if(caminhoTextura != ""){
                textura = pGrafico->carregarTextura(caminhoTextura);
                corpo.setTexture(&textura);
            } else {
                corpo.setFillColor(sf::Color::Black);
            }
            if(tipo == "corrompido"){
                //terminar
            }
        }

        MenuCarregarJogo::Card::~Card(){

        }

        void MenuCarregarJogo::Card::desenhar() const{

        }

        void MenuCarregarJogo::Card::executar(){
            pGrafico->desenhaElemento(corpo);
        }

    }

}