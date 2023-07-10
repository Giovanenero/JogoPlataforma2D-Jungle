#include "../../../include/Entidade/Item/Arma.hpp"
#include "../../../include/Entidade/Personagem/Inimigo/Esqueleto.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Item {

            Arma::Arma(const IDs::IDs ID, Personagem::Personagem* personagem):
                Entidade(sf::Vector2f(0.0f, 0.0f), ID), dano(dano), personagem(personagem)
            {
                corpo.setFillColor(sf::Color::Transparent);
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