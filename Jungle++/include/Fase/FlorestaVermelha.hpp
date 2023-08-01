#pragma once

#include "Fase.hpp"

namespace Jungle {

    namespace Fase {

        class FlorestaVermelha : public Fase {
        private:
            void recuperarJogada(const std::vector<std::string> vectorEntidades, const std::vector<std::string> vectorInfoFase);
        public:
            FlorestaVermelha();
            ~FlorestaVermelha();
            void criarFundo();
            void criarMapa(const IDs::IDs ID_Mapa);
        };

    }

}