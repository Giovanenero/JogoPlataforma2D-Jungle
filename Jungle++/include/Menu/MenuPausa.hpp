#pragma once

#include "Menu.hpp"
#include "..\Fase\Fase.hpp"

#define TAMANHO_BOTAO_X 350.0f
#define TAMANHO_BOTAO_Y 50.0f

namespace Jungle {

    namespace Menu {

        class MenuPausa : public Menu {
        private:
            Fase::Fase* fase;
        public:
            MenuPausa(Fase::Fase* fase = nullptr);
            ~MenuPausa();
            void setFase(Fase::Fase* fase);
            void executar();
        };

    }

}