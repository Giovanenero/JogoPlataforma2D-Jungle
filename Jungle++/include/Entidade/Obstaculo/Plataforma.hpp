#pragma once

#include "Obstaculo.hpp"
#include "..\Personagem\Personagem.hpp"

#define CAMINHO_TEXTURA_PLATAFORMA "Jungle++/img/Obstaculo/plataforma.png"
#define ESCALA_PLATAFORMA_X 1
#define ESCALA_PLATAFORMA_Y 1

namespace Jungle {

    namespace Entidade {

        namespace Obstaculo {

            class Plataforma : public Obstaculo {
            public:
                Plataforma(sf::Vector2f pos, sf::Vector2f tam);
                ~Plataforma();
                void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
                void colisaoObstaculo(sf::Vector2f ds, Personagem::Personagem* pPersonagem);
            };

        }

    }

}