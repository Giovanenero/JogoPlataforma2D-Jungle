#pragma once 

#include <SFML\Graphics.hpp>

namespace Jungle {

    namespace Menu {

        namespace Botao {

            class Texto {
            private:
                sf::Text texto;
                sf::Font fonte;
                std::string info;
                sf::Vector2f tam;
                unsigned int tamTexto;

                int transparente;
                sf::Color corTexto;
                sf::Color corBorda;
                bool clareando;

                void inicializa();
            public:
                Texto(sf::Font fonte, const std::string texto = "");
                ~Texto();
                void setString(const std::string texto);
                const std::string getString();
                sf::Text getTexto();
                void setPos(const sf::Vector2f pos);
                sf::Vector2f getTam();
                void mudarClareando();
                const bool getClareando() const;
                const int  getTransparente() const;
                void setTransparente(int transparente);
            };

        }

    }

}