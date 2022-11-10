#pragma once

#include <SFML/Graphics.hpp>

namespace Jungle {

    namespace Parallax {

        class Camada {
        private:
            const sf::Vector2f tamJanela;
            sf::IntRect dimensao;
            const float vel;

            sf::Texture textura;
            sf::RectangleShape fundo;
            sf::RectangleShape fundoAuxiliar;
        public:
            Camada(const sf::Vector2f tamJanela, sf::Texture textura, const float vel);
            ~Camada();
            void atualizar(sf::Vector2f ds, const sf::Vector2f posCameraAtual);
            const sf::RectangleShape getFundo();
            const sf::RectangleShape getFundoAux();
        };

    }

}