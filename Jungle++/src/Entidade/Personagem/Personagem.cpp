#include "..\..\..\include\Entidade\Personagem\Personagem.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Personagem {

            Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f tam, const float vel, const IDs::IDs ID,  const float tempoMorrer, const float tempoDano):
                Entidade(tam, ID, pos), andando(false), paraEsquerda(false),
                dt(0.0f), velFinal(sf::Vector2f(vel, 0.0f)), velMax(vel), atacando(false),
                animacao(&corpo), tempoAnimacaoMorrer(tempoMorrer), tempoMorrer(0.0f),
                vidaMaxima(100.0f), vida(100.0f), tempoAnimacaoTomarDano(tempoDano), tempoDano(0.0f),
                morrendo(false), espada(nullptr)
            {

            }

            Personagem::~Personagem(){

            }

            void Personagem::andar(const bool paraEsquerda){
                atacando = false;
                andando = true;
                this->paraEsquerda = paraEsquerda;
            }

            void Personagem::parar(){
                andando = false;
            }

            void Personagem::atacar(const bool atacando){
                andando = false;
                this->atacando = atacando;
            }

            void Personagem::atualizarPosicao(){
                dt = pGrafico->getTempo();
                //vai resetar o relógio no caso de jogo pausado;

                if(dt > 0.3f){
                    dt = 0.0f;
                }
                //relogio.restart();
                sf::Vector2f ds(0.0f, 0.0f);

                //move na horizontal
                if(andando){
                    ds.x = velFinal.x * dt;
                    if(paraEsquerda){
                        ds.x *= -1;
                    }
                }

                    //sofre o efeito da gravidade
                velFinal.y += GRAVIDADE * dt;
                ds.y = velFinal.y * GRAVIDADE;

                //atualiza posição
                setPos(sf::Vector2f(pos.x + ds.x, pos.y + ds.y));

                //atualiza velocidade na horizontal
                velFinal.x = velMax;

                //carrega o tempo pra ele levar outro dano
                atualizarTomarDano();

                //desenha na janela
                desenhar();
            }

            void Personagem::setVelFinal(sf::Vector2f velFinal){
                this->velFinal = velFinal;
            }

            const sf::Vector2f Personagem::getVelFinal() const{
                return velFinal;
            }

            const bool Personagem::getMorrer() const {
                return morrendo;
            }

            void Personagem::setEspada(Item::Espada* espada){
                this->espada = espada;
                espada->setEntidade(static_cast<Entidade*>(this));
                espada->setTam(tam);
                espada->setDano(20.0f);
            }

            void Personagem::guardarEspada(){
                espada->setPos(sf::Vector2f(-1000.0f, -1000.0f));
            }

            void Personagem::atualizarTomarDano(){
                tempoDano += pGrafico->getTempo();
                if(levandoDano && tempoDano > tempoAnimacaoTomarDano){
                    levandoDano = false;
                    tempoDano = 0.0f;
                }
            }

            void Personagem::tomarDano(const float dano){
                if(!levandoDano){
                    levandoDano = true;
                    andando = false;
                    vida -= dano;
                    if(vida <= 0.0f){
                        morrendo = true;
                        vida = 0.0f;
                    }
                    tempoDano = 0.0f;
                }
            }

            void Personagem::atualizarBarraVida(){
                barraVida.setPosition(sf::Vector2f(pos.x + tam.x / 2.0f - corpo.getSize().x / 2.0f, pos.y - 20.0f));
                barraVida.setSize(sf::Vector2f((vida / 100.0f) * BARRA_VIDA_X, BARRA_VIDA_Y));
                barraVida.setOrigin(sf::Vector2f(barraVida.getSize().x / 4.0f, 1.0f));
            }

            void Personagem::atualizarAnimacao(){
                if(morrendo){
                    animacao.atualizar(paraEsquerda, "MORRE");
                    tempoMorrer += pGrafico->getTempo();
                    if(tempoMorrer > tempoAnimacaoMorrer){
                        podeRemover = true;
                        tempoMorrer = 0.0f;
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

            void Personagem::desenhar(){
                pGrafico->desenhaElemento(corpo);
                pGrafico->desenhaElemento(barraVida);
            }

        }

    }

}