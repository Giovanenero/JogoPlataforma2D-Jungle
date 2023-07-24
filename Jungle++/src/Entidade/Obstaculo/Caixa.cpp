#include "../../../include/Entidade/Obstaculo/Caixa.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Obstaculo {

            Caixa::Caixa(sf::Vector2f pos):
                Obstaculo(pos, sf::Vector2f(TAMANHO_CAIXA_X, TAMANHO_CAIXA_Y), IDs::IDs::caixa), lentidao(0.25f)
            {
                inicializarAnimacao();
            }

            Caixa::Caixa(const std::vector<std::string> atributos):
                Obstaculo(pos, sf::Vector2f(TAMANHO_CAIXA_X, TAMANHO_CAIXA_Y), IDs::IDs::caixa), lentidao(0.25f)
            {
                try {
                    sf::Vector2f posAtual = sf::Vector2f(std::stof(atributos[1]), std::stof(atributos[2]));
                    sf::Vector2f tamAtual = sf::Vector2f(std::stof(atributos[3]), std::stof(atributos[4]));

                    setPos(posAtual);
                    setTam(tamAtual);

                    inicializarAnimacao();
                }
                catch(const std::exception& e) {
                    std::cerr << e.what() << std::endl;
                    podeRemover = true;
                }
                
            }

            Caixa::~Caixa(){

            }

            void Caixa::inicializarAnimacao(){
                textura = pGrafico->carregarTextura(CAMINHO_TEXTURA_CAIXA);
                corpo.setTexture(&textura);
            }

            void Caixa::colisao(Entidade* outraEntidade, sf::Vector2f ds){
                sf::Vector2f posOutro = outraEntidade->getPos();
                sf::Vector2f tamOutro = outraEntidade->getTam();

                if(outraEntidade->getID() == IDs::IDs::jogador || outraEntidade->getID() == IDs::IDs::esqueleto ||
                    outraEntidade->getID() == IDs::IDs::minotauro
                ){
                    colisaoObstaculo(ds, static_cast<Personagem::Personagem*>(outraEntidade));
                }
            }

            void Caixa::colisaoObstaculo(sf::Vector2f ds, Personagem::Personagem* pPersonagem){
                sf::Vector2f posOutro = pPersonagem->getPos();
                sf::Vector2f tamOutro = pPersonagem->getTam();
                sf::Vector2f velFinal = pPersonagem->getVelFinal();
                if(ds.x < 0.0f && ds.y < 0.0f){ //houve colisao
                    if(ds.x > ds.y){
                        if(pPersonagem->getID() == IDs::IDs::jogador){
                            velFinal.x *= lentidao;
                            if(posOutro.x < pos.x){ //colisão em x
                                pos.x -= ds.x;
                            } else {
                                pos.x += ds.x;
                            }
                            setPos(pos);
                        } else {
                            if(posOutro.x < pos.x){ //colisão em x
                                posOutro.x += ds.x;
                            } else {
                                posOutro.x -= ds.x;
                            }
                        }
                    } else {
                        if(posOutro.y < pos.y){ //colisão em y
                            posOutro.y += ds.y;
                            if(pPersonagem->getID() == IDs::IDs::jogador){
                                Personagem::Jogador::Jogador* pJogador = static_cast<Personagem::Jogador::Jogador*>(pPersonagem);
                                pJogador->podePular();
                            }
                        } else {
                            posOutro.y -= ds.y;
                        }
                        velFinal.y = 0.0f;
                    }
                }
                pPersonagem->setPos(posOutro);
                pPersonagem->setVelFinal(velFinal);
            }

        }

    }

}