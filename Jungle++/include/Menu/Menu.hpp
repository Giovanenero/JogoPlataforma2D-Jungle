#pragma once 

#include "..\Ente.hpp"
#include "Botao\Botao.hpp"
#include <list>

namespace Jungle {

    namespace Menu {

        class Menu: public Ente {
        protected:
            sf::Texture textura;
            sf::RectangleShape fundo;
            std::list<Botao::Botao*> listaBotao;
            std::list<Botao::Botao*>::iterator it;
        public:
            Menu(const IDs::IDs ID);
            ~Menu();
            void addBotao(const std::string texto);
            void desenhar();
            virtual void executar() = 0;
        };

    }

}