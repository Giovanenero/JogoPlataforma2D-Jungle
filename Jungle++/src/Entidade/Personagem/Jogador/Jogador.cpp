#include "..\..\..\..\include\Entidade\Personagem\Jogador\Jogador.hpp"
#include "..\..\..\..\include\Observador\ObservadorJogador.hpp"

#include <cmath>

namespace Jungle {

    namespace Entidade {

        namespace Personagem {

            namespace Jogador {

                Jogador::Jogador(const sf::Vector2f pos, Item::Espada* espada):
                    Personagem(pos, sf::Vector2f(TAMANHO_JOGADOR_X, TAMANHO_JOGADOR_Y), VELOCIDADE_JOGADOR, IDs::IDs::jogador, TEMPO_JOGADOR_MORRER), 
                    noChao(false), observadorJogador(new Observador::ObservadorJogador(this)),
                    espada(espada), pontuacao(0)
                {
                    if(observadorJogador == nullptr){
                        std::cout << "ERROR::Entidade::Personagem::Jogador::Jogador::nao foi possivel criar um observador para o jogador" << std::endl;
                        exit(1);
                    }
                    inicializaAnimacao();
                    espada->setDano(DANO);
                    espada->setTam(sf::Vector2f(TAMANHO_ESPADA_X, TAMANHO_JOGADOR_Y));
                }

                Jogador::~Jogador(){
                    if(observadorJogador){
                        delete(observadorJogador);
                        observadorJogador = nullptr;
                    }
                    /*
                    if(espada){
                        delete(espada);
                        espada = nullptr;
                    }
                    */
                }


                void Jogador::inicializaAnimacao(){
                    animacao.addAnimacao("Jungle++/img/Personagem/Jogador/Anda.png", "ANDA", 10, 0.12f, sf::Vector2f(6,2));
                    animacao.addAnimacao("Jungle++/img/Personagem/Jogador/Ataca.png", "ATACA", 10, 0.1f, sf::Vector2f(6,2));
                    animacao.addAnimacao("Jungle++/img/Personagem/Jogador/Parado.png", "PARADO", 10, 0.15f, sf::Vector2f(6,2));
                    animacao.addAnimacao("Jungle++/img/Personagem/Jogador/Pula.png", "PULA", 3, 0.15f, sf::Vector2f(6,2));
                    animacao.addAnimacao("Jungle++/img/Personagem/Jogador/Cai.png", "CAI", 3, 0.15f, sf::Vector2f(6,2));
                    animacao.addAnimacao("Jungle++/img/Personagem/Jogador/Morre.png", "MORRE", 10, 0.15f, sf::Vector2f(6,2));
                    animacao.addAnimacao("Jungle++/img/Personagem/Jogador/tomaDano.png", "TOMA_DANO", 1, 0.15f, sf::Vector2f(6,2));
                    corpo.setOrigin(sf::Vector2f(tam.x / 2.5f, tam.y / 2.0f));
                }

                void Jogador::atualizar(){
                    /**
                        * @ return void 
                        * 
                        * Faz o movimeto do jogador e atualiza animação
                    */
                    atualizarPosicao();

                    if(atacando){
                        sf::Vector2f tamEspada = espada->getTam();
                        sf::Vector2f posEspada = pos + (paraEsquerda ? sf::Vector2f(-tamEspada.x - tam.x, tamEspada.y) : tamEspada);
                        espada->setPos(posEspada);
                    } else {
                        espada->setPos(sf::Vector2f(-500.0f, -500.0f));
                    }

                    atualizarAnimacao();


                    pGrafico->atualizarCamera(sf::Vector2f(pos.x, 300.0f));
                }

                void Jogador::atualizarAnimacao(){
                    if(!noChao && velFinal.y > 0.0f){
                        animacao.atualizar(paraEsquerda, "CAI");
                    } else if(!noChao){
                        animacao.atualizar(paraEsquerda, "PULA");
                    } else if(atacando){
                        animacao.atualizar(paraEsquerda, "ATACA");
                    } else if(podeAndar){
                        animacao.atualizar(paraEsquerda, "ANDA");
                    } else {
                        animacao.atualizar(paraEsquerda, "PARADO");
                    }
                }

                void Jogador::colisao(Entidade* outraEntidade, sf::Vector2f ds){
                    switch(outraEntidade->getID()){
                        case(IDs::IDs::plataforma):
                        {
                            
                        }
                        case(IDs::IDs::espada_inimigo):
                        {
                            std::cout << "Tomar dano do inimigo" << std::endl;
                        }
                            break;
                    }   
                }

                void Jogador::pular(){
                    if(noChao){
                        velFinal.y = -sqrt(2.0f * GRAVIDADE * TAMANHO_PULO);
                        noChao = false;
                    }
                }

                void Jogador::podePular(){
                    noChao = true;
                }

                void Jogador::mudarEstadoObservador(){
                    observadorJogador->mudarEstadoAtivar();
                }

                void Jogador::addPontuacao(unsigned int pontos){
                    pontuacao += pontos;
                }

                unsigned int Jogador::getPontos() const {
                    return pontuacao;
                }

            }

        }

    }

}