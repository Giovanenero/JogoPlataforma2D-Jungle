#include "../../../include/Entidade/Obstaculo/Porta.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Obstaculo {

            Porta::Porta(const sf::Vector2f pos, const sf::Vector2f tam, Item::Chave* chave):
                Obstaculo(pos, tam, IDs::IDs::porta), animacao(&corpo), tempoAbrindo(0.0f),
                fechada(true), abrindo(false), chave(chave), mostrarTexto(false),
                textoPorta(pGrafico->carregarFonte("Jungle++/fonte/menuColocacao.ttf"), "Encontre a Chave", 30),
                caixaTexto(), coletou(false), fundoPorta()
            {
                inicializarAnimacao();
                inicializarTexto();
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
                }
            }

            void Porta::inicializarTexto(){
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

            void Porta::setMostrarTexto(const bool mostrarTexto){
                this->mostrarTexto = mostrarTexto;
            }

            void Porta::colidindoJogador(Personagem::Jogador::Jogador* pJogador){
                if(!coletou){
                    std::vector<Item::Chave*> vectorChaves = pJogador->getChaves();
                    for(int i = 0; i < vectorChaves.size() && !coletou; i++){
                        if(vectorChaves[i] == chave){
                            textoPorta.setString("Pressione 'K' para Abrir");
                            sf::Vector2f tamTexto = textoPorta.getTam();
                            textoPorta.setPos(sf::Vector2f(
                                pos.x + tam.x / 2.0f - tamTexto.x / 2.0f,
                                pos.y - tamTexto.y - 10.0f
                            ));
                            caixaTexto.setSize(tamTexto + sf::Vector2f(15.0f, 15.0f));
                            caixaTexto.setPosition(textoPorta.getPos() + sf::Vector2f(-15.0f / 2.0f, 15.0f / 2.0f));
                            coletou = true;
                        }
                    }
                    mostrarTexto = true;
                } else {
                    mostrarTexto = true;
                    if(fechada && pJogador->getAbrirPorta()){
                        fechada = false;
                        abrindo = true;
                        textoPorta.setString("Pressione 'K' para Entrar");
                        sf::Vector2f tamTexto = textoPorta.getTam();
                        textoPorta.setPos(sf::Vector2f(
                            pos.x + tam.x / 2.0f - tamTexto.x / 2.0f,
                            pos.y - tamTexto.y - 10.0f
                        ));
                        caixaTexto.setSize(tamTexto + sf::Vector2f(15.0f, 15.0f));
                        caixaTexto.setPosition(textoPorta.getPos() + sf::Vector2f(-15.0f / 2.0f, 15.0f / 2.0f));
                    } else if(abrindo){
                        mostrarTexto = false;
                    } else if(pJogador->getAbrirPorta()){
                        std::cout << "Entrar" << std::endl;
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
            
            void Porta::atualizar(){
                atualizarAnimacao();
                if(mostrarTexto){
                    pGrafico->desenhaElemento(caixaTexto);
                    pGrafico->desenhaElemento(textoPorta.getTexto());
                    mostrarTexto = false;
                }
                if(!fechada){
                    pGrafico->desenhaElemento(fundoPorta);
                }
                desenhar();
            }

        }

    }

}