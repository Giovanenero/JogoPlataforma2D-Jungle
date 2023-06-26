#include "../../include/Menu/MenuPerfil.hpp"

namespace Jungle {

    namespace Menu {

        MenuPerfil::MenuPerfil():
            Menu(IDs::IDs::menu_perfil, sf::Vector2f(TAMANHO_BOTAO_MENU_PERFIL_X, TAMANHO_BOTAO_MENU_PERFIL_Y), "SELECIONAR PERFIL", 80),
            fundo(IDs::IDs::fundo_florestaNegra), arquivo(), listaCards(),
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

        MenuPerfil::~MenuPerfil(){
            for(int i = 0; i < setas.size(); i++){
                const sf::Texture* textura = setas.at(i).getTexture();
                if(textura != nullptr){
                    delete(textura);
                    textura = nullptr;
                }
            }
        }

        void MenuPerfil::inicializarSetas(){
            sf::Texture* textura1 = new sf::Texture();
            sf::Texture* textura2 = new sf::Texture();
            sf::RectangleShape setaDireita(sf::Vector2f(TAMANHO_SETA, TAMANHO_SETA));
            if(!textura1->loadFromFile("Jungle++/img/Menu/setaDireita.png")){
                std::cout << "ERRO no caminho Jungle++/img/Menu/setaDireita.png" << std::endl;
                exit(1);
            }
            setaDireita.setPosition(tamJanela.x / 2 + tamJanela.x / 3 - setaDireita.getSize().x / 2, tamJanela.y / 2 - setaDireita.getSize().y / 2);
            setaDireita.setTexture(textura1);
            setas.push_back(setaDireita);
            sf::RectangleShape setaEsquerda(sf::Vector2f(TAMANHO_SETA, TAMANHO_SETA));
            setaEsquerda.setPosition(tamJanela.x / 2 - tamJanela.x / 3 - setaDireita.getSize().x / 2, tamJanela.y / 2 - setaDireita.getSize().y / 2);
            if(!textura2->loadFromFile("Jungle++/img/Menu/setaEsquerda.png")){
                std::cout << "ERRO no caminho Jungle++/img/Menu/setaEsquerda.png" << std::endl;
                exit(1);
            }
            setaEsquerda.setTexture(textura2);
            setas.push_back(setaEsquerda);
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
            addBotao("Novo Jogo", sf::Vector2f(posBotaoX, tamJanela.y / 2.0f + tamBotao.y * 3.2f), IDs::IDs::botao_voltar, sf::Color{0, 255, 0});
            addBotao("Voltar", sf::Vector2f(posBotaoX, tamJanela.y / 2.0f + tamBotao.y * 4.4f), IDs::IDs::botao_voltar, sf::Color{0, 255, 0});
            inicializarIterator();
        }

        void MenuPerfil::inicializarCards(){
            arquivo.open(CAMINHO_ARQUIVO);
            if(!arquivo.is_open()){
                std::cerr << "ERRO: leitura de arquivo " << CAMINHO_ARQUIVO << std::endl;
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
            listaCards.push_back(new Card
                (
                    "teste", 
                    sf::Vector2f(painelPerfil.getSize()), 
                    sf::Vector2f(painelPerfil.getPosition()),
                    "Jungle++/img/Captura/print.png"
                )
            );
            iteratorCard = listaCards.begin();
            arquivo.close();
        }

        void MenuPerfil::mudarEstadoObservador(){
            
        }

        void MenuPerfil::selecionaEsquerda(){
            Card* card = *iteratorCard;
            //card->setSelecionado(false);
            iteratorCard++;
            if(iteratorCard == listaCards.end()){
                iteratorCard = listaCards.begin();
            }
            card = *iteratorCard;
            //botao->setSelecionado(true);
        }

        void MenuPerfil::selecionaDireita(){
            Card* card = *iteratorCard;
            //card->setSelecionado(false);
            if(iteratorCard == listaCards.begin()){
                iteratorCard = listaCards.end();
            }
            iteratorCard--;
            card = *iteratorCard;
        }

        void MenuPerfil::executarCards(){
            std::list<Card*>::iterator aux;
            for(aux = listaCards.begin(); aux != listaCards.end(); aux++){
                Card* card = *aux;
                card->executar();
            }
        }

        void MenuPerfil::executarSetas(){
            for(int i = 0; i < setas.size(); i++){
                pGrafico->desenhaElemento(setas.at(i));
            }
        }

        void MenuPerfil::executar(){
            posFundo = sf::Vector2f(posFundo.x + 0.05f, posFundo.y);
            pGrafico->atualizarCamera(sf::Vector2f(posFundo.x + tamJanela.x / 2.0f, posFundo.y + tamJanela.y / 2.0f));
            fundo.executar();
            pGrafico->resetarJanela();
            
            pGrafico->desenhaElemento(titulo.getTexto());
            pGrafico->desenhaElemento(painelPerfil);
            //desenha todos os botões
            desenhar();
            executarCards();
            executarSetas();
        }

    }

}

namespace Jungle {

    namespace Menu {

        MenuPerfil::Card::Card(const char* tipo, const sf::Vector2f tam, const sf::Vector2f pos, const char* caminhoTextura):
            textura(pGrafico->carregarTextura(caminhoTextura)), corpo(tam)
        {
            corpo.setPosition(pos);
            corpo.setTexture(&textura);
            if(tipo == "corrompido"){
                //terminar
            }
        }

        MenuPerfil::Card::~Card(){

        }

        void MenuPerfil::Card::desenhar() const{

        }

        void MenuPerfil::Card::executar(){
            pGrafico->desenhaElemento(corpo);
        }

    }

}