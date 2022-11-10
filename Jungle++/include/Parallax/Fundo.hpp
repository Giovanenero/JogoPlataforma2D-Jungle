#pragma once

#include "..\Ente.hpp"
#include "..\IDs.hpp"

#include "Camada.hpp"

namespace Jungle {

    namespace Parallax {

        class Fundo : public Ente {
        private:
            sf::Vector2f posAnteriorCamera;
            std::vector<Camada*> camadas;
        public:
            Fundo();
            ~Fundo();
            void desenhar();
            void executar();
        };

    }

}