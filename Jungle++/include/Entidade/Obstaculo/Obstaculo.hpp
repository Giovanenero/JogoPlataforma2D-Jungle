#pragma once

#include "..\Entidade.hpp"
#include "..\Personagem\Jogador\Jogador.hpp"
#include "..\Personagem\Inimigo\Inimigo.hpp"

#include "..\..\Animador\Animacao.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Obstaculo {

            class Obstaculo : public Entidade {
            protected:
                sf::Texture textura;
            public:
                Obstaculo(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID);
                ~Obstaculo();
                virtual void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f)) = 0;
                void atualizar();
            };

        }

    }

}