#pragma once

#include "Inimigo.hpp"

#define RECONHECIMENTO_ALMA_X 350.0f
#define RECONHECIMENTO_ALMA_Y 120.0f
#define EXPERIENCIA_ALMA 100.0f
#define TAMANHO_ALMA_X 50.0f
#define TAMANHO_ALMA_Y 90.0f
#define TEMPO_ALMA_MORRER 1.5f
#define TEMPO_ALMA_ATACAR 1.0f
#define PONTOS_ALMA 250
#define TEMPO_ALMA_INVISIVEL 2.0f
#define FORCA_ALMA 25.0f
#define DEFESA_ALMA 20.0f
#define VITALIDADE_ALMA 10.0f

namespace Jungle {

    namespace Entidade {

        namespace Personagem {

            namespace Inimigo {

                class Alma : public Inimigo {
                    private:
                        bool invisivel;
                        float tempoInvisivel;

                        void moveInimigo();
                        void inicializarAnimacao();
                        void atualizarAnimacao();
                        void atualizarTempoAtacar();
                        void inicializarNivel();
                    public:
                        Alma(const sf::Vector2f pos, const int nivel, Jogador::Jogador* pJogador, Item::Arma* arma = nullptr);
                        Alma(const std::vector<std::string> atributos, Jogador::Jogador* pJogador);
                        ~Alma();
                        void tomarDano(const float dano);
                        const std::string salvar();
                };

            }

        }

    }

}