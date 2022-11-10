#pragma once

#include "..\Ente.hpp"
#include "..\IDs.hpp"

namespace Jungle {

    namespace Parallax {

        class Fundo : public Ente {
        private:
            sf::Vector2f* posJogador;
            sf::Vector2f posAnterior;
        public:
            Fundo(sf::Vector2f* posJogador);
            ~Fundo();
            void desenhar();
            void executar();
        };

    }

}