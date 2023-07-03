#pragma once

#include "Menu.hpp"
#include "..\Parallax\Fundo.hpp"

#define CAMINHO_TEXTURA_MENU_PRINCIPAL "Jungle++/img/Menu/menuPrincipal.png"

namespace Jungle {

    namespace Menu {

        class MenuPrincipal: public Menu {
        protected:
            Parallax::Fundo fundo;
            bool sair;

            void criarFundo();
        public:
            MenuPrincipal(const IDs::IDs ID = IDs::IDs::menu_principal, std::string nome = "JUNGLE++", const unsigned int tamFonte = 180);
            virtual ~MenuPrincipal();
            virtual void criarBotoes();
            void setSair(const bool sair = true);
            const bool getSair() const;
            virtual void executar();
        };

    } 

}