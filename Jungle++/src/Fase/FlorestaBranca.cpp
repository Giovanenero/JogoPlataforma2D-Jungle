#include "../../include/Fase/FlorestaBranca.hpp"

namespace Jungle {

    namespace Fase {

        FlorestaBranca::FlorestaBranca(const std::string arquivoEntidades, const std::vector<std::string> vectorInfoFase):
            Fase(IDs::IDs::fase_florestaBranca, IDs::IDs::fundo_florestaBranca)
        {
            criarFundo();
            if(arquivoEntidades != "" && vectorInfoFase.size() > 0){
                recuperarJogada(arquivoEntidades, vectorInfoFase);
            } else {
                criarMapa();
            }
        }

        FlorestaBranca::~FlorestaBranca(){

        }

        void FlorestaBranca::recuperarJogada(const std::string arquivoEntidades, const std::vector<std::string> vectorInfoFase){
            try {
                setPontuacao(std::stoi(vectorInfoFase[1]));
                this->textoTempo.setString(vectorInfoFase[2]);
                std::vector<std::string> linhas = GArquivo.lerArquivo(arquivoEntidades.c_str());
                int i = 2;
                Entidade::Personagem::Jogador::Jogador* pJogador = criarJogador(getAtributosEntidade(linhas[0]), getAtributosEntidade(linhas[1]));
                while(i < linhas.size()){
                    std::string linha = linhas[i];
                    int id =  std::stoi(linha.substr(0, linha.find(" ")));
                    const std::vector<std::string> atributos = getAtributosEntidade(linhas[i]);
                    switch (id)
                    {
                        case (5):
                        {
                            //criar esqueleto com espada
                            criarEsqueleto(atributos, getAtributosEntidade(linhas[i + 1]), pJogador);
                            i++;
                        }
                            break;
                        case (7):
                        {
                            //criar alma com projetil
                            criarAlma(atributos, getAtributosEntidade(linhas[i + 1]), pJogador);
                            i++;
                        }
                            break;
                        case (8):
                        {
                            //cria plataforma
                            criarPlataforma(atributos, IDs::IDs::plataforma);
                        }
                            break;
                        case (9):
                        {
                            //criar caixa
                            criarCaixa(atributos);
                        }
                            break;
                        case (10):
                        {
                            //criar moeda amarela
                            criarMoeda(atributos, IDs::IDs::moeda_amarela);
                        }
                            break;
                        case (11):
                        {
                            //criar moeda cinza
                            criarMoeda(atributos, IDs::IDs::moeda_cinza);
                        }
                            break;
                        case (12):
                        {
                            //criar vida
                            criarVida(atributos);
                        }
                            break;
                        case(50):
                        {
                            criarPlataforma(atributos, IDs::IDs::plataforma_movel);
                        }
                            break;
                    }
                    i++;
                }
            } catch(const std::exception& e) {
                std::cerr << e.what() << std::endl;
                exit(1);
            }
        }

        void FlorestaBranca::criarFundo(){
            fundo.addCamada("Jungle++/img/Fase/FlorestaBranca/camada1.png", 0.0f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaBranca/camada2.png", 0.1f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaBranca/camada3.png", 0.3f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaBranca/camada4.png", 0.5f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaBranca/camada5.png", 1.0f);
        }

        void FlorestaBranca::criarMapa(){
            for(int i = -2; i < 8; i++){
                criarPlataforma(sf::Vector2f(i * 350.0f, 550.0f), sf::Vector2f(350.0f, 50.0f), false, 0.0f, false);
            }
            criarPlataforma(sf::Vector2f(1300.0f, 290.0f), sf::Vector2f(80.0f, 40.0f), true, 0.0f, false);
            criarPlataforma(sf::Vector2f(500.0f, 420.0f), sf::Vector2f(80.0f, 40.0f), true, 800.0f, true);
            for(int i = 0; i < 4; i++){
                criarPlataforma(sf::Vector2f(1450.0f + i * 350.0f, 150.0f), sf::Vector2f(350.0f, 50.0f), false, 0.0f, false);
            }

            Entidade::Item::Chave* chave = new Entidade::Item::Chave(sf::Vector2f(200.0f, 500.0f), sf::Vector2f(50.0f, 50.0f));
            Entidade::Obstaculo::Porta* porta = new Entidade::Obstaculo::Porta(sf::Vector2f(400.0f, 450.0f), sf::Vector2f(75.0f, 100.0f), chave);
            chave->setPorta(porta);
            listaObstaculos->addEntidade(static_cast<Entidade::Entidade*>(porta));
            listaObstaculos->addEntidade(static_cast<Entidade::Entidade*>(chave));

            std::cout << "aaa ";

            Entidade::Personagem::Jogador::Jogador* pJogador = criarJogador(sf::Vector2f(100.0f, 400.0f));
            criarMoeda(sf::Vector2f(300.0f, 500.0f), IDs::IDs::moeda_amarela);
            criarMoeda(sf::Vector2f(1200.0f, 80.0f), IDs::IDs::moeda_cinza);
            criarVida(sf::Vector2f(1400.0f, 350.0f));

            for(int i = 0; i < 3; i++){
                criarEsqueleto(sf::Vector2f(400.0f * (i + 0.5f), 0.0f), 1, pJogador);
            }
            for(int i = 0; i < 3; i++){
                criarEsqueleto(sf::Vector2f(400.0f * (2 + i + 0.5f), 0.0f), 3, pJogador);
            }
            criarAlma(sf::Vector2f(200.0f, 500.0f), 2, pJogador);
            criarAlma(sf::Vector2f(500.0f, 500.0f), 4, pJogador);
        }

    }

}

