#pragma once

#include "../Entidade.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Item {

            class Espada : public Entidade {
                private:
                    float dano;
                    Entidade* entidade;
                public:
                    Espada(const IDs::IDs ID, Entidade* entidade = nullptr);
                    ~Espada();
                    void setEntidade(Entidade* entidade);
                    void setDano(const float dano);
                    const float getDano() const;
                    void atualizar();
                    void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
            };

        }

    }

}