#include "../../../../include/Entidade/Personagem/Inimigo/Esqueleto.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Personagem {

            namespace Inimigo {

                Esqueleto::Esqueleto(const sf::Vector2f pos, Jogador::Jogador* jogador):
                    Inimigo(
                        pos, 
                        sf::Vector2f(TAMANHO_ESQUELO_X, TAMANHO_ESQUELO_Y), 
                        jogador, 
                        IDs::IDs::esqueleto, 
                        TEMPO_ESQUELETO_MORRER
                    )
                {
                    this->pontos = PONTOS_ESQUELETO;
                    inicializarAnimacao();
                }

                Esqueleto::Esqueleto(const std::vector<std::string> atributos, Jogador::Jogador* jogador):
                    Inimigo(
                        sf::Vector2f(0.0f, 0.0f), 
                        sf::Vector2f(TAMANHO_ESQUELO_X, TAMANHO_ESQUELO_Y), 
                        jogador, 
                        IDs::IDs::esqueleto, 
                        TEMPO_ESQUELETO_MORRER
                    )
                {
                    this->pontos = PONTOS_ESQUELETO;
                    try {
                        const sf::Vector2f posAtual = sf::Vector2f(std::stof(atributos[1]), std::stof(atributos[2]));
                        const sf::Vector2f tamAtual = sf::Vector2f(std::stof(atributos[3]), std::stof(atributos[4]));
                        const sf::Vector2f velFinalAtual = sf::Vector2f(std::stof(atributos[5]), std::stof(atributos[6]));
                        const bool andandoAtual = atributos[7] == "1";
                        const bool paraEsquerdaAtual = atributos[8] == "1";
                        const bool levandoDanoAtual = atributos[9] == "1";
                        const bool atacandoAtual = atributos[10] == "1";
                        const bool morrendoAtual = atributos[11] == "1";
                        const float vidaAtual = std::stof(atributos[12]);
                        const float tempoDanoAtual = std::stof(atributos[13]);
                        const float tempoMorrerAtual = std::stof(atributos[14]);
                        const float dtAtual = std::stof(atributos[15]);
                        const short moveAleatorioAtual = std::stol(atributos[16]);
                        const float tempoMoverAtual = std::stof(atributos[17]);
                        const float tempoAtacarAtual = std::stof(atributos[18]);

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
                        this->moveAleatorio = moveAleatorioAtual;
                        this->tempoMover = tempoMoverAtual;
                        this->tempoAtacar = tempoAtacarAtual;

                        inicializarAnimacao();
                    }
                    catch(const std::exception& e)
                    {
                        std::cerr << e.what() << std::endl;
                        podeRemover = true;
                    }
                    
                }

                Esqueleto::~Esqueleto(){

                }

                const std::string Esqueleto::salvar(){
                    std::string linha = "";
                    //salvando atributos da entidade
                    linha += std::to_string(static_cast<int>(ID)) + ' ';
                    linha += std::to_string(pos.x) + ' ';
                    linha += std::to_string(pos.y) + ' ';
                    linha += std::to_string(tam.x) + ' ';
                    linha += std::to_string(tam.y) + ' ';
                    //salvando atributos do personagem
                    linha += std::to_string(velFinal.x) + ' ';
                    linha += std::to_string(velFinal.y) + ' ';
                    linha += std::to_string(andando) + ' ';
                    linha += std::to_string(paraEsquerda) + ' ';
                    linha += std::to_string(levandoDano) + ' ';
                    linha += std::to_string(atacando) + ' ';
                    linha += std::to_string(morrendo) + ' ';
                    linha += std::to_string(vida) + ' ';
                    linha += std::to_string(tempoDano) + ' ';
                    linha += std::to_string(tempoMorrer) + ' ';
                    linha += std::to_string(dt) + ' ';
                    //salvando atributos do inimigo
                    linha += std::to_string(moveAleatorio) + ' ';
                    linha += std::to_string(tempoMover) + ' ';
                    linha += std::to_string(tempoAtacar);
                    //salvando atributos do esqueleto
                    //ainda n tem
                    return linha;
                }

                void Esqueleto::inicializarAnimacao(){
                    const sf::Vector2f origin = sf::Vector2f(tam.x / 12.0f, tam.y / 8.5f);
                    animacao.addAnimacao("Jungle++/img/Personagem/Inimigo/Esqueleto/Parado.png", "PARADO", 11, 0.12f, sf::Vector2f(1.0f, 1.10f), origin);
                    animacao.addAnimacao("Jungle++/img/Personagem/Inimigo/Esqueleto/Anda.png", "ANDA", 13, 0.15f, sf::Vector2f(1.0f, 1.10f), origin);
                    animacao.addAnimacao("Jungle++/img/Personagem/Inimigo/Esqueleto/Morre.png", "MORRE", 15, 0.10f, sf::Vector2f(1.5f, 1.10f), origin);
                    animacao.addAnimacao("Jungle++/img/Personagem/Inimigo/Esqueleto/tomaDano.png", "TOMADANO", 8, 0.15f, sf::Vector2f(1.2f, 1.10f), origin);
                    animacao.addAnimacao("Jungle++/img/Personagem/Inimigo/Esqueleto/Ataca.png", "ATACA", 18, 0.15f, sf::Vector2f(1.95f, 1.3f), sf::Vector2f(tam.x / 3.0f, tam.y / 4.0f));
                }

            }

        }

    }

}