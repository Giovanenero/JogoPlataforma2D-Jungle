#pragma once

#include "../Entidade.hpp"
#include "../Personagem/Jogador/Jogador.hpp"
#include "../Personagem/Inimigo/Inimigo.hpp"

#include "../../Animador/Animacao.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Obstaculo {

            class Obstaculo : public Entidade {
            protected:
                sf::Texture textura;

                virtual void inicializarAnimacao() = 0;
                const std::string salvarObstaculo();
            public:
                Obstaculo(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID);
                ~Obstaculo();
                virtual void colisao(Entidade* outraEntidade, sf::Vector2f ds) = 0;
                virtual void atualizar();
                virtual void colisaoObstaculo(sf::Vector2f ds, Personagem::Personagem* pPersonagem);
                virtual const std::string salvar();
            };

        }

    }

}