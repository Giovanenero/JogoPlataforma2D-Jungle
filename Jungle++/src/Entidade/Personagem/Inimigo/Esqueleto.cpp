#include "../../../../include/Entidade/Personagem/Inimigo/Esqueleto.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Personagem {

            namespace Inimigo {

                Esqueleto::Esqueleto(const sf::Vector2f pos, Jogador::Jogador* jogador):
                    Inimigo(
                        pos, 
                        sf::Vector2f(TAMANHO_ESQUELO_X, TAMANHO_ESQUELO_Y), 
                        jogador, 
                        IDs::IDs::esqueleto, 
                        TEMPO_ESQUELETO_MORRER
                    )
                {
                    this->pontos = PONTOS_ESQUELETO;
                    inicializarAnimacao();
                }

                Esqueleto::~Esqueleto(){

                }

                const std::string Esqueleto::salvar(){
                    std::string linha = "";
                    //salvando atributos da entidade
                    linha += std::to_string(static_cast<int>(ID)) + ' ';
                    linha += std::to_string(pos.x) + ' ';
                    linha += std::to_string(pos.y) + ' ';
                    linha += std::to_string(tam.x) + ' ';
                    linha += std::to_string(tam.y) + ' ';
                    //salvando atributos do personagem
                    linha += std::to_string(velFinal.x) + ' ';
                    linha += std::to_string(velFinal.y) + ' ';
                    linha += std::to_string(andando) + ' ';
                    linha += std::to_string(paraEsquerda) + ' ';
                    linha += std::to_string(levandoDano) + ' ';
                    linha += std::to_string(atacando) + ' ';
                    linha += std::to_string(morrendo) + ' ';
                    linha += std::to_string(vida) + ' ';
                    linha += std::to_string(tempoDano) + ' ';
                    linha += std::to_string(tempoMorrer) + ' ';
                    linha += std::to_string(dt) + ' ';
                    //salvando atributos do inimigo
                    linha += std::to_string(moveAleatorio) + ' ';
                    linha += std::to_string(tempoMover) + ' ';
                    linha += std::to_string(tempoAtacar);
                    //salvando atributos do esqueleto
                    //ainda n tem
                    return linha;
                }

                void Esqueleto::inicializarAnimacao(){
                    const sf::Vector2f origin = sf::Vector2f(tam.x / 12.0f, tam.y / 8.5f);
                    animacao.addAnimacao("Jungle++/img/Personagem/Inimigo/Esqueleto/Parado.png", "PARADO", 11, 0.12f, sf::Vector2f(1.0f, 1.10f), origin);
                    animacao.addAnimacao("Jungle++/img/Personagem/Inimigo/Esqueleto/Anda.png", "ANDA", 13, 0.15f, sf::Vector2f(1.0f, 1.10f), origin);
                    animacao.addAnimacao("Jungle++/img/Personagem/Inimigo/Esqueleto/Morre.png", "MORRE", 15, 0.10f, sf::Vector2f(1.5f, 1.10f), origin);
                    animacao.addAnimacao("Jungle++/img/Personagem/Inimigo/Esqueleto/tomaDano.png", "TOMADANO", 8, 0.15f, sf::Vector2f(1.2f, 1.10f), origin);
                    animacao.addAnimacao("Jungle++/img/Personagem/Inimigo/Esqueleto/Ataca.png", "ATACA", 18, 0.15f, sf::Vector2f(1.95f, 1.3f), sf::Vector2f(tam.x / 3.0f, tam.y / 4.0f));
                }

            }

        }

    }

}