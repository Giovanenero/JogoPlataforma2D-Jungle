#pragma once

#include "Fase.hpp"

namespace Jungle {

    namespace Fase {

        class FlorestaBranca : public Fase {
        private:
        public:
            FlorestaBranca();
            ~FlorestaBranca();
            void criarFundo();
            void criarEntidades();
            void executar();
        };

    }

}