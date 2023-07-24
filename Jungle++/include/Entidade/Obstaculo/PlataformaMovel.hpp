#pragma once

#include "Plataforma.hpp"

#define VELOCIDADE_PLATAFORMA 100.0f

namespace Jungle {

    namespace Entidade {

        namespace Obstaculo {

            class PlataformaMovel : public Plataforma {
                private:
                    const bool horizontal;
                    const float posFinal;
                    const float posInicial;
                    bool paraEsquerda;
                    bool paraBaixo;
                    const sf::Vector2f velocidade;
                    sf::Vector2f ds;
                    float tempo;

                    void atualizarPosicao();
                public:
                    PlataformaMovel(const IDs::IDs ID, const sf::Vector2f pos, const float distancia, const sf::Vector2f tam, const bool ehFlutuante, const bool horizontal);
                    ~PlataformaMovel();
                    void inicializarAnimacao();
                    void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
                    void atualizar();
            };

        }

    }

}