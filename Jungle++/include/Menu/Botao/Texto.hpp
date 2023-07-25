#pragma once 

#include <SFML/Graphics.hpp>

namespace Jungle {

    namespace Menu {

        namespace Botao {

            class Texto {
            private:
                const sf::Font fonte;
                std::string info;
            protected:
                sf::Text texto;
                sf::Vector2f tam;
                sf::Vector2f pos;
                unsigned int tamFonte;
                sf::Color corTexto;
                sf::Color corBorda;

                void inicializa();
            public:
                Texto(const sf::Font fonte, const std::string info, const unsigned int tamFonte = 50);
                virtual ~Texto();
                const sf::Text getTexto() const;
                void setPos(const sf::Vector2f pos);
                const sf::Vector2f getPos() const;
                const sf::Vector2f getTam() const;
                void setCorTexto(const sf::Color corTexto);
                void setTamanhoBorda(const float tamBorda);
                void setEspacamento(const float tamEspaco);
                void setString(std::string nome);
                const std::string getString() const;
                void setTamFonte(const unsigned int tamFonte);
            };

        }

    }

}