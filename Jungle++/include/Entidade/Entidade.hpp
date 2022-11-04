#pragma once

#include <SFML\Graphics.hpp>
#include "..\Gerenciador\GerenciadorGrafico.hpp"
#include <iostream>

#include "..\IDs.hpp"

namespace Jungle {

    namespace Entidade {

        class Entidade {
        protected:
            sf::RectangleShape corpo;
            sf::Vector2f pos;
            sf::Vector2f tam;
            const IDs::IDs ID;
        public:
            Entidade(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID);
            ~Entidade();
            const sf::RectangleShape getCorpo();
            void setPos(sf::Vector2f pos);
            const sf::Vector2f getPos();
            const sf::Vector2f getTam();
            const IDs::IDs getID() const;
            virtual void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f)) = 0;
            virtual void atualizar() = 0;
        };

    }

}