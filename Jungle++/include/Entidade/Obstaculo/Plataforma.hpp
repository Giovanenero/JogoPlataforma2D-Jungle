#pragma once

#include "Obstaculo.hpp"
#include "../Personagem/Personagem.hpp"

#define CAMINHO_TEXTURA_PLATAFORMA "Jungle++/img/Obstaculo/plataforma2.png"
#define CAMINHO_TEXTURA_PLATAFORMA_FLUTUANTE "Jungle++/img/Obstaculo/flutuante.png"
#define ESCALA_PLATAFORMA_X 1
#define ESCALA_PLATAFORMA_Y 1
#define TAMANHO_PLATAFORMA_X 350.0f
#define TAMANHO_PLATAFORMA_Y 50.0f
#define TAMANHO_FLUTUANTE_X 80.0f
#define TAMANHO_FLUTUANTE_Y 40.0f

namespace Jungle {

    namespace Entidade {

        namespace Obstaculo {

            class Plataforma : public Obstaculo {
                protected:
                    bool ehFlutuante;
                public:
                    Plataforma(const IDs::IDs ID, const sf::Vector2f pos, const sf::Vector2f tam, const bool ehFlutuante);
                    Plataforma(const std::vector<std::string> atributos);
                    ~Plataforma();
                    virtual void inicializarAnimacao();
                    virtual void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
                    virtual const std::string salvar();
            };

        }

    }

}