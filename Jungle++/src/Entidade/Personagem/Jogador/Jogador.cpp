#include "..\..\..\..\include\Entidade\Personagem\Jogador\Jogador.hpp"
#include "..\..\..\..\include\Observador\ObservadorJogador.hpp"
#include "../../../../include/Entidade/Personagem/Inimigo/Inimigo.hpp"

#include <cmath>

namespace Jungle {

    namespace Entidade {

        namespace Personagem {

            namespace Jogador {

                Jogador::Jogador(const sf::Vector2f pos, Item::Espada* espada):
                    Personagem(pos, sf::Vector2f(TAMANHO_JOGADOR_X, TAMANHO_JOGADOR_Y), VELOCIDADE_JOGADOR, IDs::IDs::jogador, TEMPO_JOGADOR_MORRER, TEMPO_JOGADOR_TOMARDANO), 
                    noChao(false), observadorJogador(new Observador::ObservadorJogador(this))
                {
                    this->pontos = 0;
                    if(observadorJogador == nullptr){
                        std::cout << "ERROR::Entidade::Personagem::Jogador::Jogador::nao foi possivel criar um observador para o jogador" << std::endl;
                        exit(1);
                    }
                    inicializarAnimacao();
                    inicializarBarraVida();
                    
                    setEspada(espada);
                    espada->setDano(DANO);
                }

                Jogador::~Jogador(){
                    if(observadorJogador){
                        delete(observadorJogador);
                        observadorJogador = nullptr;
                    }
                    if(tuboBarraVida.getTexture()){
                        delete(tuboBarraVida.getTexture());
                    }
                }

                void Jogador::inicializarBarraVida(){
                    sf::Vector2f tamTubo = sf::Vector2f(BARRA_VIDA_JOGADOR_X, BARRA_VIDA_JOGADOR_Y);
                    sf::Vector2f tamVida = sf::Vector2f(BARRA_VIDA_JOGADOR_X * 61.54f, BARRA_VIDA_JOGADOR_Y * 25.0f);
                    tuboBarraVida.setSize(tamTubo);
                    //barraVida.setSize(sf::Vector2f(124.0f, 12.0f));
                    barraVida.setSize(tamVida);
                    sf::Texture* texturaVida = new sf::Texture(); 
                    sf::Texture* texturaBarra = new sf::Texture();
                    texturaVida->loadFromFile("Jungle++/img/Personagem/Vida/BarraVida.png");
                    texturaBarra->loadFromFile("Jungle++/img/Personagem/Vida/Barra.png");
                    barraVida.setTexture(texturaVida);
                    tuboBarraVida.setTexture(texturaBarra);
                }


                void Jogador::inicializarAnimacao(){
                    const sf::Vector2f origin = sf::Vector2f(tam.x / 2.5f, tam.y / 2.0f);
                    animacao.addAnimacao("Jungle++/img/Personagem/Jogador/Anda.png", "ANDA", 10, 0.12f, sf::Vector2f(6,2), origin);
                    animacao.addAnimacao("Jungle++/img/Personagem/Jogador/Ataca.png", "ATACA", 10, 0.1f, sf::Vector2f(6,2), origin);
                    animacao.addAnimacao("Jungle++/img/Personagem/Jogador/Parado.png", "PARADO", 10, 0.15f, sf::Vector2f(6,2), origin);
                    animacao.addAnimacao("Jungle++/img/Personagem/Jogador/Pula.png", "PULA", 3, 0.15f, sf::Vector2f(6,2), origin);
                    animacao.addAnimacao("Jungle++/img/Personagem/Jogador/Cai.png", "CAI", 3, 0.15f, sf::Vector2f(6,2), origin);
                    animacao.addAnimacao("Jungle++/img/Personagem/Jogador/Morre.png", "MORRE", 10, 0.10f, sf::Vector2f(5,2), origin);
                    animacao.addAnimacao("Jungle++/img/Personagem/Jogador/tomaDano.png", "TOMADANO", 1, 0.5f, sf::Vector2f(6,2), origin);
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
                        const float posY = pos.y;
                        sf::Vector2f posEspada = (paraEsquerda ? sf::Vector2f(pos.x - tamEspada.x, pos.y) : sf::Vector2f(pos.x + tam.x, pos.y));
                        espada->setPos(posEspada);
                    } else {
                        guardarEspada();
                    }

                    atualizarAnimacao();

                    pGrafico->atualizarCamera(sf::Vector2f(pos.x, 300.0f));

                    atualizarBarraVida();
                }

                void Jogador::atualizarBarraVida(){
                    sf::Vector2f posJanela = pGrafico->getCamera().getCenter();
                    sf::Vector2f tamJanela = pGrafico->getTamJanela();
                    sf::Vector2f posBarra = sf::Vector2f(posJanela.x - tamJanela.x / 2.0f + 20.0f, posJanela.y - tamJanela.y / 2.0f + 20.0f);
                    sf::Vector2f tamVida = sf::Vector2f(BARRA_VIDA_JOGADOR_X * 0.6154f, BARRA_VIDA_JOGADOR_Y * 0.25f);
                    tuboBarraVida.setPosition(posBarra);
                    barraVida.setSize(sf::Vector2f(tamVida.x * (vida / 100.0f), tamVida.y));
                    barraVida.setPosition(sf::Vector2f(posBarra.x + BARRA_VIDA_JOGADOR_X * 0.1923f, posBarra.y + BARRA_VIDA_JOGADOR_Y / 2.0f - barraVida.getSize().y / 2.0f));
                }

                void Jogador::atualizarAnimacao(){
                    if(morrendo){
                        animacao.atualizar(paraEsquerda, "MORRE");
                        tempoMorrer += pGrafico->getTempo();
                        if(tempoMorrer > tempoAnimacaoMorrer){
                            podeRemover = true;
                            tempoMorrer = 0.0f;
                        }
                    } else if(!noChao && velFinal.y > 0.0f){
                        animacao.atualizar(paraEsquerda, "CAI");
                    } else if(!noChao){
                        animacao.atualizar(paraEsquerda, "PULA");
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

                void Jogador::colisao(Entidade* outraEntidade, sf::Vector2f ds){
                    switch(outraEntidade->getID()){
                        case(IDs::IDs::plataforma):
                        {
                            
                        }
                        case(IDs::IDs::espada_inimigo):
                        {
                            //std::cout << "Tomar dano do inimigo" << std::endl;
                            Item::Espada* espada = dynamic_cast<Item::Espada*>(outraEntidade);
                            tomarDano(espada->getDano());
                        }
                            break;
                        case(IDs::IDs::esqueleto):
                        {
                            //empura inimigo
                            sf::Vector2f posInimigo = outraEntidade->getPos();
                            Inimigo::Inimigo* inimigo = dynamic_cast<Inimigo::Inimigo*>(outraEntidade);
                            if(pos.x < posInimigo.x){
                                ds.x *= -1;
                            }
                            //inimigo->setPos(sf::Vector2f(posInimigo.x + ds.x, posInimigo.y));
                            //bate no jogador
                            inimigo->parar();
                            inimigo->atacar(true);
                        }
                            break;
                    }   
                }

                void Jogador::pular(){
                    if(noChao){
                        velFinal.y = -sqrt(2.0f * GRAVIDADE * TAMANHO_PULO);
                        noChao = false;
                        atacando = false;
                    }
                }

                const bool Jogador::getNoChao() const {
                    return noChao;
                }

                void Jogador::podePular(){
                    noChao = true;
                }

                void Jogador::mudarEstadoObservador(){
                    observadorJogador->mudarEstadoAtivar();
                }

                void Jogador::addPontuacao(const unsigned int pontos){
                    this->pontos += pontos;
                }

                void Jogador::desenhar(){
                    pGrafico->desenhaElemento(corpo);
                    pGrafico->desenhaElemento(tuboBarraVida);
                    pGrafico->desenhaElemento(barraVida);
                }

            }

        }

    }

}