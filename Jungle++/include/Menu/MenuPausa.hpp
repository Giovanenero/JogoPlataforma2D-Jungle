#pragma once

#include "Menu.hpp"
#include "../Fase/Fase.hpp"

namespace Jungle {

    namespace Menu {

        class MenuPausa : public Menu {
        private:
            sf::RectangleShape fundoPainel;
        
        protected:
            Fase::Fase* fase;
            sf::RectangleShape fundoEscuro;
            float posBotaoY;
            
            void atualizarBotoes();
        public:
            MenuPausa(Fase::Fase* fase = nullptr);
            MenuPausa(const IDs::IDs ID, const std::string nome, Fase::Fase* fase = nullptr);
            ~MenuPausa();
            virtual void criarBotoes();
            void setFase(Fase::Fase* fase);
            Fase::Fase* getFase();
            virtual void executar();
        };

    }

}