#pragma once

#include "..\Ente.hpp"

namespace Jungle {

    namespace Estado {

        class Estado : public Ente {
        public:
            Estado(const IDs::IDs ID);
            ~Estado();
            virtual void executar() = 0;
            virtual void desenhar();
        };

    }

}