#pragma once

#include "Fase.hpp"

namespace Jungle {

    namespace Fase {

        class FaseFloresta : public Fase {
        private:
        public:
            FaseFloresta();
            ~FaseFloresta();
            void criarFundo();
            void criarEntidades();
            void executar();
        };

    }

}