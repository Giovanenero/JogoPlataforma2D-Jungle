#include "../../../../include/Entidade/Personagem/Inimigo/Carniceiro.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Personagem {

            namespace Inimigo {

                Carniceiro::Carniceiro(const sf::Vector2f pos, const int nivel, Jogador::Jogador* pJogador):
                    Inimigo(pos, sf::Vector2f(80.0f, 100.0f), pJogador, IDs::IDs::carniceiro, 0.6f, 1.0f, 2000.0f)
                {
                    this->nivel.setNivel(nivel);
                    this->pontos = 2000;
                    inicializarAnimacao();
                    inicializarNivel();
                }

                Carniceiro::Carniceiro(const std::vector<std::string> atributos, Jogador::Jogador* pJogador):
                    Inimigo(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(0.0f, 0.0f), pJogador, IDs::IDs::carniceiro, 0.6f, 1.0f, 2000.0f)
                {
                    try {
                        sf::Vector2f posAtual(std::stof(atributos[1]), std::stof(atributos[2]));
                        sf::Vector2f tamAtual(std::stof(atributos[3]), std::stof(atributos[4]));
                        sf::Vector2f velFinalAtual(std::stof(atributos[5]), std::stof(atributos[6]));
                        const bool andandoAtual = atributos[7] == "1";
                        const bool paraEsquerdaAtual = atributos[8] == "1";
                        const bool levandoDanoAtual = atributos[9] == "1";
                        const bool atacandoAtual = atributos[10] == "1";
                        const bool morrendoAtual = atributos[11] == "1";
                        const float vidaAtual = std::stof(atributos[12]);
                        const float tempoDanoAtual = std::stof(atributos[13]);
                        const bool tempoMorrerAtual = std::stof(atributos[14]);
                        const bool dtAtual = std::stof(atributos[15]);
                        const unsigned int nivelAtual = std::stoi(atributos[16]);
                        const float expAtual = std::stof(atributos[17]);
                        const short moveAleatorioAtual = std::stoi(atributos[18]);
                        const float tempoMovelAtual = std::stof(atributos[19]);
                        const float tempoAtacarAtual = std::stof(atributos[20]);
                        const std::string imgAtual = atributos[21];
                        const unsigned int quadroAtual = std::stoi(atributos[22]);
                        const float tempoTotalAtual = std::stof(atributos[23]);

                        setPos(posAtual);
                        setTam(tamAtual);
                        setVelFinal(velFinalAtual);
                        this->andando = andandoAtual;
                        this->paraEsquerda = paraEsquerdaAtual;
                        this->levandoDano = levandoDanoAtual;
                        this->atacando = atacandoAtual;
                        this->morrendo = morrendoAtual;
                        this->vida = vidaAtual;
                        this->tempoDano = tempoDanoAtual;
                        this->tempoMorrer = tempoMorrerAtual;
                        this->dt = dtAtual;
                        
                        this->nivel.setNivel(nivelAtual);
                        this->nivel.addExp(expAtual);
                        inicializarNivel();

                        this->moveAleatorio = moveAleatorioAtual;
                        this->tempoMover = tempoMovelAtual;
                        this->tempoAtacar = tempoAtacarAtual;

                        inicializarAnimacao();
                        animacao.setImgAtual(imgAtual);
                        animacao.setQuadroAtual(quadroAtual);
                        animacao.setTempoTotal(tempoTotalAtual);
                    }
                    catch(const std::exception& e) {
                        std::cerr << e.what() << std::endl;
                        podeRemover = true;
                    }
                    
                }

                Carniceiro::~Carniceiro(){

                }

                void Carniceiro::inicializarAnimacao(){
                    sf::Vector2f origin(sf::Vector2f(25.0f, 25.0f));
                    sf::Vector2f escala(sf::Vector2f(2.0f, 2.0f));
                    animacao.addAnimacao("Jungle++/img/Personagem/Inimigo/Carniceiro/anda.png", "ANDA", 8, 0.1f, escala, origin);
                    animacao.addAnimacao("Jungle++/img/Personagem/Inimigo/Carniceiro/parado.png", "PARADO", 8, 0.1f, escala, origin);
                    animacao.addAnimacao("Jungle++/img/Personagem/Inimigo/Carniceiro/ataca.png", "ATACA", 5, 0.1f, escala, origin);
                    animacao.addAnimacao("Jungle++/img/Personagem/Inimigo/Carniceiro/morre.png", "MORRE", 6, 0.1f, escala, origin);
                    animacao.addAnimacao("Jungle++/img/Personagem/Inimigo/Carniceiro/tomaDano.png", "TOMADANO", 4, 0.2f, escala, origin);
                }

                void Carniceiro::inicializarNivel(){
                    nivel.setDefesa(50.0f);
                }

                const std::string Carniceiro::salvar(){
                    std::string linha = salvarInimigo();
                    return linha;
                }

            }

        }

    }

}