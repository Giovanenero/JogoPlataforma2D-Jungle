#pragma once

#include <SFML/Graphics.hpp>

namespace Jungle {

    namespace Parallax {

        class Camada {
        private:
            sf::Sprite ladoDireito;
            sf::Sprite ladoEsquerdo;
        public:
            Camada();
            ~Camada();
        };

    }

}