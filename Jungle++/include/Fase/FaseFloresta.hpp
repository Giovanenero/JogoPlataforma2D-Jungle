#pragma once

#include "Fase.hpp"

namespace Jungle {

    namespace Fase {

        class FaseFloresta : public Fase {
        private:
        public:
            FaseFloresta();
            ~FaseFloresta();
            void criaFundo();
            void criaEntidades();
            void executar();
        };

    }

}