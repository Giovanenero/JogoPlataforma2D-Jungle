#include "../../../../include/Entidade/Personagem/Inimigo/Carniceiro.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Personagem {

            namespace Inimigo {

                Carniceiro::Carniceiro(const sf::Vector2f pos, const int nivel, Jogador::Jogador* pJogador):
                    Inimigo(pos, sf::Vector2f(100.0f, 150.0f), pJogador, IDs::IDs::carniceiro, 1.0f, 1.0f, 2000.0f)
                {
                    this->nivel.setNivel(nivel);
                    this->pontos = 2000;
                    inicializarAnimacao();
                    inicializarNivel();
                }

                Carniceiro::~Carniceiro(){

                }

                void Carniceiro::inicializarAnimacao(){
                    sf::Vector2f origin(sf::Vector2f(50.0f, 7.5f));
                    sf::Vector2f escala(sf::Vector2f(2.0f, 1.5f));
                    animacao.addAnimacao("Jungle++/img/Personagem/Inimigo/Carniceiro/anda.png", "ANDA", 8, 0.1f, escala, origin);
                    animacao.addAnimacao("Jungle++/img/Personagem/Inimigo/Carniceiro/parado.png", "PARADO", 8, 0.1f, escala, origin);
                    animacao.addAnimacao("Jungle++/img/Personagem/Inimigo/Carniceiro/ataca.png", "ATACA", 5, 0.1f, escala, origin);
                    animacao.addAnimacao("Jungle++/img/Personagem/Inimigo/Carniceiro/morre.png", "MORRE", 6, 0.1f, escala, origin);
                    animacao.addAnimacao("Jungle++/img/Personagem/Inimigo/Carniceiro/tomaDano.png", "TOMADANO", 4, 0.2f, escala, origin);
                }

                void Carniceiro::inicializarNivel(){

                }

                const std::string Carniceiro::salvar(){
                    std::string linha = salvarInimigo();
                    return linha;
                }

            }

        }

    }

}