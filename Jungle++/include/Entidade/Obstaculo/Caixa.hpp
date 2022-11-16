#pragma once 

#include "Obstaculo.hpp"

//textura
#define CAMINHO_TEXTURA_CAIXA "Jungle++/img/Obstaculo/caixa.png"
#define ESCALA_CAIXA_X 1
#define ESCALA_CAIXA_Y 1
#define TAMANHO_CAIXA_X 50.0f
#define TAMANHO_CAIXA_Y 50.0f

namespace Jungle {

    namespace Entidade {

        namespace Obstaculo {

            class Caixa : public Obstaculo {
            private:
                const float lentidao;
            public:
                Caixa(sf::Vector2f pos);
                ~Caixa();
                void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
                void colisaoObstaculo(sf::Vector2f ds, Personagem::Personagem* pPersonagem);
            };
            
        }

    }

}