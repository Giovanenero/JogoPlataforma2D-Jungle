#pragma once

#include "Menu.hpp"

namespace Jungle {

    namespace Menu {

         class Card {
            private:
                sf::Texture* textura;
                sf::RectangleShape* corpo;
                const std::string caminhoArquivo;
                const std::string caminhoImage;
                sf::Color cor;
                bool selecionado;
            
                static Gerenciador::GerenciadorGrafico* pGrafico;
            public:
                Card(const sf::Vector2f pos, const std::string caminhoArquivo, const std::string caminhoImage);
                ~Card();
                const std::string getCaminhoArquivo() const;
                const std::string getCaminhoImage() const;
                void setColor(sf::Color cor);
                void setSelecionado(const bool selecionado);
                const bool getSelecionado() const;
                void desenhar();
        };

    }

}