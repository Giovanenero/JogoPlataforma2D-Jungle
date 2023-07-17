#include "../../../../include/Entidade/Personagem/Inimigo/Alma.hpp"
#include "../../../../include/Entidade/Item/Projetil.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Personagem {

            namespace Inimigo {

                Alma::Alma(const sf::Vector2f pos, Jogador::Jogador* pJogador, Item::Arma* arma):
                    Inimigo(
                        pos, 
                        sf::Vector2f(TAMANHO_ALMA_X, TAMANHO_ALMA_Y), 
                        pJogador, 
                        IDs::IDs::alma, 
                        TEMPO_ALMA_MORRER, 
                        TEMPO_ALMA_ATACAR
                    ), invisivel(false), tempoInvisivel(0.0f)
                {
                    this->pontos = PONTOS_ALMA;
                    inicializarAnimacao();

                    if(arma != nullptr){
                        setArma(arma);
                        arma->setDano(35.0f);
                    }
                }

                Alma::Alma(const std::vector<std::string> atributos, Jogador::Jogador* pJogador):
                    Inimigo(
                        sf::Vector2f(0.0f, 0.0f), 
                        sf::Vector2f(TAMANHO_ALMA_X, TAMANHO_ALMA_Y), 
                        pJogador, 
                        IDs::IDs::alma, 
                        TEMPO_ALMA_MORRER, 
                        TEMPO_ALMA_ATACAR
                    ), invisivel(false), tempoInvisivel(0.0f)
                {
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
                        const bool invisivelAtual = atributos[19] == "1";
                        const float tempoInvisivelAtual = std::stof(atributos[20]);

                        this->pontos = PONTOS_ALMA;
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
                        this->invisivel = invisivelAtual;
                        this->tempoInvisivel = tempoInvisivelAtual;

                        inicializarAnimacao();
                    }
                    catch(const std::exception& e) {
                        std::cerr << e.what() << std::endl;
                        podeRemover = true;
                    }
                    
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

                void Alma::tomarDano(const float dano){
                    if(!levandoDano && !invisivel){
                        vida -= dano;
                        if(vida <= 0.0f){
                            morrendo = true;
                            vida = 0.0f;
                            if(arma != nullptr){
                                arma->remover();
                            }
                        } else {
                            levandoDano = true;
                            invisivel = true;
                            corpo.setFillColor(sf::Color(110, 110, 110, 110));
                        }
                        tempoDano = 0.0f;
                    }
                }

                void Alma::moveInimigo(){
                    if(!morrendo && !atacando){
                        sf::Vector2f posJogador = jogador->getPos();
                        sf::Vector2f tamJogador = jogador->getTam();
                        const float x = fabs((posJogador.x - tamJogador.x / 2.0f) - (pos.x - tam.x / 2.0f));
                        const float y = fabs((posJogador.y - tamJogador.y / 2.0f) - (pos.y - tam.y / 2.0f));
                        if(x <= RECONHECIMENTO_ALMA_X && y <= RECONHECIMENTO_ALMA_Y){
                            paraEsquerda = !(posJogador.x - pos.x > 0.0f); 
                            if(invisivel){
                                //vai fujir do jogador
                                andar(!paraEsquerda);
                                velFinal = sf::Vector2f(velFinal.x * 3.0f, velFinal.y);
                            } else {
                                parar();
                                if(arma != nullptr){
                                    Item::Projetil* projetil = dynamic_cast<Item::Projetil*>(arma);
                                    if(projetil->getColidiu()){
                                        tempoAtacar += pGrafico->getTempo() * 0.5f;
                                        if(tempoAtacar > tempoAnimacaoAtacar){
                                            atacando = true;
                                            tempoAtacar = 0.0f;
                                        }
                                    }
                                }
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
                    const float tempo = pGrafico->getTempo();
                    if(atacando){
                        tempoAtacar += tempo;
                        if(tempoAtacar > tempoAnimacaoAtacar){
                            if(arma == nullptr){
                                std::cout << "ERRO::Personagem::Inimigo::Alma::inicializar a arma primeiro" << std::endl;
                                exit(1);
                            }
                            //vai lançar o projétil
                            Item::Projetil* projetil = dynamic_cast<Item::Projetil*>(arma);
                            projetil->setPos(sf::Vector2f(pos.x + tam.x / 2.0f, pos.y + tam.y / 5.0f));
                            projetil->setColidiu(false);
                            projetil->setVelocidade(sf::Vector2f(110.0f, 1.0f));
                            projetil->setSentido(paraEsquerda);
                            atacando = false;
                            tempoAtacar = 0.0f;
                        }
                    }
                    if(invisivel){
                        tempoInvisivel += tempo;
                        if(tempoInvisivel > TEMPO_ALMA_INVISIVEL){
                            tempoInvisivel = 0.0f;
                            invisivel = false;
                            corpo.setFillColor(sf::Color(255, 255, 255, 255));
                        }
                    }
                }

                const std::string Alma::salvar(){
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
                    linha += std::to_string(tempoAtacar) + ' ';
                    //salvando atributos da alma
                    linha += std::to_string(invisivel) + ' ';
                    linha += std::to_string(tempoInvisivel);
                    //ainda n tem
                    return linha;
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