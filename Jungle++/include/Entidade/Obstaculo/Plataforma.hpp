#pragma once

#include "Obstaculo.hpp"
#include "../Personagem/Personagem.hpp"

#define CAMINHO_TEXTURA_PLATAFORMA "Jungle++/img/Obstaculo/plataforma.png"
#define ESCALA_PLATAFORMA_X 1
#define ESCALA_PLATAFORMA_Y 1
#define TAMANHO_PLATAFORMA_X 300.0f
#define TAMANHO_PLATAFORMA_Y 50.0f

namespace Jungle {

    namespace Entidade {

        namespace Obstaculo {

            class Plataforma : public Obstaculo {
            public:
                Plataforma(sf::Vector2f pos);
                Plataforma(const std::vector<std::string> atributos);
                ~Plataforma();
                void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
            };

        }

    }

}