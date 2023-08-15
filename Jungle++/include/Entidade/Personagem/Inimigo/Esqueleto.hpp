#pragma once

#include "Inimigo.hpp"

#define TAMANHO_ESQUELO_X 50.0f
#define TAMANHO_ESQUELO_Y 90.0f
#define TEMPO_ESQUELETO_MORRER 1.5f
#define PONTOS_ESQUELETO 200
#define EXPERIENCIA_ESQUELETO 50.0f

namespace Jungle {

    namespace Entidade {

        namespace Personagem {

            namespace Inimigo {

                class Esqueleto : public Inimigo {
                private:
                    bool raiva;
                    float tempoRaiva;
                    sf::Color corPadrao;

                    void inicializarAnimacao();
                    void inicializarNivel();
                    void atualizarRaiva();
                    void atualizarAnimacao();
                public:
                    Esqueleto(const sf::Vector2f pos, const int nivel, Jogador::Jogador* jogador);
                    Esqueleto(const std::vector<std::string> atributos, Jogador::Jogador* jogador);
                    ~Esqueleto();
                    void tomarDano(const float dano);
                    const std::string salvar();
                    void atualizarTempoAtacar();
                    void moveInimigo();
                };

            }

        }

    }
    
}