#pragma once 

#include "..\Ente.hpp"
#include "Botao\Botao.hpp"
#include <list>

namespace Jungle {

    namespace Menu {

        class Menu: public Ente {
        protected:
            std::list<Botao::Botao*> listaBotao;
            std::list<Botao::Botao*>::iterator it;
            const sf::Vector2f tamBotao;
        public:
            Menu(const IDs::IDs ID, const sf::Vector2f tamBotao);
            ~Menu();
            void addBotao(const std::string info, const sf::Vector2f pos, const IDs::IDs ID);
            void desenhar();
            virtual void executar() = 0;
        };

    }

}