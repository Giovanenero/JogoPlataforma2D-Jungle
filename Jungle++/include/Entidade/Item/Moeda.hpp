#pragma once

#include "../Entidade.hpp"
#include "../../Animador/Animacao.hpp"

#define TAMANHO_MOEDA 50.0f
#define CAMINHO_MOEDA_AMARELA "Jungle++/img/Item/moedaAmarela.png"
#define CAMINHO_MOEDA_CINZA "Jungle++/img/Item/moedaCinza.png"
#define PONTOS_MOEDA_AMARELA 500
#define PONTOS_MOEDA_CINZA 250

namespace Jungle {

    namespace Entidade {

        namespace Item {

            class Moeda : public Entidade {
                private:
                    const unsigned int pontos;
                    Animador::Animacao animacao;
                    const std::string tipo;

                    void inicializarAnimacao();
                public:
                    Moeda(const sf::Vector2f pos, const IDs::IDs ID);
                    Moeda(const std::vector<std::string> atributos, const IDs::IDs ID);
                    ~Moeda();
                    void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
                    void atualizar();
                    const unsigned int getPontos() const;
                    const std::string salvar();
            };

        }

    }

}