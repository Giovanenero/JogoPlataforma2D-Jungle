#pragma once

#include <SFML/Graphics.hpp>

namespace Jungle {

    namespace Parallax {

        class Camada {
        private:
            sf::Sprite fundo;
            sf::Sprite fundoAuxiliar;

            sf::IntRect tamFundo;
            sf::IntRect tamFundoAuxiliar;
        public:
            Camada();
            ~Camada();
        };

    }

}