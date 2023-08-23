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