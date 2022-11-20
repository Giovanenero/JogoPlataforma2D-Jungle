#pragma once 

#include <SFML\Graphics.hpp>

namespace Jungle {

    namespace Menu {

        namespace Botao {

            class Texto {
            private:
                sf::Text texto;
                sf::Font fonte;

                void inicializa();
            public:
                Texto(sf::Font fonte, const std::string texto = "");
                ~Texto();
                void setString(const std::string texto);
                const std::string getString();
                sf::Text getTexto();
            };

        }

    }

}