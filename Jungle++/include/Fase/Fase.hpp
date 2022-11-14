#pragma once

#include "..\Ente.hpp"
#include "..\Parallax\Fundo.hpp"

namespace Jungle {

    namespace Fase {

        class Fase : public Ente {
        protected:
            Parallax::Fundo fundo;
        public:
            Fase();
            ~Fase();
            virtual void criaFundo() = 0;
            virtual void criaEntidades() = 0;
        };

    }

}