#include "..\..\..\..\include\Entidade\Personagem\Jogador\Jogador.hpp"
#include "..\..\..\..\include\Observador\ObservadorJogador.hpp"

#include <cmath>

namespace Jungle {

    namespace Entidade {

        namespace Personagem {

            namespace Jogador {

                Jogador::Jogador(const sf::Vector2f pos):
                    Personagem(pos, sf::Vector2f(TAMANHO_JOGADOR_X, TAMANHO_JOGADOR_Y), VELOCIDADE_JOGADOR, IDs::IDs::jogador), 
                    noChao(false), observadorJogador(new Observador::ObservadorJogador(this))
                {
                    if(observadorJogador == nullptr){
                        std::cout << "ERROR::Entidade::Personagem::Jogador::Jogador::nao foi possivel criar um observador para o jogador" << std::endl;
                        exit(1);
                    }
                    inicializa();
                }

                Jogador::~Jogador(){
                    if(observadorJogador){
                        delete(observadorJogador);
                        observadorJogador = nullptr;
                    }
                }


                void Jogador::inicializa(){
                    animacao.addAnimacao("Jungle++/img/Jogador/Anda.png", "ANDA", 10, 0.12f, sf::Vector2f(6,2));
                    animacao.addAnimacao("Jungle++/img/Jogador/Ataca.png", "ATACA", 10, 0.1f, sf::Vector2f(6,2));
                    animacao.addAnimacao("Jungle++/img/Jogador/Parado.png", "PARADO", 10, 0.15f, sf::Vector2f(6,2));
                    animacao.addAnimacao("Jungle++/img/Jogador/Pula.png", "PULA", 3, 0.15f, sf::Vector2f(6,2));
                    animacao.addAnimacao("Jungle++/img/Jogador/Cai.png", "CAI", 3, 0.15f, sf::Vector2f(6,2));
                    animacao.addAnimacao("Jungle++/img/Jogador/Morre.png", "MORRE", 10, 0.15f, sf::Vector2f(6,2));
                    animacao.addAnimacao("Jungle++/img/Jogador/tomaDano.png", "TOMA_DANO", 1, 0.15f, sf::Vector2f(6,2));
                    corpo.setOrigin(sf::Vector2f(tam.x / 2.5f, tam.y / 2.0f));
                }

                void Jogador::atualizar(){
                    /**
                        * @ return void 
                        * 
                        * Faz o movimeto do jogador e atualiza animação
                    */
                    atualizarPosicao();
                    atualizarAnimacao();
                    pGrafico->atualizarCamera(pos);
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
                        case (IDs::IDs::esqueleto):
                        {
                            
                        }
                        break;
                        case(IDs::IDs::plataforma):
                        {
                            
                        }
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

                void Jogador::ativarObservador(){
                    observadorJogador->ativarObservador();
                }
                void Jogador::desativarObservador(){
                    observadorJogador->desativarObservador();
                }
                
                const bool Jogador::getAtivarObservador() const {
                    return observadorJogador->getAtivar();
                }

            }

        }

    }

}