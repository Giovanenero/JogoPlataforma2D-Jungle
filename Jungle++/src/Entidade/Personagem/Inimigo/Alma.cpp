#include "../../../../include/Entidade/Personagem/Inimigo/Alma.hpp"
#include "../../../../include/Entidade/Item/Projetil.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Personagem {

            namespace Inimigo {

                Alma::Alma(const sf::Vector2f pos, const int nivel, Jogador::Jogador* pJogador, Item::Arma* arma):
                    Inimigo(
                        pos, 
                        sf::Vector2f(TAMANHO_ALMA_X, TAMANHO_ALMA_Y), 
                        pJogador, 
                        IDs::IDs::alma, 
                        TEMPO_ALMA_MORRER, 
                        TEMPO_ALMA_ATACAR,
                        EXPERIENCIA_ALMA * nivel * 0.5f
                    ), invisivel(false), tempoInvisivel(0.0f)
                {
                    this->nivel.setNivel(nivel);
                    this->pontos = PONTOS_ALMA;
                    inicializarAnimacao();
                    inicializarNivel();
                }

                Alma::Alma(const std::vector<std::string> atributos, Jogador::Jogador* pJogador):
                    Inimigo(
                        sf::Vector2f(0.0f, 0.0f), 
                        sf::Vector2f(TAMANHO_ALMA_X, TAMANHO_ALMA_Y), 
                        pJogador, 
                        IDs::IDs::alma, 
                        TEMPO_ALMA_MORRER, 
                        TEMPO_ALMA_ATACAR,
                        EXPERIENCIA_ALMA
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
                        const float nivelAtual = std::stoi(atributos[16]);
                        const float experienciaAtual = std::stof(atributos[17]);
                        const short moveAleatorioAtual = std::stol(atributos[18]);
                        const float tempoMoverAtual = std::stof(atributos[19]);
                        const float tempoAtacarAtual = std::stof(atributos[20]);
                        const std::string imgAtual = atributos[21];
                        const unsigned int quadroAtual = std::stoi(atributos[22]);
                        const float tempoTotalAtual = std::stof(atributos[23]);
                        const bool invisivelAtual = atributos[24] == "1";
                        const float tempoInvisivelAtual = std::stof(atributos[25]);

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
                        inicializarNivel();
                        nivel.setNivel(nivelAtual);
                        nivel.addExp(experienciaAtual);
                        this->moveAleatorio = moveAleatorioAtual;
                        this->tempoMover = tempoMoverAtual;
                        this->tempoAtacar = tempoAtacarAtual;
                        this->invisivel = invisivelAtual;
                        this->tempoInvisivel = tempoInvisivelAtual;

                        inicializarAnimacao();
                        animacao.setImgAtual(imgAtual);
                        animacao.setQuadroAtual(quadroAtual);
                        animacao.setTempoTotal(tempoTotalAtual);
                    }
                    catch(const std::exception& e) {
                        std::cerr << "ERRO::Alma::" << e.what() << std::endl;
                        podeRemover = true;
                    }
                    
                }

                Alma::~Alma(){
                    if(arma != nullptr){
                        arma->remover();
                    }
                }

                void Alma::inicializarAnimacao(){
                    const sf::Vector2f origin = sf::Vector2f(tam.x / 4.0f, tam.y / 4.4f);
                    animacao.addAnimacao("Jungle++/img/Personagem/Inimigo/Alma/Parado.png", "PARADO", 5, 0.12f, sf::Vector2f(2.5f, 1.5f), origin, false);
                    animacao.addAnimacao("Jungle++/img/Personagem/Inimigo/Alma/Anda.png", "ANDA", 8, 0.15f, sf::Vector2f(2.5f, 1.5f), origin, false);
                    animacao.addAnimacao("Jungle++/img/Personagem/Inimigo/Alma/Morre.png", "MORRE", 8, 0.2f, sf::Vector2f(2.5f, 1.5f), origin, false);
                    animacao.addAnimacao("Jungle++/img/Personagem/Inimigo/Alma/Ataca.png", "ATACA", 10, 0.3f, sf::Vector2f(2.5f, 1.5f), origin, false);
                }

                void Alma::tomarDano(const float dano){
                    if(!levandoDano && !invisivel){
                        vida -= dano * (dano / (dano + nivel.getDefesa()));
                        if(vida <= 0.0f){
                            morrendo = true;
                            vida = 0.0f;
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
                            projetil->setVelocidade(sf::Vector2f(250.0f, 5.0f));
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

                void Alma::inicializarNivel(){
                    textoNivel.setString("Lv." + std::to_string(nivel.getNivel()));
                    textoNivel.setTamanhoBorda(2);
                    nivel.setForca(FORCA_ALMA);
                    nivel.setDefesa(DEFESA_ALMA);
                    nivel.setVitalidade(VITALIDADE_ALMA);
                    if(arma != nullptr){
                        setArma(arma);
                        arma->setDano(this->nivel.getForca());
                    }
                }

                const std::string Alma::salvar(){
                    std::string linha = salvarInimigo();
                    linha += std::to_string(invisivel) + ' ';
                    linha += std::to_string(tempoInvisivel);
                    return linha;
                }

                void Alma::atualizarAnimacao(){
                    if(morrendo){
                        animacao.atualizar(paraEsquerda, "MORRE");
                        tempoMorrer += pGrafico->getTempo();
                        if(tempoMorrer > tempoAnimacaoMorrer){
                            if(arma != nullptr){
                                Item::Projetil* projetil = dynamic_cast<Item::Projetil*>(arma);
                                if(projetil->getColidiu()){
                                    arma->remover();
                                    arma = nullptr;
                                    podeRemover = true;
                                }
                                //tempoMorrer = 0.0f;
                             else {
                                podeRemover = true;
                             }}
                            corpo.setFillColor(sf::Color::Transparent);
                            textoNivel.setCorTexto(sf::Color::Transparent);
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