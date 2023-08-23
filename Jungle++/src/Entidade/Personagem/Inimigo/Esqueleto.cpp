#include "../../../../include/Entidade/Personagem/Inimigo/Esqueleto.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Personagem {

            namespace Inimigo {

                Esqueleto::Esqueleto(const sf::Vector2f pos, const int nivel, Jogador::Jogador* jogador):
                    Inimigo(
                        pos, 
                        sf::Vector2f(TAMANHO_ESQUELO_X, TAMANHO_ESQUELO_Y), 
                        jogador, 
                        IDs::IDs::esqueleto, 
                        TEMPO_ESQUELETO_MORRER,
                        2.0f,
                        EXPERIENCIA_ESQUELETO * nivel * 0.5f
                    ), raiva(false), tempoRaiva(0.0f)
                {
                    this->nivel.setNivel(nivel);
                    this->pontos = PONTOS_ESQUELETO;
                    inicializarAnimacao();
                    inicializarNivel();
                }

                Esqueleto::Esqueleto(const std::vector<std::string> atributos, Jogador::Jogador* jogador):
                    Inimigo(
                        sf::Vector2f(0.0f, 0.0f), 
                        sf::Vector2f(TAMANHO_ESQUELO_X, TAMANHO_ESQUELO_Y), 
                        jogador, 
                        IDs::IDs::esqueleto, 
                        TEMPO_ESQUELETO_MORRER,
                        2.0f,
                        EXPERIENCIA_ESQUELETO
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
                        const float nivelAtual = std::stoi(atributos[16]);
                        const float experienciaAtual = std::stof(atributos[17]);
                        const short moveAleatorioAtual = std::stol(atributos[18]);
                        const float tempoMoverAtual = std::stof(atributos[19]);
                        const float tempoAtacarAtual = std::stof(atributos[20]);
                        const std::string imgAtual = atributos[21];
                        const unsigned int quadroAtual = std::stoi(atributos[22]);
                        const float tempoTotalAtual = std::stof(atributos[23]);
                        const bool raivaAtual = atributos[24] == "1";
                        const float tempoRaivaAtual = std::stof(atributos[25]);

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
                        inicializarNivel();
                        nivel.setNivel(nivelAtual);
                        nivel.addExp(experienciaAtual);
                        this->moveAleatorio = moveAleatorioAtual;
                        this->tempoMover = tempoMoverAtual;
                        this->tempoAtacar = tempoAtacarAtual;
                        this->raiva = raivaAtual;
                        this->tempoRaiva = tempoRaivaAtual;

                        inicializarAnimacao();
                        animacao.setImgAtual(imgAtual);
                        animacao.setQuadroAtual(quadroAtual);
                        animacao.setTempoTotal(tempoTotalAtual);
                    }
                    catch(const std::exception& e)
                    {
                        std::cerr << e.what() << std::endl;
                        podeRemover = true;
                    }
                    
                }

                Esqueleto::~Esqueleto(){

                }

                void Esqueleto::inicializarAnimacao(){
                    const sf::Vector2f origin = sf::Vector2f(tam.x / 12.0f, tam.y / 10.0f);
                    animacao.addAnimacao("Jungle++/img/Personagem/Inimigo/Esqueleto/Parado.png", "PARADO", 11, 0.12f, sf::Vector2f(1.0f, 1.10f), origin);
                    animacao.addAnimacao("Jungle++/img/Personagem/Inimigo/Esqueleto/Anda.png", "ANDA", 13, 0.15f, sf::Vector2f(1.0f, 1.10f), origin);
                    animacao.addAnimacao("Jungle++/img/Personagem/Inimigo/Esqueleto/Morre.png", "MORRE", 15, 0.10f, sf::Vector2f(1.5f, 1.10f), origin);
                    animacao.addAnimacao("Jungle++/img/Personagem/Inimigo/Esqueleto/tomaDano.png", "TOMADANO", 8, 0.15f, sf::Vector2f(1.2f, 1.10f), origin);
                    animacao.addAnimacao("Jungle++/img/Personagem/Inimigo/Esqueleto/Ataca.png", "ATACA", 18, 0.15f, sf::Vector2f(1.95f, 1.3f), sf::Vector2f(tam.x / 3.0f, tam.y / 4.0f));
                    corPadrao = corpo.getFillColor();
                    if(raiva){
                        corpo.setFillColor(sf::Color(180, 0, 0));
                    }
                }

                void Esqueleto::inicializarNivel(){
                    textoNivel.setString("Lv." + std::to_string(nivel.getNivel()));
                    textoNivel.setTamanhoBorda(2);
                    if(arma != nullptr){
                        setArma(arma);
                        arma->setDano(this->nivel.getForca());
                    }
                }

                void Esqueleto::atualizarRaiva(){
                    if(raiva){
                        tempoRaiva += pGrafico->getTempo();
                        if(tempoRaiva > 8.0f){
                            tempoRaiva = 0.0f;
                            corpo.setFillColor(corPadrao);
                            raiva = false;
                        }
                    }
                }

                void Esqueleto::atualizarAnimacao(){
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
                    } else if(levandoDano && !raiva){
                        animacao.atualizar(paraEsquerda, "TOMADANO");
                    } else if(atacando){
                        animacao.atualizar(paraEsquerda, "ATACA");
                    } else if(andando){
                        animacao.atualizar(paraEsquerda, "ANDA");
                    } else {
                        animacao.atualizar(paraEsquerda, "PARADO");
                    }
                }

                void Esqueleto::tomarDano(const float dano){
                    if(!levandoDano){
                        levandoDano = true;
                        if(!raiva && rand()%2 == 1){
                            corpo.setFillColor(sf::Color(180, 0, 0));
                            raiva = true;
                        }
                        vida -= dano * (dano / (dano + nivel.getDefesa()));
                        if(vida <= 0.0f){
                            morrendo = true;
                            vida = 0.0f;
                            if(arma != nullptr){
                                arma->remover();
                            }
                        }
                        tempoDano = 0.0f;
                    }
                }

                const std::string Esqueleto::salvar(){
                    std::string linha = salvarInimigo();
                    linha += std::to_string(raiva) + ' ';
                    linha += std::to_string(tempoRaiva);
                    return linha;
                }

                void Esqueleto::atualizarTempoAtacar(){
                    if(atacando && (raiva || !levandoDano)){
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
                    } else if(levandoDano && !raiva){
                        tempoAtacar = 0.0f;
                        atacando = false;
                        arma->setPos(sf::Vector2f(-1000.0f, -1000.0f));
                    }
                    atualizarRaiva();
                }

                void Esqueleto::moveInimigo(){
                    if((raiva || !levandoDano) && !morrendo && !atacando){
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

            }

        }

    }

}