#pragma once

#include "Arma.hpp"
#include "../../Animador/Animacao.hpp"

#define TAMANHO_PROJETIL 25.0f

namespace Jungle {

    namespace Entidade {

        namespace Item {

            class Projetil: public Arma {
                private:
                    bool paraEsquerda;
                    sf::Vector2f velocidade;
                    Animador::Animacao animacao;
                    bool colidiu;

                    void atualizarAnimacao();
                    void atualizarPosicao();
                public:
                    Projetil(Personagem::Personagem* personagem = nullptr);
                    ~Projetil();
                    void inicializarAnimacao();
                    void setSentido(const bool paraEsquerda);
                    void setVelocidade(const sf::Vector2f velocidade);
                    void setColidiu(const bool colidiu);
                    const bool getColidiu() const;
                    void desenhar();
                    void atualizar();
            };

        }

    }

}