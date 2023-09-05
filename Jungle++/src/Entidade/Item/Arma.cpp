#include "../../../include/Entidade/Item/Arma.hpp"
#include "../../../include/Entidade/Personagem/Inimigo/Esqueleto.hpp"
#include "../../../include/Entidade/Personagem/Inimigo/Alma.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Item {

            Arma::Arma(const IDs::IDs ID, Personagem::Personagem* personagem):
                Entidade(sf::Vector2f(-1000.0f, -1000.0f), ID), dano(0.0f), personagem(personagem)
            {
                //corpo.setFillColor(sf::Color::Transparent);
            }

            Arma::Arma(const IDs::IDs ID, const std::vector<std::string> atributos):
                Entidade(sf::Vector2f(-1000.0f, -1000.0f), ID), dano(0.0f), personagem(nullptr)
            {
                try {
                    const sf::Vector2f posAtual = sf::Vector2f(std::stof(atributos[1]), std::stof(atributos[2]));
                    const sf::Vector2f tamAtual = sf::Vector2f(std::stof(atributos[3]), std::stof(atributos[4]));
                    const float danoAtual = std::stof(atributos[5]);

                    setPos(posAtual);
                    setTam(tamAtual);
                    this->dano = danoAtual;
                }
                catch(const std::exception& e) {
                    std::cerr << e.what() << std::endl;
                    //Generalizando a posição, tamanho e dano se algo der errado;
                    setPos(sf::Vector2f(-1000.0f, -1000.0f));
                    setTam(sf::Vector2f(50.0f, 90.0f));
                    dano = 20.0f;
                }
                
            }

            Arma::~Arma(){

            }

            const std::string Arma::salvarArma(){
                std::string linha = salvarEntidade();
                linha += std::to_string(dano) + ' ';
                return linha;
            }

            void Arma::setPersonagem(Personagem::Personagem* personagem){
                this->personagem = personagem;
                dano = personagem->getForca();
            }

            void Arma::setDano(const float dano){
                this->dano = dano;
            }

            const float Arma::getDano() const {
                return dano;
            }

            void Arma::colisao(Entidade* outraEntidade, sf::Vector2f ds){
                if(ID == IDs::IDs::espada_jogador){
                    if(
                        outraEntidade->getID() == IDs::IDs::esqueleto || 
                        outraEntidade->getID() == IDs::IDs::alma ||
                        outraEntidade->getID() == IDs::IDs::carniceiro
                    ){
                        Personagem::Inimigo::Inimigo* inimigo = dynamic_cast<Personagem::Inimigo::Inimigo*>(outraEntidade);
                            if(!inimigo->getMorrer()){
                                inimigo->tomarDano(dano);
                                if(inimigo->getMorrer()){
                                    Personagem::Jogador::Jogador* jogador = dynamic_cast<Personagem::Jogador::Jogador*>(personagem);
                                    jogador->addPontuacao(inimigo->getPontos());
                                    jogador->addExperiencia(inimigo->getExperiencia());
                                }
                            }
                    }
                } else if(ID == IDs::IDs::projetil_inimigo){
                    if(outraEntidade->getID() == IDs::IDs::jogador){
                        std::cout << "projetil colidiu com jogador" << std::endl;
                    }
                }
            }

            const std::string Arma::salvar(){
                std::string linha = salvarEntidade();
                linha += std::to_string(dano);
                return linha;
            }

            void Arma::atualizar(){

            }

            void Arma::desenhar(){
                
            }

        }

    }

}