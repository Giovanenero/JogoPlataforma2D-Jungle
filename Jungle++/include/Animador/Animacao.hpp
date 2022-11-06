#pragma once

#include "..\Gerenciador\GerenciadorGrafico.hpp"
#include <SFML\Graphics.hpp>
#include <map>

namespace Jungle {

    namespace Animador {

        class Animacao {
        private:
            Gerenciador::GerenciadorGrafico* pGrafico;
            sf::RectangleShape* corpo;
            std::map<std::string, sf::Texture*> mapTextura;
        public:
            Animacao(sf::RectangleShape* corpo);
            ~Animacao();            
            void atualizar();
        };

    }

}