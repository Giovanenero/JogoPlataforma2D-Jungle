#include "../../../include/Entidade/Obstaculo/Obstaculo.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Obstaculo {

            Obstaculo::Obstaculo(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID, const char* caminhoTextura):
                Entidade(tam, ID, pos)
            {
                textura = pGrafico->carregarTextura(caminhoTextura);
                corpo.setTexture(&textura);
            }

            Obstaculo::~Obstaculo(){

            }

            void Obstaculo::atualizar(){
                desenhar();
            }

            void Obstaculo::colisaoObstaculo(sf::Vector2f ds, Personagem::Personagem* pPersonagem){
                sf::Vector2f posOutro = pPersonagem->getPos();
                sf::Vector2f tamOutro = pPersonagem->getTam();
                sf::Vector2f velFinal = pPersonagem->getVelFinal();
                if(ds.x < 0.0f && ds.y < 0.0f){ //houve colisao
                    if(ds.x > ds.y){
                        if(posOutro.x < pos.x){ //colisão em x
                            posOutro.x += ds.x;
                        } else {
                            posOutro.x -= ds.x;
                        }
                        velFinal.x = 0.0f;
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

            const std::string Obstaculo::salvar(){
                std::string linha = "";
                //salvando atributos da entidade
                linha += std::to_string(static_cast<int>(ID)) + ' ';
                linha += std::to_string(pos.x) + ' ';
                linha += std::to_string(pos.y) + ' ';
                linha += std::to_string(tam.x) + ' ';
                linha += std::to_string(tam.y);
                return linha;
            }

        }

    }

}