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
                    criarEntidade(IDs::IDs::jogador, getAtributosEntidade(linhas[0]), getAtributosEntidade(linhas[1]), true);
                    //pGrafico->atualizarCamera(pJogador->getPos(), pJogador->getTam());
                    //fundo.atualizarPosicao();
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
                            criarEntidade(IDs::IDs::esqueleto, atributos, getAtributosEntidade(linhas[i + 1]), true);
                            i++;
                        }
                            break;
                        case (7):
                        {
                            //criar alma com projetil
                            criarEntidade(IDs::IDs::alma, atributos, getAtributosEntidade(linhas[i + 1]), true);
                            i++;
                        }
                            break;
                        case (8):
                        {
                            //cria plataforma
                            criarEntidade(IDs::IDs::plataforma, atributos, {}, false);
                        }
                            break;
                        case (9):
                        {
                            //criar caixa
                            criarEntidade(IDs::IDs::caixa, atributos, {}, false);
                        }
                            break;
                        case (10):
                        {
                            //criar moeda amarela
                            criarEntidade(IDs::IDs::moeda_amarela, atributos, {}, false);
                        }
                            break;
                        case (11):
                        {
                            //criar moeda cinza
                            criarEntidade(IDs::IDs::moeda_cinza, atributos, {}, false);
                        }
                            break;
                        case (12):
                        {
                            //criar vida
                            criarEntidade(IDs::IDs::vida, atributos, {}, false);
                        }
                            break;
                        case(50):
                        {
                            //criar plataforma
                            criarEntidade(IDs::IDs::plataforma_movel, atributos, {}, false);
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
                            criarEntidade(IDs::IDs::porta, atributos, atributosChave, false);
                        }
                            break;
                        case(56):
                        {
                            criarEntidade(IDs::IDs::espinho, atributos, {}, false);
                        }
                            break;
                        case (57):
                            criarEntidade(IDs::IDs::carniceiro, atributos, {}, true);

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
            sf::Vector2f tamJanela = pGrafico->getTamJanela();
            limiteCamera.left = -550.0f + tamJanela.x / 2.0f - 75.f;
            limiteCamera.top = 150.0f;
            limiteCamera.width = 11 * 500.0f - 50.0f;
            limiteCamera.height = tamJanela.y - 350.0f;
            pGrafico->setLimiteCamera(limiteCamera);

            criarPlataforma(sf::Vector2f(-550.0f, 100.0f), sf::Vector2f(50.f, 500.0f), "parede");
            criarPorta(sf::Vector2f(-450.0f, 430.0f), sf::Vector2f(85.0f, 110.0f),sf::Vector2f(-350.0f, 510.0f), sf::Vector2f(40.0f, 40.0f), IDs::IDs::floresta_branca_parte_3);
            //chão
            for(int i = -1; i < 11; i++){
                criarPlataforma(sf::Vector2f(i * 500.0f, 550.0f), sf::Vector2f(500.0f, 50.0f), "padrao");
            }
            criarPlataforma(sf::Vector2f(11 * 500.0f, 100.0f), sf::Vector2f(50.f, 500.0f), "parede");

            //plataforma do jogador
            criarPersonagem(IDs::IDs::jogador, sf::Vector2f(150.0f, 300.0f));

            // teste
            criarPlataforma(sf::Vector2f(300.0f, 0.0f), sf::Vector2f(80.0f, 50.0f), 400.0f, false);

            //criando espinho
            criarEspinho(sf::Vector2f(320.0f, 525.0f), sf::Vector2f(80.0f, 25.0f));

            criarPlataforma(sf::Vector2f(0.0f, 400.0f), sf::Vector2f(250.0f, 10.0f), "madeira", sf::Vector2f(1.0f, 15.2f));
            
            criarPersonagem(IDs::IDs::esqueleto, sf::Vector2f(450.0f, 450.0f), 1);
            criarCaixa(sf::Vector2f(700.0f, 500.0f));
        
            criarPlataforma(sf::Vector2f(750.0f, 400.0f), sf::Vector2f(300.0f, 10.0f), "madeira", sf::Vector2f(1.0f, 15.2f));
            criarPlataforma(sf::Vector2f(750.0f + 300.0f, 400.0f), sf::Vector2f(300.0f, 10.0f), "madeira", sf::Vector2f(1.0f, 15.2f));
            criarEspinho(sf::Vector2f(1000.0f, 375.0f), sf::Vector2f(80.0f, 25.0f));
            criarPersonagem(IDs::IDs::esqueleto, sf::Vector2f(900.0f, 300.0f), 1);
            criarPlataforma(sf::Vector2f(1350.0f, 200.0f), sf::Vector2f(80.0f, 50.0f), 200.0f, false);

            criarPlataforma(sf::Vector2f(1350.0f + 80.0f, 200.0f), sf::Vector2f(350.0f, 50.0f), "flutuante_maior", sf::Vector2f(1.0f, 1.2f));
            criarEspinho(sf::Vector2f(1480.0f, 175.0f), sf::Vector2f(80.0f, 25.0f));
            criarPorta(sf::Vector2f(1650.0f, 80.0f), sf::Vector2f(85.0f, 110.0f),sf::Vector2f(4650.0, 160.0f), sf::Vector2f(40.0f, 40.0f), IDs::IDs::floresta_branca_parte_2);
            //criarPorta(sf::Vector2f(150.0f, 250.0f), sf::Vector2f(85.0f, 110.0f),sf::Vector2f(150.0f, 200.0f), sf::Vector2f(40.0f, 40.0f), IDs::IDs::floresta_branca_parte_2);
            criarPersonagem(IDs::IDs::esqueleto, sf::Vector2f(1700.0f, 100.0f), 4);
            criarCaixa(sf::Vector2f(2200.0f, 500.0f));

            criarPlataforma(sf::Vector2f(2300.0f, 400.0f), sf::Vector2f(300.0f, 10.0f), "madeira", sf::Vector2f(1.0f, 15.2f));
            criarPersonagem(IDs::IDs::esqueleto, sf::Vector2f(2500.0f, 300.0f), 5);
            criarPlataforma(sf::Vector2f(2600.0f, 400.0f), sf::Vector2f(80.0f, 50.0f), 300.0f, true);
            criarPersonagem(IDs::IDs::esqueleto, sf::Vector2f(2800.0f, 300.0f), 4);

            criarPlataforma(sf::Vector2f(2980.0f, 400.0f), sf::Vector2f(300.0f, 10.0f), "madeira", sf::Vector2f(1.0f, 15.2f));
            criarPlataforma(sf::Vector2f(3300.0f, 200.0f), sf::Vector2f(80.0f, 50.0f), 200.0f, false);
            criarPersonagem(IDs::IDs::esqueleto, sf::Vector2f(3650.0f, 200.0f), 3);
            criarPersonagem(IDs::IDs::alma, sf::Vector2f(3600.0f, 450.0f), 1);
            criarPersonagem(IDs::IDs::esqueleto, sf::Vector2f(3800.0f, 450.0f), 3);
            criarPersonagem(IDs::IDs::esqueleto, sf::Vector2f(3800.0f, 100.0f), 4);
            criarPlataforma(sf::Vector2f(3400.0f, 200.0f), sf::Vector2f(80.0f, 50.0f), 200.0f, true);
            criarPlataforma(sf::Vector2f(3700.0f, 200.0f), sf::Vector2f(350.0f, 50.0f), "flutuante_maior", sf::Vector2f(1.0f, 1.2f));
            criarPlataforma(sf::Vector2f(4080.0f, 200.0f), sf::Vector2f(80.0f, 50.0f), 200.0f, true);
            criarPlataforma(sf::Vector2f(4380.0f, 200.0f), sf::Vector2f(350.0f, 50.0f), "flutuante_maior", sf::Vector2f(1.0f, 1.2f));
        }
        
        
        void FlorestaBranca::criarMapa2(){
            sf::Vector2f tamJanela = pGrafico->getTamJanela();
            limiteCamera.left = -550.0f + tamJanela.x / 2.0f - 75.f;
            limiteCamera.top = 150.0f;
            limiteCamera.width = 500.0f - 50.0f;
            limiteCamera.height = tamJanela.y - 350.0f;
            pGrafico->setLimiteCamera(limiteCamera);

            criarPlataforma(sf::Vector2f(-550.0f, 100.0f), sf::Vector2f(50.f, 500.0f), "parede");
            criarPlataforma(sf::Vector2f(-220.0f, -100.0f), sf::Vector2f(50.f, 500.0f), "parede_flutuante");
            criarPlataforma(sf::Vector2f(-500.0f, 450.0f), sf::Vector2f(80.0f, 1.0f), "ponte_direita", sf::Vector2f(1.0f, 40.0f));
            criarPlataforma(sf::Vector2f(-220.0f - 80.0f, 350.0f), sf::Vector2f(80.0f, 1.0f), "ponte_esquerda", sf::Vector2f(1.0f, 40.0f));
            criarPlataforma(sf::Vector2f(-500.0f, 250.0f), sf::Vector2f(80.0f, 1.0f), "ponte_direita", sf::Vector2f(1.0f, 40.0f));
            for(int i = -1; i < 1; i++){
                criarPlataforma(sf::Vector2f(i * 500.0f, 550.0f), sf::Vector2f(500.0f, 50.0f), "padrao");
            }
            criarPorta(sf::Vector2f(0.0f, 450.0f), sf::Vector2f(85.0f, 100.0f),sf::Vector2f(-1000.0f, -1000.0f), sf::Vector2f(40.0f, 40.0f), IDs::IDs::floresta_branca_parte_1);

            //Boss
            criarPersonagem(IDs::IDs::carniceiro, sf::Vector2f(400.0f, 300.0f), 2);

            criarPlataforma(sf::Vector2f(500.0f, 100.0f), sf::Vector2f(50.f, 500.0f), "parede");
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

