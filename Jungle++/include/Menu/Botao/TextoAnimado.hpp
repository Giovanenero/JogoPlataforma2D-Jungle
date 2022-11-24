#pragma once

#include "Texto.hpp"

namespace Jungle {

    namespace Menu {

        namespace Botao {

            class TextoAnimado: public Texto {
            private:
                int transparente;
                bool clareando;
            public:
                TextoAnimado(sf::Font fonte, const std::string texto);
                ~TextoAnimado();
                void mudarClareando();
                const bool getClareando() const;
                const int  getTransparente() const;
                void setTransparente(int transparente);
                void resetar();
                void atualizar();
            };

        }

    }

}