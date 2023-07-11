#pragma once

#include "../Personagem/Personagem.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Item {

            class Arma : public Entidade {
                protected:
                    float dano;
                    Personagem::Personagem* personagem;
                public:
                    Arma(const IDs::IDs ID, Personagem::Personagem* personagem = nullptr);
                    ~Arma();
                    void setPersonagem(Personagem::Personagem* personagem);
                    void setDano(const float dano);
                    const float getDano() const;
                    void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
                    void desenhar();
                    virtual void atualizar();
            };

        }

    }

}