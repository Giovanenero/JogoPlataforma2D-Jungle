#include "../../include/Fase/FlorestaBranca.hpp"

namespace Jungle {

    namespace Fase {

        FlorestaBranca::FlorestaBranca(const std::vector<std::string> vectorEntidades, const std::vector<std::string> vectorInfoFase, const IDs::IDs ID):
            Fase(ID, IDs::IDs::fundo_florestaBranca)
        {
            criarFundo();
            recuperarJogada(vectorEntidades, vectorInfoFase);
        }

        FlorestaBranca::FlorestaBranca(const IDs::IDs ID):
            Fase(ID, IDs::IDs::fundo_florestaBranca)
        {
            criarFundo();
            criarMapa(ID);
        }

        FlorestaBranca::~FlorestaBranca(){

        }

        void FlorestaBranca::recuperarJogada(const std::vector<std::string> vectorEntidades, const std::vector<std::string> vectorInfoFase){
            try {
                setPontuacao(std::stoi(vectorInfoFase[1]));
                this->textoTempo.setString(vectorInfoFase[2]);
                std::vector<std::string> linhas = vectorEntidades;
                int i = 0;
                if(pJogador == nullptr){
                    i = 2;
                    criarJogador(getAtributosEntidade(linhas[0]), getAtributosEntidade(linhas[1]));
                    pGrafico->atualizarCamera(sf::Vector2f(pJogador->getPos().x, 300.0f));
                    fundo.atualizarPosicao();
                }
                while(i < linhas.size()){
                    std::string linha = linhas[i];
                    int id =  std::stoi(linha.substr(0, linha.find(" ")));
                    const std::vector<std::string> atributos = getAtributosEntidade(linhas[i]);
                    switch (id)
                    {
                        case (5):
                        {
                            //criar esqueleto com espada
                            criarEsqueleto(atributos, getAtributosEntidade(linhas[i + 1]));
                            i++;
                        }
                            break;
                        case (7):
                        {
                            //criar alma com projetil
                            criarAlma(atributos, getAtributosEntidade(linhas[i + 1]));
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
                            //criar plataforma
                            criarPlataforma(atributos, IDs::IDs::plataforma_movel);
                        }
                            break;
                        case(51):
                        {
                            //criar porta
                            std::vector<std::string> atributosChave = {};
                            if(i + 1 < linhas.size()){
                                std::vector<std::string> atributosAux = getAtributosEntidade(linhas[i + 1]);
                                if(atributosAux[0] == "52"){
                                    atributosChave = atributosAux;
                                    i++;
                                }
                            }
                            criarPorta(atributos, atributosChave);
                        }
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

        void FlorestaBranca::criarMapa(const IDs::IDs ID_Mapa){
           switch (ID_Mapa)
           {
                case (IDs::IDs::floresta_branca_parte_1):
                {
                    criarMapa1();
                }
                    break;
                case (IDs::IDs::floresta_branca_parte_2):
                {
                    criarMapa2();
                }
                    break;
                case (IDs::IDs::floresta_branca_parte_3):
                {
                    criarMapa3();
                }
                    break;
                default:
                {
                    std::cout << "ERRO::FlorestaBranca::ID invalido" << std::endl;
                    exit(1);
                }
                    break;
           }
        }

        void FlorestaBranca::criarMapa1(){
            criarPlataforma(sf::Vector2f(-550.0f, 100.0f), sf::Vector2f(50.f, 500.0f), "parede");
            criarPorta(sf::Vector2f(-450.0f, 430.0f), sf::Vector2f(85.0f, 110.0f),sf::Vector2f(-350.0f, 510.0f), sf::Vector2f(40.0f, 40.0f), IDs::IDs::floresta_branca_parte_3);
            //chão
            for(int i = -1; i < 11; i++){
                criarPlataforma(sf::Vector2f(i * 500.0f, 550.0f), sf::Vector2f(500.0f, 50.0f), "padrao");
            }
            criarPlataforma(sf::Vector2f(11 * 500.0f, 100.0f), sf::Vector2f(50.f, 500.0f), "parede");

            //plataforma do jogador
            criarJogador(sf::Vector2f(150.0f, 300.0f));

            Obstaculo::Espinho* espinho = new Obstaculo::Espinho(sf::Vector2f(300.0f, 520.0f), sf::Vector2f(100.0f, 30.0f));
            listaObstaculos->addEntidade(static_cast<Entidade::Entidade*>(espinho));

            criarPlataforma(sf::Vector2f(0.0f, 400.0f), sf::Vector2f(250.0f, 10.0f), "madeira", sf::Vector2f(1.0f, 15.2f));
            
            criarEsqueleto(sf::Vector2f(450.0f, 450.0f), 1);
            criarCaixa(sf::Vector2f(700.0f, 500.0f));
        
            criarPlataforma(sf::Vector2f(750.0f, 400.0f), sf::Vector2f(300.0f, 10.0f), "madeira", sf::Vector2f(1.0f, 15.2f));
            criarPlataforma(sf::Vector2f(750.0f + 300.0f, 400.0f), sf::Vector2f(300.0f, 10.0f), "madeira", sf::Vector2f(1.0f, 15.2f));
            criarEsqueleto(sf::Vector2f(900.0f, 300.0f), 1);
            criarPlataforma(sf::Vector2f(1350.0f, 200.0f), sf::Vector2f(80.0f, 50.0f), 200.0f, false);

            criarPlataforma(sf::Vector2f(1350.0f + 80.0f, 200.0f), sf::Vector2f(350.0f, 50.0f), "flutuante_maior", sf::Vector2f(1.0f, 1.2f));
            criarPorta(sf::Vector2f(1600.0f, 80.0f), sf::Vector2f(85.0f, 110.0f),sf::Vector2f(4800.0, 160.0f), sf::Vector2f(40.0f, 40.0f), IDs::IDs::floresta_branca_parte_2);
            criarEsqueleto(sf::Vector2f(1700.0f, 100.0f), 4);
            criarCaixa(sf::Vector2f(2250.0f, 500.0f));

            criarPlataforma(sf::Vector2f(2350.0f, 400.0f), sf::Vector2f(300.0f, 10.0f), "madeira", sf::Vector2f(1.0f, 15.2f));
            criarEsqueleto(sf::Vector2f(2550.0f, 300.0f), 5);
            criarPlataforma(sf::Vector2f(2650.0f, 400.0f), sf::Vector2f(80.0f, 50.0f), 300.0f, true);
            criarEsqueleto(sf::Vector2f(2850.0f, 300.0f), 4);

            criarPlataforma(sf::Vector2f(3030.0f, 400.0f), sf::Vector2f(300.0f, 10.0f), "madeira", sf::Vector2f(1.0f, 15.2f));
            criarPlataforma(sf::Vector2f(3430.0f, 200.0f), sf::Vector2f(80.0f, 50.0f), 200.0f, false);
            criarEsqueleto(sf::Vector2f(3700.0f, 200.0f), 3);
            criarAlma(sf::Vector2f(3650.0f, 450.0f), 1);
            criarEsqueleto(sf::Vector2f(3850.0f, 450.0f), 3);
            criarEsqueleto(sf::Vector2f(3850.0f, 100.0f), 4);
            criarPlataforma(sf::Vector2f(3530.0f, 200.0f), sf::Vector2f(80.0f, 50.0f), 200.0f, true);
            criarPlataforma(sf::Vector2f(3830.0f, 200.0f), sf::Vector2f(350.0f, 50.0f), "flutuante_maior", sf::Vector2f(1.0f, 1.2f));
            criarPlataforma(sf::Vector2f(4230.0f, 200.0f), sf::Vector2f(80.0f, 50.0f), 200.0f, true);
            criarPlataforma(sf::Vector2f(4530.0f, 200.0f), sf::Vector2f(350.0f, 50.0f), "flutuante_maior", sf::Vector2f(1.0f, 1.2f));
        }
        
        
        void FlorestaBranca::criarMapa2(){
            for(int i = -2; i < 10; i++){
                criarPlataforma(sf::Vector2f(i * 350.0f, 550.0f), sf::Vector2f(350.0f, 50.0f), "padrao");
            }
            criarPorta(sf::Vector2f(0.0f, 450.0f), sf::Vector2f(85.0f, 100.0f),sf::Vector2f(-1000.0f, -1000.0f), sf::Vector2f(40.0f, 40.0f), IDs::IDs::floresta_branca_parte_1);
            /*
            for(int i = -2; i < 8; i++){
                criarPlataforma(sf::Vector2f(i * 350.0f, 550.0f), sf::Vector2f(350.0f, 50.0f), false, 0.0f, false);
            }
            for(int i = 0; i < 3; i++){
                criarEsqueleto(sf::Vector2f(400.0f * (i + 0.5f), 0.0f), 1);
            }
            for(int i = 0; i < 3; i++){
                criarEsqueleto(sf::Vector2f(400.0f * (2 + i + 0.5f), 0.0f), 3);
            }
            criarAlma(sf::Vector2f(200.0f, 500.0f), 2);
            criarAlma(sf::Vector2f(500.0f, 500.0f), 4);

            criarPorta(sf::Vector2f(400.0f, 450.0f), sf::Vector2f(85.0f, 100.0f),sf::Vector2f(-1000.0f, -1000.0f), sf::Vector2f(40.0f, 40.0f), IDs::IDs::floresta_branca_parte_1);
            criarPorta(sf::Vector2f(800.0f, 450.0f), sf::Vector2f(85.0f, 100.0f),sf::Vector2f(0.0f, 490.0f), sf::Vector2f(40.0f, 40.0f), IDs::IDs::floresta_branca_parte_3);
            */
        }

        void FlorestaBranca::criarMapa3(){
            for(int i = -2; i < 8; i++){
                criarPlataforma(sf::Vector2f(i * 500.0f, 550.0f), sf::Vector2f(500.0f, 50.0f), "padrao");
            }
            criarPlataforma(sf::Vector2f(400.0f, 400.0f), sf::Vector2f(350.0f, 50.0f), "madeira", sf::Vector2f(1.0f, 3.0f));
            criarPlataforma(sf::Vector2f(800.0f, 150.0f), sf::Vector2f(80.0f, 50.0f), 250.0f, false);
            criarPlataforma(sf::Vector2f(1000.0f, 150.0f), sf::Vector2f(350.0f, 50.0f), "madeira", sf::Vector2f(1.0f, 3.0f));
            criarCaixa(sf::Vector2f(250.0f, 500.0f));

            criarPorta(sf::Vector2f(1150.0f, 50.0f), sf::Vector2f(85.0f, 100.0f), sf::Vector2f(-1000.0f, -1000.0f), sf::Vector2f(40.0f, 40.0f), IDs::IDs::floresta_branca_parte_2);
        }

    }

}

