#pragma once

#include <SFML/Graphics.hpp>

namespace Jungle {

    namespace Parallax {

        class Camada {
        private:
            sf::Sprite fundo;
            sf::Sprite fundoAuxiliar;
        public:
            Camada(const sf::Vector2f tamJanela, sf::Texture textura);
            ~Camada();
            void atualizar(const sf::Vector2f ds);
        };

    }

}