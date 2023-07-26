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
                    bool coletou;
                public:
                    Chave(const sf::Vector2f pos, const sf::Vector2f tam);
                    Chave(const std::vector<std::string> atributos);
                    ~Chave();
                    void setPorta(Obstaculo::Porta* porta);
                    Obstaculo::Porta* getPorta();
                    void setColetou(const bool coletou);
                    const bool getColetou() const;
                    void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
                    const std::string salvar();
                    void atualizar();
            };

        }

    }

}