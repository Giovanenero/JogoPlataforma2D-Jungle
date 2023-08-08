#pragma once

#include "Plataforma.hpp"

#define VELOCIDADE_PLATAFORMA 100.0f

namespace Jungle {

    namespace Entidade {

        namespace Obstaculo {

            class PlataformaMovel : public Plataforma {
                private:
                    bool horizontal;
                    float posFinal;
                    float posInicial;
                    bool paraEsquerda;
                    bool paraBaixo;
                    const sf::Vector2f velocidade;
                    sf::Vector2f ds;

                    void atualizarPosicao();
                public:
                    PlataformaMovel(const sf::Vector2f pos, const float distancia, const sf::Vector2f tam, const bool horizontal);
                    PlataformaMovel(const std::vector<std::string> atributos);
                    ~PlataformaMovel();
                    void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
                    const std::string salvar();
                    void atualizar();
            };

        }

    }

}