#pragma once

#include "Fase.hpp"
#include "../Entidade/Item/Arma.hpp"
#include "../Entidade/Item/Vida.hpp"
#include "../Entidade/Personagem/Inimigo/Alma.hpp"

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