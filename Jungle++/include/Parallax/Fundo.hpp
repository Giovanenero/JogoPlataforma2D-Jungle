#pragma once

#include "..\Ente.hpp"
#include "..\IDs.hpp"

namespace Jungle {

    namespace Parallax {

        class Fundo : public Ente {
        private:
            sf::Vector2f posAnteriorCamera;
        public:
            Fundo();
            ~Fundo();
            void desenhar();
            void executar();
        };

    }

}