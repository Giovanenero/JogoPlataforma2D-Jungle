#pragma once

namespace Jungle {

    namespace Gerenciador {
        class GerenciadorEvento;
    }

    namespace Observador {

        class Observador {
        private:
            static Gerenciador::GerenciadorEvento* pEvento;
        public:
            Observador();
            ~Observador();
            virtual void teclaPressionada(){}
            virtual void teclaSolta(){}
        };

    }

}