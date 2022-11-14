#pragma once

#include "Fase.hpp"

namespace Jungle {

    namespace Fase {

        class FlorestaVermelha : public Fase {
        private:
        public:
            FlorestaVermelha();
            ~FlorestaVermelha();
            void executar();
            void criarFundo();
            void criarEntidades();
        };

    }

}