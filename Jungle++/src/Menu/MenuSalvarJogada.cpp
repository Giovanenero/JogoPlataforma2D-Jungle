#include "../../include/Menu/MenuSalvarJogada.hpp"
#include "../../include/Lista/ListaEntidade.hpp"
#include "../../include/Gerenciador/GerenciadorEstado.hpp"
#include "../../include/Fase/Fase.hpp"

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
            fase = nullptr;
        }

        void MenuSalvarJogada::inicializarCards(){
            float espaco = (tamJanela.x / 5.0f) / 5.0f;
            for(int i = 0; i < 4; i++){
                sf::Vector2f pos(sf::Vector2f(
                    posFundo.x - tamJanela.x / 2.0f + (tamJanela.x / 5.0f) * i + (espaco) * (i + 1), 
                    posFundo.y - tamJanela.y / 2.0f + 180.0f
                ));
                std::string caminhoArquivoEntidades = "Jungle++/arquivo/SalvarJogada/SalvarEntidades/salvar" + std::to_string(i + 1) + ".txt";
                std::string caminhoArquivoFase = "Jungle++/arquivo/SalvarJogada/SalvarFase/salvar" + std::to_string(i + 1) + ".txt";
                std::string caminhoImagem = "Jungle++/arquivo/SalvarJogada/SalvarImagem/salvar" + std::to_string(i + 1) + ".png";
                Card* card = new Card(pos, caminhoArquivoEntidades, caminhoArquivoFase, caminhoImagem);
                card->setColor(sf::Color(255,0,0));
                listaCards.push_back(card);
            }
            itCards = listaCards.begin();
            (*itCards)->setSelecionado(true);
        }

        void MenuSalvarJogada::salvarJogada(){
            Gerenciador::GerenciadorEstado* pGEstado = Gerenciador::GerenciadorEstado::getGerenciadorEstado();
            Estado::Estado* estado = pGEstado->getEstado(2);
            Estado::EstadoJogar* pEstadoJogadr = dynamic_cast<Estado::EstadoJogar*>(estado);
        
            std::map<IDs::IDs, Fase::Fase*> mapFase = pEstadoJogadr->getMapFase();
            const IDs::IDs ID_FaseAtual = pEstadoJogadr->getIDFaseAtual();

            std::vector<std::string> linhas = fase->salvarEntidades();
            
            const std::string caminhoArquivoEntidades = (*itCards)->getCaminhoArquivoEntidades();
            const std::string caminhoArquivoFase = (*itCards)->getCaminhoArquivoFase();
            const std::string caminhoImagem = (*itCards)->getCaminhoImage();

            gerenciadorArquivo.removeArquivo(caminhoArquivoEntidades.c_str());
            gerenciadorArquivo.removeArquivo(caminhoArquivoFase.c_str());
            gerenciadorArquivo.gravarConteudo(caminhoArquivoEntidades.c_str(), linhas);

            sf::IntRect limiteCamera = fase->getLimiteCamera();
            std::string limite = "";
            limite += ' ' + std::to_string(limiteCamera.left) + ' ';
            limite += std::to_string(limiteCamera.width) + ' ';
            limite += std::to_string(limiteCamera.top) + ' ';
            limite += std::to_string(limiteCamera.height) + ' ';

            gerenciadorArquivo.gravarConteudo(caminhoArquivoEntidades.c_str(), std::vector<std::string>{std::to_string(static_cast<int>(fase->getID())) + limite + "=========="});

            std::string linhasFase = fase->salvar();

            gerenciadorArquivo.gravarConteudo(caminhoArquivoFase.c_str(), linhasFase);

            fase->desenhar();

            //salva a imagem no card
            sf::RenderWindow* window = pGrafico->getWindow();
            sf::Texture textura;
            textura.create(window->getSize().x , window->getSize().y);
            textura.update(*(static_cast<sf::Window*>(window)));
            sf::Image imagem = textura.copyToImage();
            imagem.saveToFile(caminhoImagem);

            std::map<IDs::IDs, Fase::Fase*>::iterator itMapFase = mapFase.begin();
            while(itMapFase != mapFase.end()){
                Fase::Fase* aux = (*itMapFase).second;
                if(aux != fase && aux != nullptr){
                    linhas = aux->salvarEntidades();
                    gerenciadorArquivo.gravarConteudo(caminhoArquivoEntidades.c_str(), linhas);
                    sf::IntRect limiteCamera = aux->getLimiteCamera();
                    limite = "";
                    limite += ' ' + std::to_string(limiteCamera.left) + ' ';
                    limite += std::to_string(limiteCamera.width) + ' ';
                    limite += std::to_string(limiteCamera.top) + ' ';
                    limite += std::to_string(limiteCamera.height) + ' ';
                    gerenciadorArquivo.gravarConteudo(caminhoArquivoEntidades.c_str(), std::vector<std::string>{std::to_string(static_cast<int>(aux->getID())) + limite + "=========="});
                }
                itMapFase++;
            }
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