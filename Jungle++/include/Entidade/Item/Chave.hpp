#pragma once

#include "../Entidade.hpp"
#include "../../Animador/Animacao.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Obstaculo {
            class Porta;
        }

        namespace Item {

            class Chave : public Entidade {
                private:
                    Obstaculo::Porta* porta;
                    Animador::Animacao animacao;
                public:
                    Chave(const sf::Vector2f pos, const sf::Vector2f tam);
                    ~Chave();
                    void setPorta(Obstaculo::Porta* porta);
                    Obstaculo::Porta* getPorta();
                    void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
                    const std::string salvar();
                    void atualizar();
            };

        }

    }

}