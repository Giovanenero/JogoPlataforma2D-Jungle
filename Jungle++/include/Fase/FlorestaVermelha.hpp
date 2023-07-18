#pragma once

#include "Fase.hpp"

namespace Jungle {

    namespace Fase {

        class FlorestaVermelha : public Fase {
        public:
            FlorestaVermelha();
            ~FlorestaVermelha();
            void recuperarJogada(const std::string caminhoArquivo);
            void criarFundo();
            void criarMapa();
        };

    }

}