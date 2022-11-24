#pragma once 

#include "..\Ente.hpp"
#include "Botao\Botao.hpp"
#include <list>

#include "..\Parallax\Fundo.hpp"

namespace Jungle {

    namespace Menu {

        class Menu: public Ente {
        protected:
            Parallax::Fundo fundo;
            std::list<Botao::Botao*> listaBotao;
            std::list<Botao::Botao*>::iterator it;
            const sf::Vector2f tamBotao;
            const sf::Vector2f tamJanela;
            sf::Vector2f posFundo;
        public:
            Menu(const IDs::IDs ID, const sf::Vector2f tamBotao, const IDs::IDs ID_Fundo);
            ~Menu();
            void addBotao(const std::string texto, const sf::Vector2f pos, const IDs::IDs ID);
            void desenhar();
            virtual void executar() = 0;
        };

    }

}