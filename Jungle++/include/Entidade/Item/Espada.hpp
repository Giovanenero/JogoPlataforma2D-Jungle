#pragma once

#include "../Personagem/Personagem.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Item {

            class Espada : public Entidade {
                private:
                    float dano;
                    Personagem::Personagem* personagem;
                public:
                    Espada(const IDs::IDs ID, Personagem::Personagem* personagem = nullptr);
                    ~Espada();
                    void setPersonagem(Personagem::Personagem* personagem);
                    void setDano(const float dano);
                    const float getDano() const;
                    void atualizar();
                    void desenhar();
                    void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
            };

        }

    }

}