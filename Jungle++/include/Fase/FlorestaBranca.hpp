#pragma once

#include "Fase.hpp"

namespace Jungle {

    namespace Fase {

        class FlorestaBranca : private Fase  {
        public:
            FlorestaBranca();
            ~FlorestaBranca();
            void criarFundo();
            void criarMapa();
        };

    }

}