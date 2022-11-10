#pragma once

#include <SFML/Graphics.hpp>

namespace Jungle {

    namespace Parallax {

        class Camada {
        private:
            sf::Sprite fundo;
            sf::Sprite fundoAuxiliar;
        public:
            Camada();
            ~Camada();
        };

    }

}