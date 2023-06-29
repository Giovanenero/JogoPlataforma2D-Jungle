#pragma once

#include "Fase.hpp"
#include "..\Entidade\Item\Espada.hpp"

namespace Jungle {

    namespace Fase {

        class FlorestaBranca : public Fase  {
        public:
            FlorestaBranca();
            ~FlorestaBranca();
            void criarFundo();
            void criarMapa();
        };

    }

}