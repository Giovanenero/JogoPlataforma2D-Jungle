#pragma once

#include "../Personagem.hpp"
#include "../Jogador/Jogador.hpp"
#include  "../../Item/Arma.hpp"

// usado p/ gerar números aleatórios
#include <time.h>

// utuliza a função fabs
#include <cmath>

#define RAIO_PERSEGUIR_X 200.0f
#define RAIO_PERSEGUIR_Y 200.0f
#define VELOCIDADE_INIMIGO 60.0f
#define TEMPO_MOVER_ALEATORIO 1.0f

namespace Jungle {

    namespace Entidade {

        namespace Personagem {

            namespace Inimigo {

                class Inimigo : public Personagem {
                protected:
                    Jogador::Jogador* jogador;
                    short moveAleatorio;
                    float tempoMover;
                    const float tempoAnimacaoAtacar;
                    float tempoAtacar;
                    const float experiencia;

                    virtual void moveInimigo();
                    void atualizaMovimentoAleatorio();
                    virtual void inicializarAnimacao() = 0;
                    void inicializarBarraVida();
                    virtual void atualizarTempoAtacar();
                    virtual void atualizarAnimacao();
                    virtual void inicializarNivel() = 0;
                    const std::string salvarInimigo();
                public:
                    Inimigo(const sf::Vector2f pos, const sf::Vector2f tam, Jogador::Jogador* jogador, const IDs::IDs ID, const float tempoMorrer, const float tempoAtacar, const float experiencia);
                    ~Inimigo();
                    virtual void tomarDano(const float dano);
                    void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
                    virtual const std::string salvar() = 0;
                    const float getExperiencia() const;
                    void atualizar();
                };

            }

        }

    }

}