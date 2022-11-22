#pragma once 

#include "..\..\Ente.hpp"
#include "Texto.hpp"

#define CAMINHO_FONTE "Jungle++/fonte/menu.ttf"

namespace Jungle {

    namespace Menu {

        namespace Botao {

            class Botao : public Ente {
            private:
                sf::RectangleShape caixa;
                Texto caixaTexto;
                bool selecionado;

            public:
                Botao(const std::string texto);
                ~Botao();
                void desenhar();
            };

        }

    }

}