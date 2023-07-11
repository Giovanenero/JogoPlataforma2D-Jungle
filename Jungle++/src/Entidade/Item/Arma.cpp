#include "../../../include/Entidade/Item/Arma.hpp"
#include "../../../include/Entidade/Personagem/Inimigo/Esqueleto.hpp"
#include "../../../include/Entidade/Personagem/Inimigo/Alma.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Item {

            Arma::Arma(const IDs::IDs ID, Personagem::Personagem* personagem):
                Entidade(sf::Vector2f(0.0f, 0.0f), ID), dano(0.0f), personagem(personagem)
            {
                //corpo.setFillColor(sf::Color::Transparent);
            }

            Arma::~Arma(){

            }

            void Arma::setPersonagem(Personagem::Personagem* personagem){
                this->personagem = personagem;
            }

            void Arma::setDano(const float dano){
                this->dano = dano;
            }

            const float Arma::getDano() const {
                return dano;
            }

            void Arma::colisao(Entidade* outraEntidade, sf::Vector2f ds){
                if(ID == IDs::IDs::espada_jogador){
                    switch(outraEntidade->getID()){
                        case (IDs::IDs::minotauro):
                        {
                            std::cout << "Bater no minotauro" << std::endl;
                            //std::cout << "Empurra inimigo" << std::endl;
                        }
                            break;
                        case(IDs::IDs::esqueleto):
                        {
                            Personagem::Inimigo::Esqueleto* esqueleto = dynamic_cast<Personagem::Inimigo::Esqueleto*>(outraEntidade);
                            if(!esqueleto->getMorrer()){
                                esqueleto->tomarDano(dano);
                                if(esqueleto->getMorrer()){
                                    Personagem::Jogador::Jogador* jogador = dynamic_cast<Personagem::Jogador::Jogador*>(personagem);
                                    jogador->addPontuacao(esqueleto->getPontos());
                                    std::cout << jogador->getPontos() << std::endl;
                                }
                            }
                        }
                            break;
                        case (IDs::IDs::alma):
                        {
                            Personagem::Inimigo::Alma* alma = dynamic_cast<Personagem::Inimigo::Alma*>(outraEntidade);
                            if(!alma->getMorrer()){
                                alma->tomarDano(dano);
                                if(alma->getMorrer()){
                                    Personagem::Jogador::Jogador* jogador = dynamic_cast<Personagem::Jogador::Jogador*>(personagem);
                                    jogador->addPontuacao(alma->getPontos());
                                    std::cout << jogador->getPontos() << std::endl;
                                }
                            }
                        }
                            break;
                    }
                } else if(ID == IDs::IDs::projetil_inimigo){
                    if(outraEntidade->getID() == IDs::IDs::jogador){
                        std::cout << "projetil colidiu com jogador" << std::endl;
                    }
                }
            }

            void Arma::atualizar(){

            }

            void Arma::desenhar(){
                
            }

        }

    }

}