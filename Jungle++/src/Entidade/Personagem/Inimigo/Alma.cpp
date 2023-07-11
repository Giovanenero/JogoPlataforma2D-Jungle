#include "../../../../include/Entidade/Personagem/Inimigo/Alma.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Personagem {

            namespace Inimigo {

                Alma::Alma(const sf::Vector2f pos, Jogador::Jogador* pJogador):
                    Inimigo(
                        pos, 
                        sf::Vector2f(TAMANHO_ALMA_X, TAMANHO_ALMA_Y), 
                        pJogador, 
                        IDs::IDs::alma, 
                        TEMPO_ALMA_MORRER, 
                        TEMPO_ALMA_ATACAR
                    )
                {
                    this->pontos = PONTOS_ALMA;
                    inicializarAnimacao();
                }

                Alma::~Alma(){

                }

                void Alma::inicializarAnimacao(){
                    const sf::Vector2f origin = sf::Vector2f(tam.x / 4.0f, tam.y / 4.0f);
                    animacao.addAnimacao("Jungle++/img/Personagem/Inimigo/Alma/Parado.png", "PARADO", 5, 0.12f, sf::Vector2f(2.5f, 1.5f), origin, false);
                    animacao.addAnimacao("Jungle++/img/Personagem/Inimigo/Alma/Anda.png", "ANDA", 8, 0.15f, sf::Vector2f(2.5f, 1.5f), origin, false);
                    animacao.addAnimacao("Jungle++/img/Personagem/Inimigo/Alma/Morre.png", "MORRE", 8, 0.2f, sf::Vector2f(2.5f, 1.5f), origin, false);
                    animacao.addAnimacao("Jungle++/img/Personagem/Inimigo/Alma/Ataca.png", "ATACA", 10, 0.3f, sf::Vector2f(2.5f, 1.5f), origin, false);
                }

                void Alma::moveInimigo(){
                    if(!morrendo && !atacando){
                        sf::Vector2f posJogador = jogador->getPos();
                        sf::Vector2f tamJogador = jogador->getTam();
                        const float x = fabs((posJogador.x - tamJogador.x / 2.0f) - (pos.x - tam.x / 2.0f));
                        const float y = fabs((posJogador.y - tamJogador.y / 2.0f) - (pos.y - tam.y / 2.0f));
                        if(x <= RECONHECIMENTO_ALMA_X && y <= RECONHECIMENTO_ALMA_Y){
                            parar();
                            paraEsquerda = !(posJogador.x - pos.x > 0.0f);
                            
                            tempoAtacar += pGrafico->getTempo() * 0.5f;
                            if(tempoAtacar > tempoAnimacaoAtacar){
                                atacando = true;
                                tempoAtacar = 0.0f;
                            }
                        } else {
                            atualizaMovimentoAleatorio();
                            tempoAtacar = 0.0f;
                        }
                    } else {
                        tempoMover = 0.0f;
                    }
                }

                void Alma::atualizarTempoAtacar(){
                    if(atacando){
                        tempoAtacar += pGrafico->getTempo();
                        if(tempoAtacar > tempoAnimacaoAtacar){
                            atacando = false;
                            tempoAtacar = 0.0f;
                        }
                    }
                }

                void Alma::atualizarAnimacao(){
                    if(morrendo){
                        animacao.atualizar(paraEsquerda, "MORRE");
                        tempoMorrer += pGrafico->getTempo();
                        if(tempoMorrer > tempoAnimacaoMorrer){
                            podeRemover = true;
                            tempoMorrer = 0.0f;
                        }
                    } else if(atacando){
                        animacao.atualizar(paraEsquerda, "ATACA");
                    } else if(andando){
                        animacao.atualizar(paraEsquerda, "ANDA");
                    } else {
                        animacao.atualizar(paraEsquerda, "PARADO");
                    }
                }

            }

        }

    }

}