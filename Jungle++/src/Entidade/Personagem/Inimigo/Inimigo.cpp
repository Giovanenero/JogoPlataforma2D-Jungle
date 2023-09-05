#include "../../../../include/Entidade/Personagem/Inimigo/Inimigo.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Personagem {

            namespace Inimigo {

                Inimigo::Inimigo(const sf::Vector2f pos, const sf::Vector2f tam, Jogador::Jogador* jogador, const IDs::IDs ID, const float tempoMorrer, const float tempoAtacar, const float experiencia):
                    Personagem(pos, tam, VELOCIDADE_INIMIGO, ID, tempoMorrer), jogador(jogador), 
                    tempoMover(0.0f), tempoAnimacaoAtacar(tempoAtacar), tempoAtacar(0.0f),
                    experiencia(experiencia)
                {
                    srand(time(NULL));
                    moveAleatorio = rand()%3;
                    if(moveAleatorio == 0){
                        parar();
                    } else if(moveAleatorio == 1){
                        andar(true);
                    } else {
                        andar(false);
                    }
                    inicializarBarraVida();
                }

                Inimigo::~Inimigo(){
                    if(barraVida.getTexture()){
                        delete(barraVida.getTexture());
                    }
                }

                void Inimigo::inicializarBarraVida(){
                    barraVida.setSize((sf::Vector2f(BARRA_VIDA_X, BARRA_VIDA_Y)));
                    sf::Texture* textura = new sf::Texture(); 
                    textura->loadFromFile("Jungle++/img/Personagem/Vida/VidaInimigo.png");
                    barraVida.setTexture(textura);
                }

                void Inimigo::atualizaMovimentoAleatorio(){
                    if(tempoMover > TEMPO_MOVER_ALEATORIO){
                        moveAleatorio = rand()%3;
                        if(moveAleatorio == 0){
                            parar();
                        } else if(moveAleatorio == 1){
                            andar(true);
                        } else {
                            andar(false);
                        }
                        tempoMover = 0.0f;
                    } 
                }

                void Inimigo::atualizarTempoAtacar(){
                    if(atacando && !levandoDano){
                        tempoAtacar += pGrafico->getTempo();
                        if(tempoAtacar > tempoAnimacaoAtacar){
                            atacando = false;
                            arma->setPos(sf::Vector2f(-1000.0f, -1000.0f));
                            tempoAtacar = 0.0f;
                        } else if(tempoAtacar > tempoAnimacaoAtacar / 1.5f){
                            arma->setPos(sf::Vector2f(-1000.0f, -1000.0f));
                        } else if(tempoAtacar > tempoAnimacaoAtacar / 1.7f){
                            sf::Vector2f posEspada = (paraEsquerda ? sf::Vector2f(pos.x - arma->getTam().x / 2.0f, pos.y) : sf::Vector2f(pos.x + tam.x / 2.0f, pos.y));
                            arma->setPos(posEspada);
                        }
                    } else if(levandoDano){
                        tempoAtacar = 0.0f;
                        atacando = false;
                        if(arma != nullptr){
                            arma->setPos(sf::Vector2f(-1000.0f, -1000.0f));
                        }
                    }
                }

                void Inimigo::moveInimigo(){
                    if(!levandoDano && !morrendo && !atacando){
                        sf::Vector2f posJogador = jogador->getPos();
                        sf::Vector2f posInimigo = getPos();
                        if(fabs(posJogador.x - posInimigo.x) <= RAIO_PERSEGUIR_X && fabs(posJogador.y - posInimigo.y) <= RAIO_PERSEGUIR_Y){
                            if(posJogador.x - posInimigo.x > 0.0f){
                                andar(false);
                            } else {
                                andar(true);
                            }
                        } else {
                            atualizaMovimentoAleatorio();
                        }
                    } else {
                        tempoMover = 0.0f;
                    }
                }

                const float Inimigo::getExperiencia() const{
                    return experiencia;
                }

                void Inimigo::atualizar(){
                    moveInimigo();

                    atualizarPosicao();

                    tempoMover += pGrafico->getTempo();

                    atualizarTempoAtacar();

                    atualizarAnimacao();

                    atualizarBarraVida();

                    atualizarNivel();
                }

                void Inimigo::atualizarAnimacao(){
                    if(morrendo){
                        animacao.atualizar(paraEsquerda, "MORRE");
                        tempoMorrer += pGrafico->getTempo();
                        if(tempoMorrer > tempoAnimacaoMorrer){
                            podeRemover = true;
                            tempoMorrer = 0.0f;
                            if(arma != nullptr){
                                arma->remover();
                            }
                        }
                    } else if(levandoDano){
                        animacao.atualizar(paraEsquerda, "TOMADANO");
                    } else if(atacando){
                        animacao.atualizar(paraEsquerda, "ATACA");
                    } else if(andando){
                        animacao.atualizar(paraEsquerda, "ANDA");
                    } else {
                        animacao.atualizar(paraEsquerda, "PARADO");
                    }
                }

                const std::string Inimigo::salvarInimigo(){
                    std::string linha = salvarPersonagem();
                    linha += std::to_string(moveAleatorio) + ' ';
                    linha += std::to_string(tempoMover) + ' ';
                    linha += std::to_string(tempoAtacar) + ' ';
                    linha += animacao.getImgAtual() + ' ';
                    linha += std::to_string(animacao.getQuadroAtual()) + ' ';
                    linha += std::to_string(animacao.getTempoTotal()) + ' ';
                    return linha;
                }

                void Inimigo::tomarDano(const float dano){
                    if(!levandoDano){
                        levandoDano = true;
                        andando = false;
                        vida -= dano * (dano / (dano + nivel.getDefesa()));
                        if(vida <= 0.0f){
                            morrendo = true;
                            vida = 0.0f;
                        }
                        tempoDano = 0.0f;
                    }
                }

                void Inimigo::colisao(Entidade* outraEntidade, sf::Vector2f ds){
                    switch(outraEntidade->getID()){
                        case (IDs::IDs::jogador):
                        {
                            std::cout << "Bate jogador e jogador pode bater no inimigo" << std::endl;
                        }
                            break;
                        case (IDs::IDs::minotauro):
                        {
                            //std::cout << "Empurra inimigo" << std::endl;
                        }
                            break;
                        case(IDs::IDs::esqueleto):
                        {

                        }
                            break;
                        case(IDs::IDs::espada_jogador):
                        {
                            std::cout << "Colidiu com o inimigo" << std::endl;
                        }
                            break;
                    }
                }

            }

        }

    }

}