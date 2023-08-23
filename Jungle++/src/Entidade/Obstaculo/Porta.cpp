#include "../../../include/Entidade/Obstaculo/Porta.hpp"
#include "../../../include/Gerenciador/GerenciadorEstado.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Obstaculo {

            Porta::Porta(const sf::Vector2f pos, const sf::Vector2f tam, Item::Chave* chave, const IDs::IDs ID_Fase):
                Obstaculo(pos, tam, IDs::IDs::porta), animacao(&corpo), tempoAbrindo(0.0f),
                fechada(true), abrindo(false), chave(chave), mostrarTexto(false), ID_Fase(ID_Fase),
                textoPorta(pGrafico->carregarFonte("Jungle++/fonte/menuColocacao.ttf"), "", 30),
                caixaTexto(), coletou(false), fundoPorta()
            {
                inicializarAnimacao();
                if(chave == nullptr){
                    inicializarTexto("Pressione 'K' para Entrar");
                    coletou = true;
                    fechada = false;
                } else {
                    inicializarTexto("Encontre a Chave");
                }
            }

            Porta::Porta(const std::vector<std::string> atributos, Item::Chave* chave):
                Obstaculo(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(0.0f, 0.0f), IDs::IDs::porta), 
                animacao(&corpo), chave(chave), fundoPorta(), caixaTexto(),
                textoPorta(pGrafico->carregarFonte("Jungle++/fonte/menuColocacao.ttf"), "", 30)
            {
                try {
                    const sf::Vector2f posAtual = sf::Vector2f(std::stof(atributos[1]), std::stof(atributos[2]));
                    const sf::Vector2f tamAtual = sf::Vector2f(std::stof(atributos[3]), std::stof(atributos[4]));
                    const bool fechadaAtual = atributos[5] == "1";
                    const bool abrindoAtual = atributos[6] == "1";
                    const float tempoAbrindoAtual = std::stof(atributos[7]);
                    const std::string imgAtual = atributos[8];
                    const unsigned int quadroAtual = std::stoi(atributos[9]);
                    const float tempoTotalAtual = std::stof(atributos[10]);
                    const bool mostrarTextoAtual = atributos[11] == "1";
                    const bool coletouAtual = atributos[12] == "1";
                    switch (std::stoi(atributos[13]))
                    {
                    case (53):
                        this->ID_Fase = IDs::IDs::floresta_branca_parte_1;
                        break;
                    case (54):
                        this->ID_Fase = IDs::IDs::floresta_branca_parte_2;
                        break;
                    case (55):
                        this->ID_Fase = IDs::IDs::floresta_branca_parte_3;
                        break;
                    default:
                        std::cout << "ERRO::Erro ao recuperar porta, pois o  Id da fase atual eh invalido" << std::endl;
                        exit(1);
                        break;
                    }

                    setPos(posAtual);
                    setTam(tamAtual);
                    this->fechada = fechadaAtual;
                    this->abrindo = abrindoAtual;
                    this->tempoAbrindo = tempoAbrindoAtual;
                    inicializarAnimacao();
                    animacao.setImgAtual(imgAtual);
                    animacao.setQuadroAtual(quadroAtual);
                    animacao.setTempoTotal(tempoAbrindoAtual);
                    this->mostrarTexto = mostrarTextoAtual;
                    this->coletou = coletouAtual;

                    if(!coletou){
                        inicializarTexto("Encontre a Chave");
                    } else if(fechada){
                        inicializarTexto("Pressione 'K' para Abrir");
                    } else {
                        inicializarTexto("Pressione 'K' para Entrar");
                    }
                } catch(const std::exception& e) {
                    std::cerr << e.what() << std::endl;
                    podeRemover = true;
                }
                
            }

            Porta::~Porta(){

            }

            void Porta::inicializarAnimacao(){
                sf::Vector2f origin(0.0f, -10.0f);
                animacao.addAnimacao("Jungle++/img/Obstaculo/Porta/portaAbrindo.png", "PORTA_ABRINDO", 14, 0.10f, sf::Vector2f(1.0f, 1.0f), origin);
                animacao.addAnimacao("Jungle++/img/Obstaculo/Porta/portaAberta.png", "PORTA_ABERTA", 1, 1.0f, sf::Vector2f(1.0f, 1.0f), origin);
                animacao.addAnimacao("Jungle++/img/Obstaculo/Porta/portaFechada.png", "PORTA_FECHADA", 1, 1.0f, sf::Vector2f(1.0f, 1.0f), origin);
                fundoPorta.setSize(sf::Vector2f(tam.x * 0.8f, tam.y * 0.6f));
                fundoPorta.setPosition(sf::Vector2f(pos.x + tam.x / 2.0f - (tam.x * 0.8f) / 2.0f, pos.y + tam.y - tam.y * 0.55f));
                fundoPorta.setFillColor(sf::Color::Black);
            }

            void Porta::atualizarAnimacao(){
                if(fechada){
                    animacao.atualizar(true, "PORTA_FECHADA");
                } else if(abrindo){
                    tempoAbrindo += pGrafico->getTempo();
                    animacao.atualizar(true, "PORTA_ABRINDO");
                    if(tempoAbrindo > TEMPO_PORTA_ABRINDO){
                        tempoAbrindo = 0.0f;
                        abrindo = false;
                    }
                } else {
                    animacao.atualizar(true, "PORTA_ABERTA");
                    if(tempoAbrindo < TEMPO_ENTRAR){
                        tempoAbrindo += pGrafico->getTempo();
                    }
                }
            }

            void Porta::inicializarTexto(std::string texto){
                textoPorta.setString(texto);
                textoPorta.setTamanhoBorda(1);
                textoPorta.setEspacamento(0.6f);
                textoPorta.setPos(sf::Vector2f(
                    pos.x + tam.x / 2.0f - textoPorta.getTam().x / 2.0f, 
                    pos.y - textoPorta.getTam().y - 10.0f
                ));
                caixaTexto.setSize(textoPorta.getTam() + sf::Vector2f(15.0f, 15.0f));
                caixaTexto.setPosition(sf::Vector2f(textoPorta.getPos() + sf::Vector2f(-15.0f / 2.0f, 15.0f / 2.0f)));
                caixaTexto.setFillColor(sf::Color(0,0,0,100));
            }
            
            Item::Chave* Porta::getChave(){
                return chave;
            }

            const IDs::IDs Porta::getIDFase() const{
                return ID_Fase;
            }

            void Porta::colidindoJogador(Personagem::Jogador::Jogador* pJogador){
                if(!coletou){
                    std::vector<Item::Chave*> vectorChaves = pJogador->getChaves();
                    for(int i = 0; i < vectorChaves.size() && !coletou; i++){
                        if(vectorChaves[i] == chave){
                            inicializarTexto("Pressione 'K' para Abrir");
                            coletou = true;
                        }
                    }
                    mostrarTexto = true;
                } else {
                    mostrarTexto = true;
                    if(fechada && pJogador->getAbrirPorta()){
                        fechada = false;
                        abrindo = true;
                        inicializarTexto("Pressione 'K' para Entrar");
                        pJogador->removerChave(chave);
                        chave->remover();
                        chave = nullptr;
                    } else if(abrindo){
                        mostrarTexto = false;
                    } else if(pJogador->getAbrirPorta() && tempoAbrindo >= TEMPO_ENTRAR){
                        Gerenciador::GerenciadorEstado* pGEstado = Gerenciador::GerenciadorEstado::getGerenciadorEstado();
                        Estado::EstadoJogar* estadoJogar = dynamic_cast<Estado::EstadoJogar*>(pGEstado->getEstadoAtual());
                        pJogador->setAbrirPorta(false);
                        tempoAbrindo = 0.0f;
                        estadoJogar->mudarFase(ID_Fase);
                    }
                } 
                pJogador->setColidindoPorta(true);
            }

            void Porta::colisao(Entidade* outraEntidade, sf::Vector2f ds){
                if(outraEntidade->getID() == IDs::IDs::jogador){
                    Personagem::Jogador::Jogador* pJogador = dynamic_cast<Personagem::Jogador::Jogador*>(outraEntidade);
                    colidindoJogador(pJogador);
                }
            }

            const std::string Porta::salvar(){
                std::string linha = salvarObstaculo();
                linha += std::to_string(fechada) + ' ';
                linha += std::to_string(abrindo) + ' ';
                linha += std::to_string(tempoAbrindo) + ' ';
                linha += animacao.getImgAtual() + ' ';
                linha += std::to_string(animacao.getQuadroAtual()) + ' ';
                linha += std::to_string(animacao.getTempoTotal()) + ' ';
                //linha += textoPorta.getString() + ' ';
                linha += std::to_string(mostrarTexto) + ' ';
                linha += std::to_string(coletou) + ' ';
                linha += std::to_string(static_cast<int>(ID_Fase));
                return linha;
            }

            void Porta::desenhar(){
                if(mostrarTexto){
                    pGrafico->desenhaElemento(caixaTexto);
                    pGrafico->desenhaElemento(textoPorta.getTexto());
                }
                if(!fechada){
                    pGrafico->desenhaElemento(fundoPorta);
                }
                pGrafico->desenhaElemento(corpo);
            }
            
            void Porta::atualizar(){
                atualizarAnimacao();
                desenhar();
                mostrarTexto = false;
            }

        }

    }

}