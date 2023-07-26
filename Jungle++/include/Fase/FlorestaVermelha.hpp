#pragma once

#include "Fase.hpp"

namespace Jungle {

    namespace Fase {

        class FlorestaVermelha : public Fase {
        private:
            void recuperarJogada(const std::string arquivoEntidades, const std::vector<std::string> vectorInfoFase);
        public:
            FlorestaVermelha();
            ~FlorestaVermelha();
            void criarFundo();
            void criarMapa(const int mapa);
        };

    }

}