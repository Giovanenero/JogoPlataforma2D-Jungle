#pragma once

#include "Fase.hpp"

namespace Jungle {

    namespace Fase {

        class FlorestaVermelha : public Fase {
        private:
            void recuperarJogada(const std::string caminhoArquivo);
        public:
            FlorestaVermelha();
            ~FlorestaVermelha();
            void criarFundo();
            void criarMapa();
        };

    }

}