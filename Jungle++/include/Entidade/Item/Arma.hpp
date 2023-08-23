#pragma once

#include "../Personagem/Personagem.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Item {

            class Arma : public Entidade {
                protected:
                    float dano;
                    Personagem::Personagem* personagem;

                    const std::string salvarArma();
                public:
                    Arma(const IDs::IDs ID, Personagem::Personagem* personagem = nullptr);
                    Arma(const IDs::IDs ID, const std::vector<std::string> atributos);
                    virtual ~Arma();
                    void setPersonagem(Personagem::Personagem* personagem);
                    void setDano(const float dano);
                    const float getDano() const;
                    void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
                    virtual void desenhar();
                    virtual void atualizar();
                    const std::string salvar();
            };

        }

    }

}