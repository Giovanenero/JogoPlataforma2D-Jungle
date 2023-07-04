#include "..\..\..\..\include\Entidade\Personagem\Inimigo\Inimigo.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Personagem {

            namespace Inimigo {

                Inimigo::Inimigo(const sf::Vector2f pos, const sf::Vector2f tam, Jogador::Jogador* jogador, const IDs::IDs ID, const float tempoMorrer, const float tempoAtacar):
                    Personagem(pos, tam, VELOCIDADE_INIMIGO, ID, tempoMorrer), jogador(jogador), 
                    dtAux(0.0f), tempoAnimacaoAtacar(tempoAtacar), tempoAtacar(0.0f)
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
                    textura->loadFromFile("Jungle++/img/Personagem/Vida/BarraVida.png");
                    barraVida.setTexture(textura);
                }

                void Inimigo::atualizaMovimentoAleatorio(){
                    if(dtAux > 1.0f){
                        moveAleatorio = rand()%3;
                        if(moveAleatorio == 0){
                            parar();
                        } else if(moveAleatorio == 1){
                            andar(true);
                        } else {
                            andar(false);
                        }
                        dtAux = 0.0f;
                    } 
                }

                void Inimigo::atualizarTempoAtacar(){
                    if(atacando && !levandoDano){
                        tempoAtacar += pGrafico->getTempo();
                        if(tempoAtacar > tempoAnimacaoAtacar){
                            atacando = false;
                            guardarEspada();
                            tempoAtacar = 0.0f;
                        } else if(tempoAtacar > tempoAnimacaoAtacar / 1.5f){
                            guardarEspada();
                        } else if(tempoAtacar > tempoAnimacaoAtacar / 1.7f){
                            sf::Vector2f posEspada = (paraEsquerda ? sf::Vector2f(pos.x - espada->getTam().x / 2.0f, pos.y) : sf::Vector2f(pos.x + tam.x / 2.0f, pos.y));
                            espada->setPos(posEspada);
                        }
                    } else if(levandoDano){
                        tempoAtacar = 0.0f;
                        atacando = false;
                        guardarEspada();
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
                        dtAux = 0.0f;
                    }
                }

                void Inimigo::atualizar(){
                    moveInimigo();
                    atualizarPosicao();
                    dtAux += pGrafico->getTempo();

                    atualizarTempoAtacar();

                    atualizarAnimacao();

                    atualizarBarraVida();
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