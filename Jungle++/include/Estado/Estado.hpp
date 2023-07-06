#pragma once

#include "../Ente.hpp"

namespace Jungle {

    namespace Estado {

        class Estado : public Ente {
        private:
            bool remover;
        public:
            Estado(const IDs::IDs ID);
            virtual ~Estado();
            virtual void executar() = 0;
            virtual void desenhar();
            void setRemover(const bool remover = true);
            const bool getRemover() const;
            virtual void mudarEstadoObservador() = 0;
        };

    }

}