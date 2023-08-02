#pragma once

#include "../Ente.hpp"
#include "../IDs.hpp"

#include "Camada.hpp"

namespace Jungle {

    namespace Parallax {

        class Fundo : public Ente {
        private:
            sf::Vector2f posAnteriorCamera;
            std::vector<Camada*> camadas;
        public:
            Fundo(const IDs::IDs ID);
            ~Fundo();
            void desenhar();
            void addCamada(const char* caminhoTextura, const float vel);
            void atualizarPosicao();
            void executar();
        };

    }

}