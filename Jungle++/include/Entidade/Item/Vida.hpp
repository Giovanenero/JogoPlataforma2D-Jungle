#pragma once

#include "../../Animador/Animacao.hpp"
#include "../Personagem/Jogador/Jogador.hpp"

#define TAMANHO_VIDA 50.0f
#define CAMINHO_VIDA "Jungle++/img/Item/vida.png"
#define VIDA_MAXIMA 80
#define VIDA_MINIMA 20

namespace Jungle {

    namespace Entidade {

        namespace Item {

            class Vida : public Entidade {
                private:
                    float vida;
                    Animador::Animacao animacao;

                    void inicializarAnimacao();
                    void atualizarAnimacao();
                public:
                    Vida(const sf::Vector2f pos);
                    Vida(const std::vector<std::string> atributos);
                    ~Vida();
                    const float getVida() const;
                    void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
                    const std::string salvar();
                    void atualizar();
            };

        }

    }

}