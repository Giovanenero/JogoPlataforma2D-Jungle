#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

namespace Jungle {

    namespace Gerenciador {

        class Camera {
            private:
                sf::View camera;
                sf::IntRect limiteCamera;
                sf::IntRect limiteObjeto;
                sf::Vector2f tamJanela;
            public:
                Camera(const sf::Vector2f tamJanela);
                ~Camera();
                void inicializarLimite(const sf::Vector2f pos, const sf::Vector2f tam);
                void setLimiteCamera(const sf::IntRect limiteCamera);
                sf::View getCamera();
                void resetar(const sf::Vector2f posCenter);
                void atualizar(const sf::Vector2f pos);
                void atualizar(const sf::Vector2f pos, sf::Vector2f tam);
        };

    }

}