#pragma once

#include "Inimigo.hpp"

#define RECONHECIMENTO_ALMA_X 350.0f
#define RECONHECIMENTO_ALMA_Y 120.0f
#define TAMANHO_ALMA_X 50.0f
#define TAMANHO_ALMA_Y 90.0f
#define TEMPO_ALMA_MORRER 2.0f
#define TEMPO_ALMA_ATACAR 1.5f
#define PONTOS_ALMA 250

namespace Jungle {

    namespace Entidade {

        namespace Personagem {

            namespace Inimigo {

                class Alma : public Inimigo {
                    private:

                        void moveInimigo();
                        void inicializarAnimacao();
                        void atualizarAnimacao();
                        void atualizarTempoAtacar();
                    public:
                        Alma(const sf::Vector2f pos, Jogador::Jogador* pJogador);
                        ~Alma();

                };

            }

        }

    }

}