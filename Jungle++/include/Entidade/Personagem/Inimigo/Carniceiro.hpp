#pragma once

#include "Inimigo.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Personagem {

            namespace Inimigo {

                class Carniceiro: public Inimigo {
                    private:
                        //bool noChao;
                        void inicializarAnimacao();
                        void inicializarNivel();
                    public:
                        Carniceiro(const sf::Vector2f pos, const int nivel, Jogador::Jogador* pJogador);
                        Carniceiro(const std::vector<std::string> atributos, Jogador::Jogador* pJogador);
                        ~Carniceiro();
                        const std::string salvar();
                };

            }

        }

    }

}