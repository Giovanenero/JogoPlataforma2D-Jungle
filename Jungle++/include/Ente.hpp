#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "IDs.hpp"
#include "Gerenciador/GerenciadorGrafico.hpp"

namespace Jungle {

    class Ente {
        protected:
            static Gerenciador::GerenciadorGrafico* pGrafico;
            const IDs::IDs ID;

            const std::string salvarEnte();
        public:
            Ente(const IDs::IDs ID);
            ~Ente();
            const IDs::IDs getID() const;
            virtual void desenhar() = 0;
    };

}