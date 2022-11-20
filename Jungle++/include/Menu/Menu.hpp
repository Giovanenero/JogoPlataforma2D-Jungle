#pragma once 

#include "..\Ente.hpp"
#include "Botao\Botao.hpp"

namespace Jungle {

    namespace Menu {

        class Menu: public Ente {
        private:
            sf::RectangleShape fundo;
        public:
            Menu(const IDs::IDs ID);
            ~Menu();
        };

    }

}