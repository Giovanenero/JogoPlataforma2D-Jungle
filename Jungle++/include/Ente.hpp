#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>

#include "IDs.hpp"
#include "Gerenciador\GerenciadorGrafico.hpp"

namespace Jungle {

    class Ente {
    protected:
        Gerenciador::GerenciadorGrafico* pGrafico;
        const IDs::IDs ID;
    public:
        Ente(const IDs::IDs ID);
        ~Ente();
        const IDs::IDs getID() const;
    };

}