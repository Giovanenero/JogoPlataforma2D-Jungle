#pragma once

#include "Obstaculo.hpp"
#include "../Item/Chave.hpp"
#include "../../Animador/Animacao.hpp"

#define TEMPO_PORTA_ABRINDO 1.4f

namespace Jungle {

    namespace Entidade {

        namespace Obstaculo {

            class Porta : public Obstaculo {
                private:
                    Item::Chave* chave;
                    bool fechada;
                    bool abrindo;
                    float tempoAbrindo;
                    Animador::Animacao animacao;
                    void inicializarAnimacao();
                    void atualizarAnimacao();
                public:
                    Porta(const sf::Vector2f pos, const sf::Vector2f tam, Item::Chave* chave);
                    ~Porta();
                    Item::Chave* getChave();
                    void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
                    void atualizar();
            };

        }

    }

}