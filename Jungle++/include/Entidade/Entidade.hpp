#pragma once

#include "..\Ente.hpp"

namespace Jungle {

    namespace Entidade {

        class Entidade : public Ente {
        protected:
            sf::RectangleShape corpo;
            sf::Vector2f pos;
            sf::Vector2f tam;

            bool podeRemover;
        public:
            Entidade(const sf::Vector2f tam, const IDs::IDs ID, const sf::Vector2f pos = sf::Vector2f(0.0f, 0.0f));
            virtual ~Entidade();
            const sf::RectangleShape getCorpo();
            void setPos(const sf::Vector2f pos);
            sf::Vector2f getPos();
            void setTam(const sf::Vector2f tam);
            const sf::Vector2f getTam();
            virtual void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f)) = 0;
            virtual void atualizar() = 0;
            void desenhar();
            const bool getRemover() const;
        };

    }

}