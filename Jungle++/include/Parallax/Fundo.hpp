#pragma once

#include "..\Ente.hpp"
#include "..\IDs.hpp"

namespace Jungle {

    namespace Parallax {

        class Fundo : public Ente {
        private:
            sf::Vector2f* posJogador;
        public:
            Fundo(sf::Vector2f* posJogador);
            ~Fundo();
            void desenhar();
            void executar();
        };

    }

}