#include "..\..\..\include\Entidade\Item\Espada.hpp"
#include "../../../include/Entidade/Personagem/Inimigo/Esqueleto.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Item {

            Espada::Espada(const IDs::IDs ID, Entidade* entidade):
                Entidade(sf::Vector2f(0.0f, 0.0f), ID), dano(dano), entidade(entidade)
            {

            }

            Espada::~Espada(){

            }

            void Espada::setEntidade(Entidade* entidade){
                this->entidade = entidade;
            }

            void Espada::setDano(const float dano){
                this->dano = dano;
            }

            const float Espada::getDano() const {
                return dano;
            }

            void Espada::colisao(Entidade* outraEntidade, sf::Vector2f ds){
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
                                    Personagem::Jogador::Jogador* jogador = dynamic_cast<Personagem::Jogador::Jogador*>(entidade);
                                    jogador->addPontuacao(esqueleto->getPontos());
                                    std::cout << jogador->getPontos() << std::endl;
                                }
                            }
                        }
                            break;
                    }
                }
            }

            void Espada::atualizar(){

            }

        }

    }

}